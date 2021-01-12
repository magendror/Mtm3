#include "open_event.h"
#include "base_event.h"
namespace mtm{
    openEvent::openEvent(const mtm::DateWrap event_date,const char* event_name):
                                                mtm::baseEvent(event_date,event_name){}
    baseEvent::baseEvent(const mtm::DateWrap event_date,const char* event_name,const participantList event_list):
                                                mtm::baseEvent(event_date,event_name,event_list){}

    baseEvent::~baseEvent(){}
/*
    void baseEvent::registerParticipant(const int new_student){
        if(list.add(new_student)==false){
            //student is already here
        }
    }

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
    openEvent* openEvent::clone() const{
        const char* name_in_char = name.c_str(); 
        openEvent copy_of_event(date,name.c_str(),list);
        return &copy_of_event;
    }
}
