#include "base_event.h"

namespace{
    participantList::participantList ():participant(0),students(new int[1]){
        }
    
    participantList::~participantList(){
            delete[] students;
    }
    
    bool participantList::add(int new_student){
        for (int i=0; i<participant; i++){
            if (students[i]==new_student){
                return false;
            }
        }
        participant++;
        int* temp = new int[participant];
        for (int i=0; i<participant-1; i++){
            temp[i]=students[i];
        }
        delete[] students;
        students = temp;
        students[participant]=new_student;
        return true;
    }
    
    bool participantList::remove(int remove_student){
        bool student_registered = false;
        for (int i=0; i<participant; i++){
            if (students[i]==remove_student){
                student_registered = true;
            }
        }
        if(student_registered==false){
            return false;
        }
        participant--;
        int* temp = new int[participant];
        for (int i=0,k=0; i<participant; i++){
            if (students[i]!=remove_student){
                temp[k]=students[i];
                k++;
            }
        }
        delete[] students;
        students = temp;
        return true;
    }
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