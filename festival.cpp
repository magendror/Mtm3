#include "festival.h"

namespace mtm{

    Festival::Festival(const DateWrap date):date(date){}
    Festival::~Festival(){
        EventContainer::EventIterator iterator=this->begin();
        while(iterator!=this->end()){
            EventContainer::EventIterator previous_iterator=iterator;
            ++iterator;
            delete previous_iterator.framePtr();
        }
    }

    void Festival::add(BaseEvent& event_reference){
        if(!event_reference.sameDate(date)){
            throw DateMismatch();
        }
        FrameEvent* frame = new FrameEvent(event_reference);//
        if(first_event==NULL){
            first_event=frame;
            return;
        }
        addAux(frame,event_reference);   
    }

    void Festival::addAux(FrameEvent* frame, BaseEvent& event_reference){
        EventContainer::EventIterator iterator=this->begin();
        EventContainer::EventIterator previous_iterator(NULL);
        while(iterator!=this->end()){
            if(event_reference.nameCompare(*iterator)<0){
                if(previous_iterator.framePtr()==NULL){
                    frame->next=first_event;
                    first_event=frame;
                }
                else{
                    previous_iterator.setNext(frame);//maybe here saves pointer to local frame?
                    frame->next=iterator.framePtr();  
                }
                return;
            }
            previous_iterator=iterator;
            ++iterator;
        }
        previous_iterator.setNext(frame);
    }
}