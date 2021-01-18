#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class OneTimeEvent: public EventContainer{
        private:
            FrameEvent event;
        public:
            OneTimeEvent(const DateWrap date,const char* name):event(FrameEvent(EventType(date,name))){
                first_event=&event;
            }
            void add(const BaseEvent& event) override{
                throw NotSupported();
            }
    };
}
#endif