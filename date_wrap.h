#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

#include "date.h"

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
        bool operator==(const DateWrap& date2) const;
        bool operator==(const DateWrap& date2) const;
        bool operator>(const DateWrap& date2) const;
        bool operator<(const DateWrap& date2) const;
        bool operator>=(const DateWrap& date2) const;
        bool operator<=(const DateWrap& date2) const;
        bool operator!=(const DateWrap& date2) const;
        friend ostream& operator<<(ostream& os, const DateWrap& date);
};

DateWrap& operator+(const DateWrap& date,const int& days);
DateWrap& operator+(const int& days,const DateWrap& date);

#endif

