#include "open_event.h"
#include "base_event.h"
namespace mtm{
    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const char* event_name)try:
                                                mtm::BaseEvent(event_date,event_name){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const char* event_name,const mtm::StudentList event_list)try:
                                                mtm::BaseEvent(event_date,event_name,event_list){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const std::string event_name)try:
                                                mtm::BaseEvent(event_date,event_name){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    OpenEvent::OpenEvent(const mtm::DateWrap event_date,const std::string event_name,
                                                const mtm::StudentList event_list)try:
                                                mtm::BaseEvent(event_date,event_name,event_list){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
                                                
    OpenEvent::~OpenEvent(){}

    OpenEvent* OpenEvent::clone() const{
        OpenEvent* copy_of_event = new OpenEvent(date,name.c_str(),list);
        return copy_of_event;
    }

    bool OpenEvent::operator==(const OpenEvent& event2) const{
        return((event2.sameDate(date))&&(event2.nameCompare(*this)==0));
    }

    bool OpenEvent::operator==(const BaseEvent& event2) const{
        return((event2.sameDate(date))&&(event2.nameCompare(*this)==0));
    }

    
}
