#include "schedule.h"
#include "../partB/base_event.h"
#include <iostream>

namespace mtm {

    Schedule::Schedule():schedule_vector(std::vector<BaseEvent*>()){}
    
    Schedule::~Schedule(){
        for(std::vector<BaseEvent*>::iterator iterator = schedule_vector.begin();
                                    iterator!=schedule_vector.end();++iterator){
            delete *iterator;
        }
    }

    bool compareFunc(BaseEvent* event1,BaseEvent* event2){
        return *event1<*event2;
    }

    void Schedule::addEvents(const EventContainer& container){
        for (ContainerIterator container_iterator = container.begin();
                                container_iterator != container.end();++container_iterator){

            for(std::vector<BaseEvent*>::iterator iterator = schedule_vector.begin();
                                                iterator!=schedule_vector.end();++iterator){

                if(*container_iterator==*(*iterator)){
                    throw EventAlreadyExists();
                }
            } 
        }
        for (ContainerIterator container_iterator = container.begin();
                                container_iterator != container.end();++container_iterator){

                schedule_vector.push_back((*container_iterator).clone());
        }
        std::sort(schedule_vector.begin(), schedule_vector.end(), compareFunc);   
    }
    
    void Schedule::registerToEvent(const mtm::DateWrap date,const char* name, const int student){
        mtm::OpenEvent temp(date,name);
        for(std::vector<BaseEvent*>::iterator iterator = schedule_vector.begin();
                                            iterator!=schedule_vector.end();++iterator){

            if(((*(*iterator)).nameCompare(temp)==0)&&((*(*iterator)).sameDate(date))){
                try{
                    (*(*iterator)).registerParticipant(student);
                    return;  
                }
                catch(AlreadyRegistered&){
                    throw AlreadyRegistered();
                }
                catch(RegistrationBlocked&){
                    throw RegistrationBlocked();
                }
            }
        }
        throw EventDoesNotExist();
    }
    
    bool sameMonthAndYear(const int month,const int year,const BaseEvent& event){
        for(int i=1;i<=30;i++){
            if(event.sameDate(DateWrap(i,month,year))){
                return true;
            }
        }
        return false;
    }

    void Schedule::printAllEvents() const{
        for(std::vector<BaseEvent*>::const_iterator iterator = schedule_vector.begin();
                                                    iterator!=schedule_vector.end();++iterator){

            (*(*iterator)).printShort(std::cout);
            cout<<endl;
        }
    }

    void Schedule::printMonthEvents(const int month,const int year) const{
        for(std::vector<BaseEvent*>::const_iterator iterator = schedule_vector.begin();
                                                    iterator!=schedule_vector.end();++iterator){

            if(sameMonthAndYear(month,year,*(*(iterator)))){  
                (*(*iterator)).printShort(std::cout);
                cout<<endl;
            }    
        }
    }

    void Schedule::printEventDetails(const mtm::DateWrap date,const char* name) const{
        mtm::OpenEvent temp(date,name);
        bool result=false;
        for(std::vector<BaseEvent*>::const_iterator iterator = schedule_vector.begin();
                                                    iterator!=schedule_vector.end();++iterator){

            if(((*(*iterator)).nameCompare(temp)==0)&&((*(*iterator)).sameDate(date))){
                result=true;
                (*(*iterator)).printLong(std::cout);
                cout<<endl;
            }
        }
        if(!result){
            throw EventDoesNotExist();
        }
    }

    void Schedule::unregisterFromEvent(const mtm::DateWrap date,const char* name, const int student){
        mtm::OpenEvent temp(date,name);
        for(std::vector<BaseEvent*>::iterator iterator = schedule_vector.begin();
                                                iterator!=schedule_vector.end();++iterator){
                                                    
            if(((*(*iterator)).nameCompare(temp)==0)&&((*(*iterator)).sameDate(date))){
                try{
                    (*(*iterator)).unregisterParticipant(student);
                    return;  
                }
                catch(NotRegistered&){
                    throw NotRegistered();
                }
            }
        }
        throw EventDoesNotExist();
    }

    const BaseEvent& constConvresion(BaseEvent& event){
        return event;
    }
}