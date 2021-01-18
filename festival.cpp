#include "festival.h"

namespace mtm{
    void Festival::add(const BaseEvent& event){
        if(!event.sameDate(date)){
            throw DateMismatch();
        }
        FrameEvent frame(event);//
        if(first_event==NULL){
            first_event->event=event;
            first_event->event=NULL;
            return;
        }
        EventContainer::EventIterator iterator=this->begin();
        EventContainer::EventIterator previous_iterator(NULL);
        while(iterator!=this->end()){
            if(event.nameCompare(*iterator)<0){
                previous_iterator.setNext(&frame);
                previous_iterator.event_iterator->next=&frame;
                frame.next=iterator.event_iterator;
                return;
            }
            previous_iterator=iterator;
            iterator=iterator.event_iterator->next;
           

        }
        previous_iterator.event_iterator->next=&frame;

    }
}