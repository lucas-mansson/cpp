#include <ctime>  // time and localtime
#include <iostream>
#include <istream>
#include <ostream>
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std;

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if(day > daysPerMonth[month-1]){
		day = 1;
		month++;
		if(month > 12){
			month = 1;
			year++;
		}
	}
}

std::istream& operator>>(std::istream& is, Date& date){

	int y, m, d;
    char dash1, dash2;
    
    is >> y >> dash1 >> m >> dash2 >> d;
    
    if (is.fail() || dash1 != '-' || dash2 != '-' || m < 1 || m > 12 || d < 1 || d > date.daysPerMonth[m - 1]) {
        is.setstate(std::ios_base::failbit);  
    } else {
        date.year = y;
        date.month = m;
        date.day = d;
    }

	return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
	os << date.year << '-';

	if(date.month < 10){
		os << '0';
	}
	os << date.month << '-';
	
	if(date.day < 10){
		os << '0';
	}
	os << date.day;

	return os;
}

