#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"
extern "C"{
    #include "date.h"
}

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

namespace mtm{
    class OpenEvent: public BaseEvent{
        public:
            OpenEvent(const mtm::DateWrap event_date,const char* event_name);
            OpenEvent(const mtm::DateWrap event_date,const char* event_name,mtm::StudentList event_list);
            ~OpenEvent();
            /*virtual void registerParticipant(const int new_student);
            virtual void unregisterParticipant(const int remove_student);
            virtual void printShort(ostream& os) const;
            virtual void printLong(ostream& os) const;*/
            OpenEvent* clone() const override;
    };
}
#endif
