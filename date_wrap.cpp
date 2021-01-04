#include "date.h"
class DateWrap{
    private:
        Date date;

    public:
        int year() const;
        int month() const;  
        int day() const;
        bool operator==(const Date& date2) const;
        bool operator>(const Date& date2) const;
        bool operator<(const Date& date2) const;
        bool operator>=(const Date& date2) const;
        bool operator<=(const Date& date2) const;
};

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