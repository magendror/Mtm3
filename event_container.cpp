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

//////////////////////////////////////////////////eventIterator/////////////////////////////////////

namespace mtm{
    eventContainer::eventIterator::eventIterator(const eventIterator& iterator):event_iterator(*FrameEvent(iterator.event_list,iterator.next)){}
    eventContainer::eventIterator::eventIterator& eventContainer::eventIterator::operator=(const eventIterator& iterator){
        if(this==&iterator){
            return *this;
        }


    }
    void eventContainer::eventIterator::operator++(){
        this->event_iterator->event=this->event_iterator->next;
    }
    BaseEvent& eventContainer::eventIterator::operator*(){
        return *(this->event_iterator->event);
    }
    bool eventContainer::eventIterator::operator==(const eventIterator& iterator2){

    }
    bool eventContainer::eventIterator::operator!=(const eventIterator& iterator2){
        
    }



    
    
}