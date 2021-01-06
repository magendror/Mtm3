#include "date.h"
#include "date_wrap.h"
#include <iostream>

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;



DateWrap::DateWrap(int day,int month,int year):
    date(dateCreate(day,month,year)){
    //should add invalid date exception 
}
DateWrap::~DateWrap(){
    dateDestroy(date);
}
//problem because of const!!
DateWrap::DateWrap(const DateWrap& date_to_copy){
    DateWrap(date_to_copy.day(),date_to_copy.month(),date_to_copy.year());
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
bool DateWrap::operator==(const DateWrap& date_wrap2) const{
    if(dateCompare(date,date_wrap2.date)==0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator<(const DateWrap& date_wrap2) const{
    if(dateCompare(date,date_wrap2.date)<0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator>(const DateWrap& date_wrap2) const{
    if(dateCompare(date,date_wrap2.date)>0){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator>=(const DateWrap& date_wrap2) const{
    if(date>date_wrap2.date||date==date_wrap2.date){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator<=(const DateWrap& date_wrap2) const{
    if(date<date_wrap2.date||date==date_wrap2.date){
        return true;
    }
    else{
        return false;
    }
}

bool DateWrap::operator!=(const DateWrap& date_wrap2) const{
    return !(date==date_wrap2.date);
}
//need to add to public with a friend
ostream& operator<<(ostream& os,const DateWrap& date){
    return os<<date.day()<<"/"<<date.month()<<"/"<<date.year()<<"\n";
}

DateWrap& operator+(const DateWrap& date_wrap,const int& days){
    DateWrap new_date(date_wrap);
    new_date+=days;
    return new_date;
}

DateWrap& operator+(const int& days,const DateWrap& date_wrap) {
    DateWrap new_date(date_wrap);
    new_date+=days;
    return new_date;
}