#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include <iostream>
#include "../partA/date_wrap.h"
#include "base_event.h"
extern "C"{
    #include "../partA/date.h"
}

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
//////////////////////////////////////////////////FrameEvent/////////////////////////////////////////
namespace mtm{
    class FrameEvent{
        public:
            BaseEvent* const event;
            FrameEvent* next;
            FrameEvent(BaseEvent* const base_event,FrameEvent* next_event=NULL);
            ~FrameEvent();
            FrameEvent(const FrameEvent& event_to_copy);
            FrameEvent& operator=(const FrameEvent& frame_event2);
            bool operator==(const FrameEvent& frame_event2);
    };
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    class EventContainer{
        protected:
            FrameEvent* first_event;//
        public:
            EventContainer();
            virtual ~EventContainer()=default;
            virtual void add(const BaseEvent& event)=0;
            class EventIterator{
                private:
                    FrameEvent* event_iterator;
                public:
                    EventIterator(FrameEvent* ptr_to_event);
                    EventIterator(const EventIterator& iterator);
                    ~EventIterator()=default;
                    EventIterator& operator=(const EventIterator& iterator2);
                    EventIterator& operator++();
                    BaseEvent& operator*() const;
                    bool operator==(const EventIterator& iterator2) const;
                    bool operator!=(const EventIterator& iterator2) const;
                    void setNext(FrameEvent* next_event);
                    FrameEvent* framePtr() const;

            };
            EventIterator end() const;
            EventIterator begin() const;
    };
}
#endif