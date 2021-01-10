#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <iostream>
#include "date_wrap.h"

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

namespace{
    class participantList {
        private:
        int participant;
        int* students;

        public:
        participantList ();
        ~participantList();
        bool add(int new_student);
        bool remove(int remove_student);
    };

    class baseEvent{
        private:
            std::string name;
            mtm::DateWrap date;
            participantList list;
        public:
            void registerParticipant(int new_student);
            void registerParticipant(int new_student);


    };
}
#endif
