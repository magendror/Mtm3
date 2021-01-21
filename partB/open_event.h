#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

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
    class OpenEvent: public BaseEvent{
        public:
            OpenEvent(const mtm::DateWrap event_date,const char* event_name);
            OpenEvent(const mtm::DateWrap event_date,const char* event_name,mtm::StudentList event_list);
            OpenEvent(const mtm::DateWrap event_date,const std::string event_name);
            OpenEvent(const mtm::DateWrap event_date,const std::string event_name,mtm::StudentList event_list);            
            ~OpenEvent();
            OpenEvent* clone() const override;
            bool operator==(const OpenEvent& event2) const;
            bool operator==(const BaseEvent& event2) const;
    };
}
#endif
