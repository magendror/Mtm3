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

namespace mtm{
    class participantList {
        private:
        int participants;
        int* students;

        public:
        participantList ();
        ~participantList();
        participantList(const participantList& to_clone);
        bool add(const int new_student);
        bool remove(const int remove_student);
        void printList(ostream& os) const;
    };

    class baseEvent{
        private:
            std::string name;
            mtm::DateWrap date;
            participantList list;
        public:
            baseEvent(const mtm::DateWrap event_date,const char* event_name);
            baseEvent(const mtm::DateWrap event_date,const char* event_name,participantList event_list);
            ~baseEvent();
            void registerParticipant(const int new_student);
            void unregisterParticipant(const int remove_student);
            void printShort(ostream& os) const;
            void printLong(ostream& os) const;
            baseEvent* clone() const;
    };
}
#endif
