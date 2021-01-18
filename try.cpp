#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "date_wrap.h"
#include "exceptions.h"
#include "open_event.h"
#include "recurring_event.h"
#include "one_time_event.h"
#include "event_container.h"
#include "festival.h"
#include <cstdlib>
#include <iostream>

using namespace mtm;

struct StudentFilter {
    bool operator()(int student) {
        return student%2==0;
    }
};

int main(int argc, char* argv[]) {
    RecurringEvent<OpenEvent> recurring(mtm::DateWrap(21, 10, 2020),"open1",4,1);
    mtm::CustomEvent<StudentFilter> custom1(mtm::DateWrap(21, 10, 2020),"A Custom Event",StudentFilter());
    OneTimeEvent<OpenEvent> onetime(mtm::DateWrap(21, 10, 2020),"open1");
    mtm::EventContainer::EventIterator iter2=onetime.begin();
    (*iter2).printShort(cout);
    mtm::OpenEvent open1(mtm::DateWrap(21, 10, 2020),"open1");
    mtm::ClosedEvent close1(mtm::DateWrap(21, 10, 2020),"close1");
    mtm::ClosedEvent close2(mtm::DateWrap(21, 10, 2020),"close2");
    mtm::Festival festival1(mtm::DateWrap(21, 10, 2020));
    festival1.add(close1);
    festival1.add(custom1);
    festival1.add(open1);
    festival1.add(close2);
    mtm::EventContainer::EventIterator iter=festival1.begin();
    for(;iter!=festival1.end();++iter){
        (*iter).printShort(cout);
    }
    return 0;
}