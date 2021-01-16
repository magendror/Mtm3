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
    class StudentList {
        private:
        int participants;
        int* students;

        public:
        StudentList ();
        ~StudentList();
        StudentList(const StudentList& to_clone);
        bool add(const int new_student);
        bool remove(const int remove_student);
        bool contains(const int check_student);
        void printList(ostream& os) const;
    };

    class BaseEvent{
        protected:
            std::string name;
            mtm::DateWrap date;
            StudentList list;
            static std::string assign(const char* event_name);
        public:
            BaseEvent(const mtm::DateWrap event_date,const char* event_name);
            BaseEvent(const mtm::DateWrap event_date,const char* event_name,StudentList event_list);
            virtual ~BaseEvent();
            virtual void registerParticipant(const int new_student);
            virtual void unregisterParticipant(const int remove_student);
            virtual void printShort(ostream& os) const;
            virtual void printLong(ostream& os) const;
            virtual BaseEvent* clone() const=0;
            bool operator>(const BaseEvent& event2) const;
            bool operator<(const BaseEvent& event2) const;
            bool sameDate(const mtm::DateWrap date2) const;
            bool operator==(const BaseEvent& event2) const;
            int nameCompare(BaseEvent& event2);
    };
}
#endif
