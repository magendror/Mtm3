#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../partB/base_event.h"
#include "../partB/closed_event.h"
#include "../partB/custom_event.h"
#include "../partA/date_wrap.h"
#include "../partB/event_container.h"
#include "../partA/exceptions.h"
#include "../partB/festival.h"
#include "../partB/one_time_event.h"
#include "../partB/open_event.h"
#include "../partB/recurring_event.h"
#include <iostream>
#include "../partA/date_wrap.h"
#include <vector> 
#include <algorithm>

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
typedef mtm::EventContainer::EventIterator ContainerIterator;

extern "C"{
    #include "../partA/date.h"
}

namespace mtm{

    class Schedule{
        private:
            std::vector<BaseEvent> schedule_vector;
        public:
            Schedule();
            ~Schedule();
            void addEvents(EventContainer& container);

    };
}

#endif


