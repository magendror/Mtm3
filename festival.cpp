#include "festival.h"

namespace mtm{
    void festival::add(const FrameEvent& event){
        if(this->date!=event.event.date){
            throw(DateMismatch);
        }
        if(this->first_event==NULL){
            this->date=event.date;//waiting for date permission
            *this->first_event=event;
            *this->event_list=event;
        }
        FrameEvent* iterator=this.begin();
        FrameEvent* privios_iterator=NULL;
        while(iterator!=NULL){
            if(event.name<iterator.event.name){
                privios_iterator->next=event.event;
                event.next=iterator->event;
            }
            privios_iterator=iterator;
            iterator=iterator->next;
        }





    }
}