#include "base_event.h"

namespace mtm{
////////////////////////////////////////studentList/////////////////////////////////////////////////////
    int const MAX_STUDENT=1234567890;
    int const MIN_STUDENT=0;
    int const FIRST_NAME_GREATER=1;
    int const SECOND_NAME_GREATER=-1;
    int const SAME_NAME=0;

    StudentList::StudentList ():participants(0),students(new int[1]){
        }
    
    StudentList::~StudentList(){
        delete[] students;
    }
    
    StudentList::StudentList(const StudentList& to_clone){
        participants = to_clone.participants;
        students = new int[participants];
        for (int i=0;i<participants;i++){
            students[i]=to_clone.students[i];
        }
    }

    bool StudentList::add(const int new_student){
        if((new_student>=MAX_STUDENT)||(new_student<=MIN_STUDENT)){
            throw InvalidStudent();
        }
        if(this->contains(new_student)==true){
            return false;
        }
        participants++;
        int* temp = new int[participants];
        temp[0]=new_student;
        for (int i=0; i<participants-1; i++){
            temp[i+1]=students[i];
        }
        delete[] students;
        students = temp;
        bubbleSort(students,participants);
        return true;
    }

    bool StudentList::operator==(const StudentList& list2) const{
        if(participants!=list2.participants){
            return false;
        }
        for(int i=0;i<participants;i++){
            if(this->contains(list2.students[i])==false){
                return false;
            }
        }
        return true;
    }

    bool StudentList::remove(const int remove_student){
        if(this->contains(remove_student)==false){
            return false;
        }
        participants--;
        int* temp = new int[participants];
        for (int i=0,k=0; i<participants+1; i++){
            if (students[i]!=remove_student){
                temp[k]=students[i];
                k++;
            }
        }
        delete[] students;
        students = temp;
        return true;
    }
    
    bool StudentList::contains(int check_student) const {
        for (int i=0;i<participants;i++){
            if(students[i]==check_student){
                return true;
            }
        }
        return false;
    }

    void StudentList::printList(ostream& os) const{
        for(int i=0;i<participants;i++){
        os<<students[i]<<endl;
        }
    }

    StudentList& StudentList::operator=(const StudentList& list2){
        if(this==&list2){
            return *this;
        }
        participants=list2.participants;
        int* temp_students= new int[list2.participants];
        for(int i=0;i<participants;i++){
            temp_students[i]=list2.students[i];
        }
        delete[] students;
        students=temp_students;
        return *this;
    }

    void StudentList::swap(int *xp, int *yp){ 
        int temp = *xp; 
        *xp = *yp; 
        *yp = temp; 
    } 
  
    void StudentList::bubbleSort(int arr[], int n){ 
        int i, j; 
        bool swapped; 
        for (i = 0; i < n-1; i++){ 
            swapped = false; 
            for (j = 0; j < n-i-1; j++){ 
                if (arr[j] > arr[j+1]){ 
                    swap(&arr[j], &arr[j+1]); 
                    swapped = true; 
                } 
            } 
            if (swapped == false){ 
                break;
            } 
        } 
    }
    
////////////////////////////////////////BaseEvent////////////////////////////////////////////////

    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const char* event_name)try: name(assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList()){}
                                                                catch(mtm::Exception&){
                                                                        throw;
                                                                }
    
    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const char* event_name,const StudentList event_list)try:
                                                            name(assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList(event_list)){}
                                                            catch(mtm::Exception&){
                                                                        throw;
                                                            }
    
    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const std::string event_name)try:name(event_name),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList()){}
                                                            catch(mtm::Exception&){
                                                                        throw;
                                                            }

    BaseEvent::BaseEvent(const mtm::DateWrap event_date,const std::string event_name,const StudentList event_list)try:
                                                            name(event_name),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(mtm::StudentList(event_list)){}
                                                            catch(mtm::Exception&){
                                                                throw;
                                                            }
    BaseEvent::~BaseEvent(){}

    std::string BaseEvent::assign(const char* event_name){
        std::string new_name;
        new_name.assign(event_name);
        return new_name;
    }

    void BaseEvent::registerParticipant(const int new_student){
        if((new_student>=1234567890)||(new_student<=0)){
            throw InvalidStudent();
        }
        if(list.add(new_student)==false){
            throw AlreadyRegistered();
        }
    }

    void BaseEvent::unregisterParticipant(const int remove_student){
        if((remove_student>=1234567890)||(remove_student<=0)){
            throw InvalidStudent();
        }
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

    bool BaseEvent::operator<(const BaseEvent& event2) const{
        if(date<event2.date){
            return true;
        }
        else if (date>event2.date){
            return false;
        }
        else {
            return name<event2.name;
        }
    }

    bool BaseEvent::operator>(const BaseEvent& event2) const{
        if(date>event2.date){
            return true;
        }
        else if (date<event2.date){
            return false;
        }
        else {
            return name>event2.name;
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

    int BaseEvent::nameCompare(const BaseEvent& event2)const{
        if(name>event2.name){
            return FIRST_NAME_GREATER;
        }
        else if (name<event2.name){
            return SECOND_NAME_GREATER;
        }
        else{
            return SAME_NAME;
        }
    }

    int BaseEvent::nameCompare(const char* name2) const{
        std::string temp = name2;
        if(name>temp){
            return FIRST_NAME_GREATER;
        }
        else if (name<temp){
            return SECOND_NAME_GREATER;
        }
        else{
            return SAME_NAME;
        }
    }

    BaseEvent& BaseEvent::operator=(const BaseEvent& event2){
        if (this == &event2) {
		    return *this;
	    }
        name=event2.name;
        date=event2.date;
        list=event2.list;
        return *this;
    }
}
