#include "schedule.h"
#include "../partB/base_event.h"

namespace mtm{

    Schedule::Schedule():schedule_vector(){}

    void Schedule::addEvents(const EventContainer& container){
        for (ContainerIterator container_iterator = container.begin(); container_iterator != container.end();
                                                                                        ++container_iterator){
            std::vector<BaseEvent>::iterator iterator = std::find(schedule_vector.begin(),schedule_vector.end()
                                                                                            ,*container_iterator);
            if(iterator!=schedule_vector.end()){
                throw EventAlreadyExists();
            }   
        }
        for (ContainerIterator container_iterator = container.begin(); container_iterator != container.end();++container_iterator){
                schedule_vector.resize(schedule_vector.size() + 1);
                schedule_vector.assign(1,*container_iterator);
        }   
    }
    void Schedule::registerToEvent(const mtm::DateWrap date,const char* name, const int student){
        mtm::OpenEvent temp(date,name);
        for(std::vector<BaseEvent>::iterator iterator = schedule_vector.begin();iterator!=schedule_vector.end();++iterator){
            if(((*iterator).nameCompare(temp)==0)&&((*iterator).sameDate(date))){
                try{
                    (*iterator).registerParticipant(student);  
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
    bool compareFunc(const BaseEvent event1,const BaseEvent event2){
        return event1>event2;
    }
    bool sameMonthAndYear(const int month,const int year,const BaseEvent event){
        bool result=false;
        for(int i=0;i<=30;i++){
            if(event.sameDate(DateWrap(i,month,year))){
                result=true;
            }
        }
        return result;
    }

    void printAllEvents(){
        std::sort(schedule_vector.begin(), schedule_vector.end(), compareFunc);
        for(std::vector<BaseEvent>::iterator iterator = schedule_vector.begin();iterator!=schedule_vector.end();++iterator){
            BaseEvent::printShort(iterator);
            printf("\n");
        }
    }

    void printMonthEvents(const int month,const int year){
        for(std::vector<BaseEvent>::iterator iterator = schedule_vector.begin();iterator!=schedule_vector.end();++iterator){
            if(sameMonthAndYear(month,year,iterator)){  
                BaseEvent::printShort(iterator);
                printf("\n");
            }    
        }
    }

    void printEventDetails(const mtm::DateWrap date,const char* name){
        BaseEvent event(date,name);
        bool result=false;
        for(std::vector<BaseEvent>::iterator iterator = schedule_vector.begin();iterator!=schedule_vector.end();++iterator){
            if(iterator==event){
                result=true;
                BaseEvent::printLong(iterator);
            }
        }
        if(!result){
            throw EventDoesNotExist();
        }
    }
    



}