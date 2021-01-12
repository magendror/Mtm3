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

//////////////////////////////////////////////////eventContainer/////////////////////////////////////
namespace mtm{
    class eventContainer{
        protected:
            BaseEvent* event_list;
        public:
            eventContainer();
            virtual ~eventContainer();
            virtual void add(const BaseEvent& event)=0;
            class eventIterator{
                private:
                    BaseEvent* event_iterator;
                public:
                    eventIterator(){iterator=NULL;}
                    eventIterator(const evenetIterator& iterator);
                    ~evenetIterator();
                    evenetIterator& operator=(const evenetIterator& iterator);
                    void operator++();
                    baseEvent& operator*();
                    bool operator==(const evenetIterator& iterator2);
                    bool operator!=(const evenetIterator& iterator2);

            }
            evenetIterator begin();
            evenetIterator end();
    }
}



#endif