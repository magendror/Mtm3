#include "date_wrap.h"
#include "exceptions.h"
#include <iostream>
using mtm::DateWrap;
using std::cout;
using std::endl;

template <class T> void print(const T& x) { cout << x << endl; }

int main() {
    DateWrap date(30, 11, 2020);
    print(date);
    print(date + 4);
    print(3 + date);
    date++;
    print(date);
    date += 7;
    print(date);
    print(date > DateWrap(29, 11, 2020));
    print(date <= DateWrap(29, 11, 2020));
    print(date == DateWrap(30, 11, 2020));
    print(date == DateWrap(8, 12, 2020));
    date=DateWrap(30, 11, 2020);
    DateWrap copy(date);
    copy++;
    print(copy);
    cout<<copy<<" or "<<date<<endl;
    try {
        date += (-3);
    } catch (mtm::NegativeDays& e) {
        print("NegativeDays");
    }
    try {
        date = date + (-3);
    } catch (mtm::NegativeDays& e) {
        print("NegativeDays");
    }
    try {
        date = date + 1 + (-3);
    } catch (mtm::NegativeDays& e) {
        print("NegativeDays");
    }
    return 0;
}
