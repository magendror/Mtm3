#include "open_event.h"
#include "base_event.h"
namespace mtm{
    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const char* event_name):
                                                mtm::BaseEvent(event_date,event_name){}
    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const char* event_name,const mtm::StudentList event_list):
                                                mtm::BaseEvent(event_date,event_name,event_list){}

    OpenEvent::~OpenEvent(){}

    OpenEvent* OpenEvent::clone() const{
        OpenEvent copy_of_event(date,name.c_str(),list);
        return &copy_of_event;
    }
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

}
