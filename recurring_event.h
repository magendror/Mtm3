#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"
#include "exceptions.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class RecurringEvent: public EventContainer{
        private:
            EventType** event_list;
            int num_occurrence;
        public:
            RecurringEvent(const DateWrap first_date,const char* name,const int num_occurrence,const int interval_days);
            ~RecurringEvent();
            void add(BaseEvent& event) override;
    };

    template <class EventType>
    RecurringEvent<EventType>::RecurringEvent(const DateWrap first_date,const char* name,const int num_occurrence,const int interval_days):
                                                        event_list(new EventType*[num_occurrence]),num_occurrence(num_occurrence){
        if(num_occurrence<=0){
            throw InvalidNumber();
        }
        if(interval_days<=0){
            throw InvalidInterval();
        }
        FrameEvent* event_iterator=first_event;
        for(int i=0;i<num_occurrence;i++){
            EventType* temp_event = new EventType(first_date + i*interval_days,name);
            FrameEvent* temp_frame = new FrameEvent(*temp_event);   
            event_list[i]=temp_event;
            if(first_event==NULL){
                first_event=temp_frame;
                event_iterator=first_event;
            }
            else{
                event_iterator->next=temp_frame;
                event_iterator=event_iterator->next;
            }
        }
    }
    template <class EventType>
    RecurringEvent<EventType>::~RecurringEvent(){
        for (int i=0; i< num_occurrence;i++){
            delete event_list[i];
        }
        delete[] event_list;
        EventContainer::EventIterator iterator=this->begin();
        EventContainer::EventIterator previous_iterator(NULL);
        while(iterator!=this->end()){
        previous_iterator=iterator;
        ++iterator;
        delete previous_iterator.framePtr();   
        }
    }

    template <class EventType>
    void RecurringEvent<EventType>::add(BaseEvent& event){
        throw NotSupported();
    }
}
#endif

