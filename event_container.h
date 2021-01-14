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
            BaseEvent* event;
            FrameEvent* next;
            FrameEvent(const BaseEvent& event,BaseEvent* next =NULL);
            ~FrameEvent();
            FrameEvent(const FrameEvent& event_to_copy);
            FrameEvent& operator=(const FrameEvent& event);
            bool operator==(const FrameEvent& event);
    }
}
//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    class eventContainer{
        protected:
            FrameEvent* first_event;
            FrameEvent* event_list;
        public:
            eventContainer()=default;
            virtual ~eventContainer()=default;
            virtual void add(const FrameEvent& event)=0;
            
            class eventIterator{
                private:
                    FrameEvent* event_iterator;
                public:
                    eventIterator()=default;
                    eventIterator(const eventIterator& iterator);
                    ~eventIterator()=default;
                    eventIterator& operator=(const eventIterator& iterator);
                    void operator++();
                    BaseEvent& operator*();
                    bool operator==(const eventIterator& iterator2);
                    bool operator!=(const eventIterator& iterator2);

            }
            eventIterator* end();
            eventIterator* begin();

    }
}
#endif