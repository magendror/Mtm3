#include "event_container.h"

///////////////////////////////////////FrameEvent////////////////////////////////////////////////
namespace mtm{
    FrameEvent::FrameEvent(const BaseEvent& base_event,FrameEvent* next_event =NULL):event(base_event),next(next_event){}

    FrameEvent::~FrameEvent(){}

    FrameEvent::FrameEvent(const FrameEvent& event_to_copy):event(event_to_copy.event),next(event_to_copy.next){}

    bool FrameEvent::operator==(const FrameEvent& event){
        return(this->event==event.event&&this->next==event.next);
    }
}

//////////////////////////////////////////////////eventIterator/////////////////////////////////////

namespace mtm{
    eventContainer::eventIterator::eventIterator(FrameEvent* ptr_to_event=NULL):event_iterator(ptr_to_event){}

    eventContainer::eventIterator::eventIterator(const eventIterator& iterator):event_iterator(iterator.event_iterator){}

    eventContainer::eventIterator::eventIterator& eventContainer::eventIterator::operator=(const eventIterator& iterator){
        if(this==&iterator){
            return *this;
        }
        event_iterator=iterator.event_iterator;
    }

    void eventContainer::eventIterator::operator++(){
        if(event_iterator==NULL){
            throw EndOfContainer();
        }
        event_iterator=event_iterator->next;
    }

    BaseEvent& eventContainer::eventIterator::operator*(){
        return event_iterator->event;
    }

    bool eventContainer::eventIterator::operator==(const eventIterator& iterator2){
        return (event_iterator==iterator2.event_iterator);

    }

    bool eventContainer::eventIterator::operator!=(const eventIterator& iterator2){
        return !(event_iterator==iterator2.event_iterator);
    }

    void eventContainer::eventIterator::setNext(FrameEvent* next_event){
        event_iterator->next=next_event;
    }
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    eventContainer::eventContainer():first_event(NULL){}

    eventContainer::eventIterator eventContainer::end(){
        return eventContainer::eventIterator(NULL);
    }

    eventContainer::eventIterator eventContainer::begin(){
        return eventContainer::eventIterator(first_event);
    }
}
