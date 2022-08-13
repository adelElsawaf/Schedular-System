#pragma once
#include <string>
#include <string.h>
#include "Time.h"
#include <vector>
using std::vector;
using namespace std;
class Event
{
private:
	string name;
	string place;
	string description;
	Time startTime;
	Time endTime;
	Time reminderTime;
	int totalMinutes;
public:
	static vector<Event>allEvents;
	static vector<Event>sortedEvents;
	Event(string name, string place, string description, Time startTime, Time endTime, Time reminderTime);
	Event();
	string getName();
	string getPlace();
	string getDescription();
	Time getStartTime();
	Time getEndTime();
	Time getReminderTime();
	int  getTotalMinutes();
	void setName(string name);
	void setPlace(string place);
	void setDescription(string description);
	void setStartTime(Time startTime);
	void setEndTime(Time endTime);
	void setReminderTime(Time reminderTime);
	void setTotalMinutes(int totalMinutes);
	static int read(Time startTime);
	static bool isEqualTime(Time first, Time second);
	static void update(Time startTime,Event newEvent);
	static void deleteAll();
	static void showEvent(int index);
	static void deleteEvent(int index);
	Time static changeReminder(Time startTime);
	void static createEvent(Event newEvent);
	bool static isSuitableTime(Time checkedTime);
	void static showAll();
	void static sort();
	static void deleteDoneEvents(int timeNowTotalMinutes);
	static int calculateTotalMinutes(Time startTime);
};

