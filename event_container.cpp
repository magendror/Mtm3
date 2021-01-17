#include "event_container.h"

///////////////////////////////////////FrameEvent////////////////////////////////////////////////
namespace mtm{
    FrameEvent::~FrameEvent(){}

    FrameEvent::FrameEvent(const FrameEvent& event_to_copy):event(event_to_copy.event),next(event_to_copy.next){}

    bool FrameEvent::operator==(const FrameEvent& event){
        return(this->event==event.event&&this->next==event.next);
    }
}

//////////////////////////////////////////////////eventIterator/////////////////////////////////////

namespace mtm{
    EventContainer::EventIterator::EventIterator(FrameEvent* ptr_to_event=NULL):event_iterator(ptr_to_event){}

    EventContainer::EventIterator::EventIterator(const EventIterator& iterator):event_iterator(iterator.event_iterator){}

    EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& iterator){
        if(this==&iterator){
            return *this;
        }
        event_iterator=iterator.event_iterator;
        return *this;
    
    }

    
    void EventContainer::EventIterator::operator++(){
        if(event_iterator==NULL){
            throw EndOfContainer();
        }
        event_iterator=event_iterator->next;
    }

    const BaseEvent& EventContainer::EventIterator::operator*()const{
        return event_iterator->event;
    }

    bool EventContainer::EventIterator::operator==(const EventIterator& iterator2){
        return (event_iterator==iterator2.event_iterator);

    }

    bool EventContainer::EventIterator::operator!=(const EventIterator& iterator2){
        return !(event_iterator==iterator2.event_iterator);
    }

    void EventContainer::EventIterator::setNext(FrameEvent* next_event){
        event_iterator->next=next_event;
    }
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    EventContainer::EventIterator EventContainer::end(){
        return EventContainer::EventIterator(NULL);
    }

    EventContainer::EventIterator EventContainer::begin(){
        return EventContainer::EventIterator(first_event);
    }
}
