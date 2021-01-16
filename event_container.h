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
            FrameEvent(const BaseEvent& event,FrameEvent* next =NULL);
            ~FrameEvent();
            FrameEvent(const FrameEvent& event_to_copy);
            FrameEvent& operator=(const FrameEvent& event);
            bool operator==(const FrameEvent& event);
    };
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    class eventContainer{
        protected:
            FrameEvent* first_event;
        public:
            eventContainer();
            virtual ~eventContainer()=default;
            virtual void add(const BaseEvent& event)=0;
            class eventIterator{
                protected:
                    FrameEvent* event_iterator;
                public:
                    eventIterator(FrameEvent* ptr_to_event);
                    eventIterator(const eventIterator& iterator);
                    ~eventIterator()=default;
                    eventIterator& operator=(const eventIterator& iterator);
                    void operator++();
                    BaseEvent& operator*();
                    bool operator==(const eventIterator& iterator2);
                    bool operator!=(const eventIterator& iterator2);
                    void setNext(FrameEvent* next_event);

            };
            eventIterator end();
            eventIterator begin();
    };
}
#endif