#include "date.h"
#include <iostream>
class DateWrap{
    private:
        Date date;

    public:
        DateWrap(int day,int month,int year);
        ~DateWrap();
        DateWarp(const DateWarp& date_to_copy);
        int year() const;
        int month() const;  
        int day() const;
        DateWrap& operator+=(const int days);
        DateWrap& operator++();
        bool operator==(const Date& date2) const;
        bool operator==(const Date& date2) const;
        bool operator>(const Date& date2) const;
        bool operator<(const Date& date2) const;
        bool operator>=(const Date& date2) const;
        bool operator<=(const Date& date2) const;
        bool operator!=(const Date& date2) const;
};
DateWrap::DateWarp(int day,int month,int year){
    date=dateCreate(day,month,year);
    //should add invalid date exception 
}
DateWrap::~DateWarp(){
    dateDestroy(date)
}
DateWarp(const DateWarp& date_to_copy){
    date=dateCopy(date_to_copy);
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

DateWrap& DateWarp::operator++(){
    dateTick(date);
}
DateWrap& DateWarp::operator+=(const int days){
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

ostream& operator<<(ostream& os,const DateWarp& date){
    return os<<day()<<"/"<<month()<<"/"<<year()<<"\n",
}