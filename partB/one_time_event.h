#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class OneTimeEvent: public EventContainer{
        private:
            EventType* event;
            FrameEvent* eventCreate(const mtm::DateWrap date,const char* name){
                event = new EventType(date,name);
                FrameEvent* frame = new FrameEvent(*event);
                return frame;
            }
        public:
            OneTimeEvent(const DateWrap date,const char* name):EventContainer(){
                first_event=eventCreate(date,name);
            }
            ~OneTimeEvent(){
                delete event;
                delete first_event;
            }
            void add(BaseEvent& event) override{
                throw NotSupported();
            }
    };
}
#endif