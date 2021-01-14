#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_
#include "event_container.h"
#include <iostream>
namespace mtm{
    template <class EventType>
    class RecurringEvent: public eventContainer{
        private:
            int num_occurrence;
            int interval_days;
            FrameEvent event_list;
        public:
            RecurringEvent(const DateWrap first_date,const std::string name,const int num_occurrence,const int interval_days ):event_list(EventType(first_date,name)),num_occurrence(num_occurrence),interval_days(interval_days){
                if(num_occurrence<0){
                    throw(InvalidNumber);
                }
                if(interval_days<0){
                    throw(InvalidInterval);
                }
                DateWrap date=first_date;
                FrameEvent event_iterator=event_list;
                for(int i=1;i<num_occurrence;i++){
                    date+=interval_days;
                    event_iterator.next=FrameEvent(EventType(first_date,name));
                    event_iterator=event_iterator.next;
                }

            }
            void add(const FrameEvent& event) override{
                throw(NotSupported);
            }


    }

}
#endif