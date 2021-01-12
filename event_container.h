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

namespace mtm{

    class eventContainer{
        protected:
            *baseEvent event_list;
        public:
            eventContainer();
            virtual ~eventContainer();
            virtual void add(const &baseEvent event)=0;
            class eventIterator{
                private:
                    *baseEvent event_iterator;
                public:
                    eventIterator(){iterator=NULL;}
                    eventIterator(const evenetIterator& iterator);
                    ~evenetIterator();
                    evenetIterator& operator=(const evenetIterator& iterator);
                    void operator++();
                    &baseEvent operator*();
                    friend bool operator==(const evenetIterator& iterator1,const evenetIterator& iterator2 );
                
            }
            evenetIterator begin();
            evenetIterator end();
    }
    bool operator!=(const evenetIterator& iterator1,const evenetIterator& iterator2 );

}



#endif