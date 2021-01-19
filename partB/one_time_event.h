#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_
#include "event_container.h"
#include <iostream>

namespace mtm{
    template <class EventType>
    class OneTimeEvent: public EventContainer{
        private:
            FrameEvent* eventCreate(const mtm::DateWrap date,const char* name){
                EventType* event = new EventType(date,name);
                FrameEvent* frame = new FrameEvent(event);
                return frame;
            }
            FrameEvent* eventCreate(const mtm::DateWrap date,const std::string name){
                EventType* event = new EventType(date,name);
                FrameEvent* frame = new FrameEvent(event);
                return frame;
            }
        public:
            OneTimeEvent(const DateWrap date,const char* name)try:EventContainer(){
                first_event=eventCreate(date,name);
            }
            catch(mtm::Exception&){
                throw;
            }

            OneTimeEvent(const DateWrap date,const std::string name)try:EventContainer(){
                first_event=eventCreate(date,name);
            }
            catch(mtm::Exception&){
                throw;
            }

            ~OneTimeEvent(){
                delete first_event;
            }

            void add(const BaseEvent& event) override{
                throw NotSupported();
            }
    };
}
#endif