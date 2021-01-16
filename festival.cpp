#include "festival.h"

namespace mtm{
    void festival::add(BaseEvent& event){
        if(!event.sameDate(date)){
            throw DateMismatch();
        }
        FrameEvent frame(event);
        if(first_event==NULL){
            first_event=event;//waiting for date permission
        }
        eventContainer::eventIterator iterator=this->begin();
        eventContainer::eventIterator previous_iterator=NULL;
        while(iterator!=this->end()){
            if(event.nameCompare(*iterator)<0){
                previous_iterator.setNext(&frame);
                privios_iterator->next=event.event;
                event.next=iterator->event;
            }
            privios_iterator=iterator;
            iterator=iterator->next;
        }





    }
}