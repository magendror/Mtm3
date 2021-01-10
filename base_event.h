#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <iostream>
#include "date_wrap.h"
extern "C"{
    #include "date.h"
}

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

namespace{
    class participantList {
        private:
        int participants;
        int* students;

        public:
        participantList ();
        ~participantList();
        bool add(int new_student);
        bool remove(int remove_student);
        void printList(ostream& os);
    };

    class baseEvent{
        private:
            std::string name;
            mtm::DateWrap date;
            participantList list;
        public:
            baseEvent(mtm::DateWrap event_date,char* event_name);
            baseEvent::~baseEvent();
            void registerParticipant(int new_student);
            void unregisterParticipant(int remove_student);
            void printShort(ostream& os);
            void printLong(ostream& os);
    };
}
#endif
