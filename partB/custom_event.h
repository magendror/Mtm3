#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include <iostream>
#include "../partA/date_wrap.h"
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
        CustomEvent(const mtm::DateWrap event_date,const std::string event_name,CanRegister register_func);
        CustomEvent(const mtm::DateWrap event_date,const std::string event_name,StudentList event_list,CanRegister register_func);
        ~CustomEvent();
        void registerParticipant(const int new_student) override;
        CustomEvent* clone() const override;
        CustomEvent<CanRegister>& operator=(const CustomEvent<CanRegister>& event2);
    };

    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const char* event_name,CanRegister register_func)try:
                                                        mtm::BaseEvent(event_date,event_name),register_key(register_func){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const char* event_name,StudentList event_list,CanRegister register_func)try:
                                                mtm::BaseEvent(event_date,event_name,event_list),register_key(register_func){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const std::string event_name,CanRegister register_func)try:
                                                        mtm::BaseEvent(event_date,event_name),register_key(register_func){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(const mtm::DateWrap event_date,const std::string event_name,StudentList event_list,CanRegister register_func)try:
                                                mtm::BaseEvent(event_date,event_name,event_list),register_key(register_func){}
                                                catch(mtm::Exception&){
                                                    throw;
                                                }
    
    template <class CanRegister>
    CustomEvent<CanRegister>::~CustomEvent(){}

    template <class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(const int new_student){
        if((new_student>=1234567890)||(new_student<=0)){
            throw InvalidStudent();
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
    template <class CanRegister>
        CustomEvent<CanRegister>& CustomEvent<CanRegister>::operator=(const CustomEvent<CanRegister>& event2){
        if (this == &event2) {
		    return *this;
	    }
        name=event2.name;
        date=event2.date;
        list=event2.list;
        register_key=event2.register_key;
        return *this;
    }

}


#endif