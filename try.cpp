#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "date_wrap.h"
#include "exceptions.h"
#include "open_event.h"
#include <cstdlib>
#include <iostream>

struct StudentFilter {
    bool operator()(int student) {
        return student == 1 || student == 3 || student == 20000;
    }
};

int main(int argc, char* argv[]) {
    mtm::StudentList klo;
    klo.add(1);
    mtm::OpenEvent open(mtm::DateWrap(21, 10, 2020),"A Custom Event");
    //mtm::CustomEvent<StudentFilter> custom(mtm::DateWrap(21, 10, 2020),"A Custom Event", StudentFilter());
    open.registerParticipant(1);
    open.printShort(cout);
    return 0;
}
