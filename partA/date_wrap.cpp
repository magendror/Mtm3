extern "C"{
    #include "date.h"
}
#include "date_wrap.h"
#include <iostream>
#include "exceptions.h"

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

namespace mtm{

    DateWrap::DateWrap(int day,int month,int year)
    try: date(dateCheck(day,month,year)){}
    catch (...) {
        throw;
    }
    Date DateWrap::dateCheck(int day,int month,int year){
        if(day>30||day<1||month>12||month<1||year<0){
            throw mtm::InvalidDate();
        }
        return dateCreate(day,month,year);
    }

    DateWrap::~DateWrap(){
        dateDestroy(date);
    }

    DateWrap::DateWrap(const DateWrap& date_to_copy):
        date(dateCreate(date_to_copy.day(),date_to_copy.month(),date_to_copy.year())){
    }

    DateWrap& DateWrap::operator=(const DateWrap& date_to_copy){
        if (this == &date_to_copy) {
		    return *this;
	    }
        dateDestroy(date);
        date = dateCreate(date_to_copy.day(),date_to_copy.month(),date_to_copy.year());
        return *this;

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

    DateWrap DateWrap::operator++(int){
        DateWrap temp(*this);
        dateTick(date);
        return temp;
    }
    DateWrap& DateWrap::operator+=(const int days){
        if (days<0)
        {
            throw NegativeDays();  
        }
        for(int i=0;i<days;i++){
            dateTick(date);
        }
        return *this;
    }

    bool DateWrap::operator==(const DateWrap& date_wrap2) const{
        if(dateCompare(date,date_wrap2.date)==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool DateWrap::operator<(const DateWrap& date_wrap2) const {
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
        if((*this>date_wrap2)||(*this==date_wrap2)){
            return true;
        }
        else{
            return false;
        }
    }

    bool DateWrap::operator<=(const DateWrap& date_wrap2) const{
        if((*this<date_wrap2)||(*this==date_wrap2)){
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
        return os<<date.day()<<"/"<<date.month()<<"/"<<date.year();
    }

    DateWrap operator+(const DateWrap& date_wrap,const int& days){
        if (days<0)
        {
            throw NegativeDays();  
        }
        DateWrap new_date = DateWrap(date_wrap);
        new_date+=days;
        return new_date;
    }

    DateWrap operator+(const int& days,const DateWrap& date_wrap) {
        if (days<0)
        {
            throw NegativeDays();  
        }
        DateWrap new_date = DateWrap(date_wrap);
        new_date+=days;
        return new_date;
    }

}