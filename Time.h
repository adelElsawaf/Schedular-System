#pragma once
#include <string>
using namespace std;
class Time
{
private:
	int minute;
	int hour;
	int day;
	int month;
	int year;
public:
	Time();
	Time(int minute,int hour , int day,int month,int year);
	int getMinute();
	int getHour();
	int getDay();
	int getmonth();
	int getyear();
	void setMinute(int minute);
	void setHour(int hour);
	void setDay(int day);
	void setmonth(int month);
	void setyear(int year);
};

