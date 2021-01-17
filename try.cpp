#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "date_wrap.h"
#include "exceptions.h"
#include "open_event.h"
#include "recurring_event.h"
#include "event_container.h"
#include "festival.h"
#include <cstdlib>
#include <iostream>

struct StudentFilter {
    bool operator()(int student) {
        return student == 1 || student == 3 || student == 20000;
    }
};

// int main(int argc, char* argv[]) {
//     mtm::StudentList klo;
//     klo.add(1);
//     mtm::OpenEvent open(mtm::DateWrap(21, 10, 2020),"A Custom Event");
//     //mtm::CustomEvent<StudentFilter> custom(mtm::DateWrap(21, 10, 2020),"A Custom Event", StudentFilter());
//     open.registerParticipant(1);
//     open.printShort(cout);
//     return 0;
// }

int main(int argc, char* argv[]) {
    mtm::StudentList klo;
    klo.add(1);
    mtm::OpenEvent open(mtm::DateWrap(21, 10, 2020),"A Custom Event");
    // open.printLong(cout);
    mtm::OpenEvent open1(mtm::DateWrap(21, 10, 2020),"open1");
    mtm::ClosedEvent close1(mtm::DateWrap(21, 10, 2020),"close1");
    mtm::ClosedEvent close2(mtm::DateWrap(21, 10, 2020),"close2");
    // mtm::Festival festival1(mtm::DateWrap(21, 10, 2020));
    // festival1.add(close1);
    // festival1.add(open);
    // festival1.add(open1);
    // festival1.add(close2);

    
    // mtm::EventContainer::EventIterator iter=festival1.begin();
    // for(;iter!=festival1.end();++iter){
    //     const mtm::BaseEvent& curr_event=*iter;
    //     curr_event.printShort(cout);
    // }

    mtm::RecurringEvent<mtm::OpenEvent> r_event(mtm::DateWrap(21, 10, 2020),"A Custom Event",3,2);
    mtm::EventContainer::EventIterator iter=r_event.begin();
    for(;iter!=r_event.end();++iter){
        const mtm::BaseEvent& curr_event=*iter;
        curr_event.printShort(cout);

    }






}