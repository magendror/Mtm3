#include "base_event.h"

namespace mtm{
////////////////////////////////////////ParticipantList////////////////////////////////////////////////
    participantList::participantList ():participants(0),students(new int[1]){
        }
    
    participantList::~participantList(){
        delete[] students;
    }
    
    participantList::participantList(const participantList& to_clone){
        participants = to_clone.participants;
        int* students = new int[participants];
        for (int i=0;i<participants;i++){
            students[i]=to_clone.students[i];
        }
    }

    bool participantList::add(const int new_student){
        for (int i=0; i<participants; i++){
            if (students[i]==new_student){
                return false;
            }
        }
        participants++;
        int* temp = new int[participants];
        for (int i=0; i<participants-1; i++){
            temp[i]=students[i];
        }
        delete[] students;
        students = temp;
        students[participants]=new_student;
        return true;
    }
    
    bool participantList::remove(const int remove_student){
        bool student_registered = false;
        for (int i=0; i<participants; i++){
            if (students[i]==remove_student){
                student_registered = true;
            }
        }
        if(student_registered==false){
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

    void participantList::printList(ostream& os) const{
        for(int i=0;i<participants;i++)
        os<<students[i]<<endl;
    }
////////////////////////////////////////BaseEvent////////////////////////////////////////////////

    baseEvent::baseEvent(const mtm::DateWrap event_date,const char* event_name):name(name.assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(){
    }
    baseEvent::baseEvent(const mtm::DateWrap event_date,const char* event_name,const participantList event_list):
                                                            name(name.assign(event_name)),
                                                            date(mtm::DateWrap(event_date)),
                                                            list(event_list){
    }

    baseEvent::~baseEvent(){}

    void baseEvent::registerParticipant(const int new_student){
        if(list.add(new_student)==false){
            //student is already here
        }
    }

    void baseEvent::unregisterParticipant(const int remove_student){
        if(list.remove(remove_student)==false){
            //student is not in the list
        }
    }

    void baseEvent::printShort(ostream& os) const {
        os<<name<<" "<<date;
    }
    void baseEvent::printLong(ostream& os) const {
        os<<name<<" "<<date<<endl;
        list.printList(os);
    }

    baseEvent* baseEvent::clone() const{/*
        baseEvent copy_event(date,name.c_str(),list);
        return &copy_event;*/
    }
}
