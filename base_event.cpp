#include "base_event.h"

namespace mtm{
////////////////////////////////////////studentList////////////////////////////////////////////////
    StudentList::StudentList ():participants(0),students(new int[1]){
        }
    
    StudentList::~StudentList(){
        delete[] students;
    }
    
    StudentList::StudentList(const StudentList& to_clone){
        participants = to_clone.participants;
        int* students = new int[participants];
        for (int i=0;i<participants;i++){
            students[i]=to_clone.students[i];
        }
    }

    bool StudentList::add(const int new_student){
        if(this->contains(new_student)==true){
            return false;
        }
        participants++;
        int* temp = new int[participants];
        for (int i=0; i<participants-1; i++){
            temp[i]=students[i];
        }
        delete[] students;
        students = temp;
        students[participants-1]=new_student;
        return true;
    }
    
    bool StudentList::remove(const int remove_student){
        if(this->contains(remove_student)==false){
            return false;
        }
        participants--;
        int* temp = new int[participants];
        for (int i=0,k=0; i<participants; i++){
            if (students[i]!=remove_student){
                temp[k]=students[i];
                k++;
            }
        }
        delete[] students;
        students = temp;
        return true;
    }

    bool StudentList::contains(const int check_student){
        for (int i=0;i<participants;i++){
            if(students[i]==check_student){
                return true;
            }
        }
        return false;
    }

    void StudentList::printList(ostream& os) const{
        for(int i=0;i<participants;i++)
        os<<students[i]<<endl;
    }
////////////////////////////////////////BaseEvent////////////////////////////////////////////////

    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const char* event_name):name(assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList()){
    }
    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const char* event_name,const StudentList event_list):
                                                            name(name.assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList(event_list)){
    }

    BaseEvent::~BaseEvent(){}

    std::string BaseEvent::assign(const char* event_name){
        std::string new_name;
        new_name.assign(event_name);
        return new_name;
    }

    void BaseEvent::registerParticipant(const int new_student){
        if((new_student>200000)||(new_student<=0)){
            throw RegistrationBlocked();
        }
        if(list.add(new_student)==false){
            throw AlreadyRegistered();
        }
    }

    void BaseEvent::unregisterParticipant(const int remove_student){
        if(list.remove(remove_student)==false){
            throw NotRegistered();
        }
    }

    void BaseEvent::printShort(ostream& os) const {
        os<<name<<" "<<date<<endl;
    }
    void BaseEvent::printLong(ostream& os) const {
        os<<name<<" "<<date<<endl;
        list.printList(os);
    }

    /*BaseEvent* BaseEvent::clone() const{
        baseEvent copy_event(date,name.c_str(),list);
        return &copy_event;
    }*/

    bool BaseEvent::operator<(const BaseEvent& event2) const{
        if(date<event2.date){
            return true;
        }
        else{
            return false;
        }
    }

    bool BaseEvent::operator>(const BaseEvent& event2) const{
        if(date>event2.date){
            return true;
        }
        else{
            return false;
        }
    }
    bool BaseEvent::sameDate(const mtm::DateWrap date2) const{
        if(date==date2){
            return true;
        }
        else{
            return false;
        }
        
    }
    bool BaseEvent::operator==(const BaseEvent& event2) const{
        return((date==event2.date)&&(name==event2.name));
    }

    int BaseEvent::nameCompare(BaseEvent& event2){
        if(name>event2.name){
            return 1;
        }
        else if (name<event2.name){
            return -1;
        }
        else{
            return 0;
        }
    }
}
