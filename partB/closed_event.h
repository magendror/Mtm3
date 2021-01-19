#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include <iostream>
#include "../partA/date_wrap.h"
#include "base_event.h"
extern "C"{
    #include "../partA/date.h"
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
            ClosedEvent(const mtm::DateWrap event_date,const std::string event_name);
            ClosedEvent(const mtm::DateWrap event_date,const std::string event_name,
                        const mtm::StudentList event_list,const mtm::StudentList invited_list);
            ~ClosedEvent();
            void registerParticipant(const int new_student) override;
            void addInvitee(const int new_student);
            ClosedEvent& operator=(const ClosedEvent& event2);
            ClosedEvent* clone() const override;
    };
}
#endif
