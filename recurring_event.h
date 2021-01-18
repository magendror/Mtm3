#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"
#include "exceptions.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class RecurringEvent: public EventContainer{
        private:
            const int num_occurrence;
            const int interval_days;
            // FrameEvent* event_list;
        public:
            RecurringEvent(const DateWrap first_date,const char* name,const int num_occurrence,const int interval_days);
            void add(const BaseEvent& event) override;
    };

    template <class EventType>
    RecurringEvent<EventType>::RecurringEvent(const DateWrap first_date,const char* name,const int num_occurrence,const int interval_days):num_occurrence(num_occurrence),interval_days(interval_days),event_list(EventType(first_date,name)){
        if(num_occurrence<0){
            throw InvalidNumber();
        }
        if(interval_days<0){
            throw InvalidInterval();
        }
        DateWrap date=first_date;
        FrameEvent* event_iterator=first_event;
        for(int i=1;i<num_occurrence;i++){
            date+=interval_days;
            event_iterator->next=&FrameEvent(const EventType(first_date,name));
            event_iterator=event_iterator->next;
        }
    }

    template <class EventType>
    void RecurringEvent<EventType>::add(const BaseEvent& event){
        throw NotSupported();
    }
}
#endif

