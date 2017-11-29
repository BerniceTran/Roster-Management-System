// Date.cpp

#include "Date.h"
#include <iostream>
using namespace std;

// Initializes a date to the default value of January 1, 1970
Date::Date() {
    month = 1;
    day = 1;
    year = 1970;
}

// Initializes a date to the values in the parameters.  If the
// date is not legal, sets the date to 1 of the illegal value.
// (Illegal years are set to 2000)
Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
    //adjust();
}

// Returns the month stored by the class
string Date::getMonth() const {
    if (month == 1)
        return "January";
    if (month == 2)
        return "February";
    if (month == 3)
        return "March";
    if (month == 4)
        return "April";
    if (month == 5)
        return "May";
    if (month == 6)
        return "June";
    if (month == 7)
        return "July";
    if (month == 8)
        return "August";
    if (month == 9)
        return "September";
    if (month == 10)
        return "October";
    if (month == 11)
        return "November";
    return "December";
}

ostream& operator<<(ostream& os, const Date& rhs)
{
    os << rhs.month << "/" << rhs.day << "/" << rhs.year;
    return os;
}

istream& operator>>(istream& is, Date& rhs)
{
    cout << "\tPlease enter the month: ";
    is >> rhs.month;
    cout << "\tPlease enter the day: ";
    is >> rhs.day;
    cout << "\tPlease enter the year: ";
    is >> rhs.year;
    return is;
}