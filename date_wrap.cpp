#include "date.h"
#include <iostream>
class DateWrap{
    private:
        Date date;

    public:
        DateWrap(int day,int month,int year);
        ~DateWrap();
        DateWrap(const DateWrap& date_to_copy);
        int year() const;
        int month() const;  
        int day() const;
        DateWrap& operator+=(const int days);
        DateWrap& operator++(int);
        bool operator==(const Date& date2) const;
        bool operator==(const Date& date2) const;
        bool operator>(const Date& date2) const;
        bool operator<(const Date& date2) const;
        bool operator>=(const Date& date2) const;
        bool operator<=(const Date& date2) const;
        bool operator!=(const Date& date2) const;
        bool operator+(const int& days) const;
};

DateWrap::DateWrap(int day,int month,int year):
    date(dateCreate(day,month,year)){
    //should add invalid date exception 
}
DateWrap::~DateWrap(){
    dateDestroy(date);
}
//problem because of const!!
DateWrap::DateWrap(const DateWrap& date_to_copy):
    date(dateCopy(date_to_copy)){
}
int DateWrap::year() const{
    int day,month,year;
    dateGet(date,&day,&month,&year);
    return year;
}
int DateWrap::month() const{
    int day,month,year;
    dateGet(date,&day,&month,&year);
    return month;
}    
int DateWrap::day() const{
    int day,month,year;
    dateGet(date,&day,&month,&year);
    return day;
}

DateWrap& DateWrap::operator++(int){
    dateTick(date);
    return *this;
}
DateWrap& DateWrap::operator+=(const int days){
    //should add exception 
    for(int i=0;i<days;i++){
        dateTick(date);
    }
}
bool DateWrap::operator==(const Date& date2) const{
    if(dateCompare(date,date2)==0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator<(const Date& date2) const{
    if(dateCompare(date,date2)<0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator>(const Date& date2) const{
    if(dateCompare(date,date2)>0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator>=(const Date& date2) const{
    if(date>date2||date==date2){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator<=(const Date& date2) const{
    if(date<date2||date==date2){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator!=(const Date& date2) const{
    return !(date==date2);
}
//need to add to public with a friend
ostream& operator<<(ostream& os,const DateWrap& date){
    return os<<day()<<"/"<<month()<<"/"<<year()<<"\n",
}

bool DateWrap::operator+(const int& days) const{
    Date new_date = dateCopy(date);
    for (int i=0;i<days;i++){
        dateTick(new_date);
    }
}