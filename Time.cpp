#include "Time.h"
using namespace std;
Time::Time() {};
Time::Time(int minute, int hour, int day,int month,int year)
{
	this->minute = minute;
	this->hour = hour;
	this->day = day;
	this->month = month;
	this->year = year;
}
int Time::getMinute()
{
	return this->minute;
}
int Time::getHour()
{
	return this->hour;
}
int Time::getDay()
{
	return this->day;
}
int Time::getmonth()
{
	return this->month;
}
int Time::getyear()
{
	return this->year;
}
void Time::setMinute(int minute)
{
	this->minute = minute;
}
void Time::setHour(int hour)
{
	this->hour = hour;
}
void Time::setDay(int day)
{
	this->day = day;
}
void Time::setmonth(int month)
{
	this->month = month;
}
void Time::setyear(int year)
{
	this->year = year;
}