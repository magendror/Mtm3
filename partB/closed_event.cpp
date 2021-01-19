#include "closed_event.h"
#include "base_event.h"
namespace mtm{
    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const char* event_name)try:
                                                mtm::BaseEvent(event_date,event_name),
                                                invited_list(mtm::StudentList()){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const char* event_name,
                            const mtm::StudentList event_list,const mtm::StudentList invited_list)try:
                                                mtm::BaseEvent(event_date,event_name,event_list),
                                                invited_list(mtm::StudentList(invited_list)){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const std::string event_name)try:
                                                mtm::BaseEvent(event_date,event_name),
                                                invited_list(mtm::StudentList()){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    ClosedEvent::ClosedEvent(const mtm::DateWrap event_date,const std::string event_name,
                            const mtm::StudentList event_list,const mtm::StudentList invited_list)try:
                                                mtm::BaseEvent(event_date,event_name,event_list),
                                                invited_list(mtm::StudentList(invited_list)){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    ClosedEvent::~ClosedEvent(){}

    ClosedEvent* ClosedEvent::clone() const{
        ClosedEvent* copy_of_event = new ClosedEvent(date,name.c_str(),list,invited_list);
        return copy_of_event;
    }

    void ClosedEvent::registerParticipant(const int new_student){
        if((new_student>=1234567890)||(new_student<=0)){
            throw InvalidStudent();
        }
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
    ClosedEvent& ClosedEvent::operator=(const ClosedEvent& event2){
        if (this == &event2) {
		    return *this;
	    }
        name=event2.name;
        date=event2.date;
        list=event2.list;
        invited_list=event2.invited_list;
        return *this;
    }

}
