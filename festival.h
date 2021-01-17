#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"
#include "date_wrap.h"

namespace mtm {
    class Festival: public EventContainer{
        private:
            const DateWrap date;

        public:
            Festival(const DateWrap date):date(date){};
            // Festival(const DateWrap date):date(date){};
            void add(const BaseEvent& event) override;
    };
}
#endif