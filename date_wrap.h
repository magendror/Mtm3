#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_

extern "C"{
    #include "date.h"
}
#include <iostream>

using std::ostream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

namespace mtm{

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
            DateWrap& operator=(const DateWrap& date_to_copy);
            bool operator==(const DateWrap& date_wrap2) const;
            bool operator>(const DateWrap& date_wrap2) const;
            bool operator<(const DateWrap& date_wrap2) const;
            bool operator>=(const DateWrap& date_wrap2) const;
            bool operator<=(const DateWrap& date_wrap2) const;
            bool operator!=(const DateWrap& date_wrap2) const;
            friend ostream& operator<<(ostream& os, const DateWrap& date);
    };

    DateWrap operator+(const DateWrap& date,const int& days);
    DateWrap operator+(const int& days,const DateWrap& date);

}

#endif

