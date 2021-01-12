#include "event_container.h"

///////////////////////////////////////FrameEvent////////////////////////////////////////////////
namespace mtm{
    FrameEvent::FrameEvent(const BaseEvent& base_event,BaseEvent* next_event =NULL):event(base_event),next(new BaseEvent[1]){
        this->next=next_event;
    }
    FrameEvent::~FrameEvent(){
        delete[] next;
    }
    FrameEvent::FrameEvent(const FrameEvent& event_to_copy):event(event_to_copy.event),next(event_to_copy.next){}
    FrameEvent& FrameEvent::operator=(const FrameEvent& e){
        if(this==&e){
            return *this;
        }
        delete[] next;
        next=new BaseEvent[1];
        event=e.event;
        next=e.next;
        return *this;
    }
}

//////////////////////////////////////////////////eventContainer/////////////////////////////////////

namespace mtm{
    
}