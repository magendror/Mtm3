#include "base_event.h"

namespace{
    participantList::participantList ():participants(0),students(new int[1]){
        }
    
    participantList::~participantList(){
            delete[] students;
    }
    
    bool participantList::add(int new_student){
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
    
    bool participantList::remove(int remove_student){
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
    baseEvent::baseEvent(mtm::DateWrap event_date,char* event_name):name(name.assign(event_name)),
                                                            date(event_date),list(){
    }
    baseEvent::~baseEvent(){}
    void baseEvent::registerParticipant(int new_student){
        if(list.add(new_student)==false){
            //student is already here
        }
    }
    void baseEvent::unregisterParticipant(int remove_student){
        if(list.remove(remove_student)==false){
            //student is not in the list
        }
    }
}