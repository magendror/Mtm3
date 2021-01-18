#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"
#include "date_wrap.h"

namespace mtm {
    class Festival: public EventContainer{
        private:
            const DateWrap date;
            void addAux(FrameEvent* frame, BaseEvent& event_reference);
        public:
            ~Festival() override;
            Festival(const DateWrap date);
            void add(BaseEvent& event_reference) override;
            
    };
}
#endif