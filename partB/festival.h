#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"
#include "../partA/date_wrap.h"

namespace mtm {
    class Festival: public EventContainer{
        private:
            const DateWrap date;
            void addAux(FrameEvent* frame,const BaseEvent& event_reference);
        public:
            ~Festival() override;
            Festival(const DateWrap date);
            void add(const BaseEvent& event_reference) override;
            
    };
}
#endif