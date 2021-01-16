#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include <iostream>
#include "date_wrap.h"
#include "base_event.h"

namespace mtm{
    template <class CanRegister>
    class CustomEvent : public BaseEvent
    {
    private:
        CanRegister register_key;
    public:
        CustomEvent(const mtm::DateWrap event_date,const char* event_name,CanRegister register_func);
        CustomEvent(const mtm::DateWrap event_date,const char* event_name,StudentList event_list,CanRegister register_func);
        ~CustomEvent();
        void registerParticipant(const int new_student) override;
        CustomEvent* clone() const override;
    };

    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const char* event_name,CanRegister register_func):
                                                        mtm::BaseEvent(event_date,event_name),register_key(register_func){}

    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const char* event_name,StudentList event_list,CanRegister register_func):
                                                mtm::BaseEvent(event_date,event_name,event_list),register_key(register_func){}
    template <class CanRegister>
    CustomEvent<CanRegister>::~CustomEvent(){}

    template <class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(const int new_student){
        if((new_student>200000)||(new_student<=0)){
            throw RegistrationBlocked();
        }
        if (register_key(new_student)==true){
            if(list.add(new_student)==false){
                throw AlreadyRegistered();
            }
        }
        else{
            throw RegistrationBlocked();
        }
    }
    
    template <class CanRegister>
    CustomEvent<CanRegister>* CustomEvent<CanRegister>::clone() const{
        CustomEvent<CanRegister>* copy_of_event = new CustomEvent<CanRegister>(date,name.c_str(),list,register_key);
        return copy_of_event;
    }

}


#endif