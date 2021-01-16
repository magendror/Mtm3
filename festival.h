#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"
#include "date_wrap.h"

namespace mtm {
    class festival: public eventContainer{
        private:
            DateWrap date;

        public:
            festival(const DateWrap date):date(date){};
            void add(BaseEvent& event) override;
    };
}
#endif