#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class OneTimeEvent: public eventContainer{
        private:
            FrameEvent event;
        public:
            OneTimeEvent(const DateWrap date,const std::string name):event(EventType(date,name)){}
             void add(const FrameEvent& event) override{
                throw(NotSupported);
            }
    }
}
#endif