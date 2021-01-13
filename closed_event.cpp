#include "closed_event.h"
#include "base_event.h"
namespace mtm{
    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const char* event_name):
                                                mtm::BaseEvent(event_date,event_name),
                                                invited_list(mtm::StudentList()){}
    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const char* event_name,
                            const mtm::StudentList event_list,const mtm::StudentList invited_list):
                                                mtm::BaseEvent(event_date,event_name,event_list),
                                                invited_list(mtm::StudentList(invited_list)){}

    ClosedEvent::~ClosedEvent(){}

    ClosedEvent* ClosedEvent::clone() const{
        ClosedEvent* copy_of_event = new ClosedEvent(date,name.c_str(),list,invited_list);
        return copy_of_event;
    }

    void ClosedEvent::registerParticipant(const int new_student){
        if(invited_list.contains(new_student)){
            if(list.add(new_student)==false){
                throw AlreadyRegistered();
            }
        }
        else{
            throw RegistrationBlocked();
        }
    }

    void ClosedEvent::addInvitee(const int new_student){
        if(invited_list.contains(new_student)){
            throw AlreadyInvited();  
        }
        else{
            invited_list.add(new_student);
        }
    }
/*
    void baseEvent::unregisterParticipant(const int remove_student){
        if(list.remove(remove_student)==false){
            //student is not in the list
        }
    }

    void baseEvent::printShort(ostream& os) const {
        os<<name<<" "<<date;
    }
    void baseEvent::printLong(ostream& os) const {
        os<<name<<" "<<date<<endl;
        list.printList(os);
    }
*/

}
