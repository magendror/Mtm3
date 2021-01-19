#include "event_container.h"

///////////////////////////////////////FrameEvent////////////////////////////////////////////////
namespace mtm{
    FrameEvent::FrameEvent(BaseEvent* const base_event,FrameEvent* next_event)try:
                                            event(base_event),next(next_event){}
                                            catch(mtm::Exception&){
                                                throw;
                                            }

    FrameEvent::~FrameEvent(){
        delete event;
    }

    FrameEvent::FrameEvent(const FrameEvent& event_to_copy)try:event(event_to_copy.event),next(event_to_copy.next){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }

    bool FrameEvent::operator==(const FrameEvent& frame_event2){
        return(this->event==frame_event2.event&&this->next==frame_event2.next);
    }
}

//////////////////////////////////////////////////eventIterator/////////////////////////////////////

namespace mtm{
    EventContainer::EventIterator::EventIterator(FrameEvent* ptr_to_event=NULL)try:
                                                event_iterator(ptr_to_event){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    EventContainer::EventIterator::EventIterator(const EventIterator& iterator)try:
                                                event_iterator(iterator.event_iterator){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
                                                
    EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& iterator2){
        if(this==&iterator2){
            return *this;
        }
        event_iterator=iterator2.event_iterator;
        return *this;
    }

    
    EventContainer::EventIterator& EventContainer::EventIterator::operator++(){
        if(event_iterator==NULL){
            throw EndOfContainer();
        }
        event_iterator=event_iterator->next;
        return *this;
    }

    BaseEvent& EventContainer::EventIterator::operator*() const {
        return *(event_iterator->event);
    }

    bool EventContainer::EventIterator::operator==(const EventIterator& iterator2) const{
        return (event_iterator==iterator2.event_iterator);

    }

    bool EventContainer::EventIterator::operator!=(const EventIterator& iterator2) const{
        return !(event_iterator==iterator2.event_iterator);
    }

    void EventContainer::EventIterator::setNext(FrameEvent* next_event){
        event_iterator->next=next_event;
    }

    FrameEvent* EventContainer::EventIterator::framePtr() const{
        return event_iterator;
    }
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    EventContainer::EventContainer():first_event(NULL){}

    EventContainer::EventIterator EventContainer::end(){
        return EventContainer::EventIterator(NULL);
    }

    EventContainer::EventIterator EventContainer::begin(){
        return EventContainer::EventIterator(first_event);
    }
}
