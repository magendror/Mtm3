#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"

namespace mtm {
    class festival: public eventContainer{
        private:
            DateWrap date;

        public:
            festival(const DateWrap date):date(date){};
            void add(const &baseEvent event) override;
    }

}


#endif