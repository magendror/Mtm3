#include "schedule.h"
#include "../partB/base_event.h"

namespace mtm{

    Schedule::Schedule():schedule_vector(){}

    void Schedule::addEvents(EventContainer& container){
        for (ContainerIterator container_iterator = container.begin(); container_iterator != container.end();
                                                                                        ++container_iterator){
            std::vector<BaseEvent>::iterator iterator = std::find(schedule_vector.begin(),schedule_vector.end()
                                                                                            ,*container_iterator);
            if(iterator!=schedule_vector.end()){
                throw EventAlreadyExists();
            }   
        }
        for (ContainerIterator container_iterator = container.begin(); container_iterator != container.end();++container_iterator){
                schedule_vector.resize(schedule_vector.size() + 1);
                schedule_vector.assign(1,*container_iterator);
        }   
    }
}