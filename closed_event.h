#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

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
    class ClosedEvent: public BaseEvent{
        private:
            mtm::StudentList invited_list;
        public:
            ClosedEvent(const mtm::DateWrap event_date,const char* event_name);
            ClosedEvent(const mtm::DateWrap event_date,const char* event_name,
                        const mtm::StudentList event_list,const mtm::StudentList invited_list);
            ~ClosedEvent();
            void registerParticipant(const int new_student) override;
            void addInvitee(const int new_student);
            /*virtual void unregisterParticipant(const int remove_student);
            virtual void printShort(ostream& os) const;
            virtual void printLong(ostream& os) const;*/
            ClosedEvent* clone() const override;
    };
}
#endif
