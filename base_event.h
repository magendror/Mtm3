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
    class studentList {
        private:
        int participants;
        int* students;

        public:
        studentList ();
        ~studentList();
        studentList(const studentList& to_clone);
        bool add(const int new_student);
        bool remove(const int remove_student);
        void printList(ostream& os) const;
    };

    class baseEvent{
        protected:
            std::string name;
            mtm::DateWrap date;
            studentList list;
        public:
            baseEvent(const mtm::DateWrap event_date,const char* event_name);
            baseEvent(const mtm::DateWrap event_date,const char* event_name,studentList event_list);
            virtual ~baseEvent();
            virtual void registerParticipant(const int new_student);
            virtual void unregisterParticipant(const int remove_student);
            virtual void printShort(ostream& os) const;
            virtual void printLong(ostream& os) const;
            virtual baseEvent* clone() const=0;
            bool operator>(const baseEvent& event2) const;
            bool operator<(const baseEvent& event2) const;
    };
}
#endif
