#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
extern "C"{
    #include "date.h"
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
            const BaseEvent& event;
            FrameEvent* next;
            FrameEvent(const BaseEvent& base_event,FrameEvent* next_event=NULL):event(base_event),next(next_event){};
            ~FrameEvent();
            FrameEvent(const FrameEvent& event_to_copy);
            FrameEvent& operator=(const FrameEvent& event);
            bool operator==(const FrameEvent& event);
    };
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    class EventContainer{
        protected:
            FrameEvent* first_event;//
        public:
            EventContainer():first_event(NULL){};
            virtual ~EventContainer()=default;
            virtual void add(const BaseEvent& event)=0;
            class EventIterator{
                // protected:
                //     FrameEvent* event_iterator;
                public:
                    FrameEvent* event_iterator;
                    EventIterator(FrameEvent* ptr_to_event);
                    EventIterator(const EventIterator& iterator);
                    ~EventIterator()=default;
                    EventIterator& operator=(const EventIterator& iterator);
                    void operator++();
                    const BaseEvent& operator*()const;
                    bool operator==(const EventIterator& iterator2);
                    bool operator!=(const EventIterator& iterator2);
                    void setNext(FrameEvent* next_event);

            };
            EventIterator end();
            EventIterator begin();
    };
}
#endif