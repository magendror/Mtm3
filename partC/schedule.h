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

namespace mtm {

    class Schedule{
        private:
            std::vector<BaseEvent*> schedule_vector;
        public:
            Schedule();
            ~Schedule();
            void addEvents(const EventContainer& container);
            void registerToEvent(const mtm::DateWrap date,const char* name, const int student);
            void unregisterFromEvent(const mtm::DateWrap date,const char* name, const int student);
            void printAllEvents() const;
            void printMonthEvents(const int month,const int year) const;
            void printEventDetails(const mtm::DateWrap date,const char* name) const;      
            const BaseEvent& constConvresion(BaseEvent& event);
            template <class Predicate>
            void printSomeEvents(Predicate pred,bool verbose=false) const{
                for(std::vector<BaseEvent>::const_iterator iterator = schedule_vector.begin();iterator!=schedule_vector.end();++iterator){
                    if(pred(*iterator)){
                        if(verbose){
                            (*iterator).printLong(std::cout);
                        }
                        else{
                            (*iterator).printShort(std::cout);
                        }
                    }
                }
            } 
    };
}

#endif


