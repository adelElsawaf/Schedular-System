#include "Event.h"
#include "Time.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
using std::vector;
std::vector<Event> Event::allEvents;
Event::Event(string name, string place, string description, Time startTime, Time endTime, Time reminderTime)
{
	this->name = name;
	this->place = place;
	this->description = description;
	this->startTime = startTime;
	this->endTime = endTime;
	this->reminderTime = reminderTime;
	this->totalMinutes = Event::calculateTotalMinutes(startTime);
}
Event::Event() {}
string Event::getName()
{
	return this->name;
}
string Event::getPlace()
{
	return this->place;
}
string Event::getDescription()
{
	return this->description;
}
Time Event::getStartTime()
{
	return this->startTime;
}
Time Event::getEndTime()
{
	return this->endTime;
}
Time Event::getReminderTime()
{
	return this->reminderTime;
}
int Event::getTotalMinutes()
{
	return this->totalMinutes;
}
void Event::setTotalMinutes(int totalMinutes)
{
	this->totalMinutes = totalMinutes;
}
void Event::setName(string name)
{
	this->name = name;
}
void Event::setPlace(string place)
{
	this->place = place;
}
void Event::setDescription(string description)
{
	this->description = description;
}
void Event::setStartTime(Time startTime)
{
	this->startTime = startTime;
}
void Event::setEndTime(Time endTime)
{
	this->endTime = endTime;
}
void Event::setReminderTime(Time reminderTime)
{
	this->reminderTime = reminderTime;
}
bool Event::isEqualTime(Time first, Time second)
{
	return (first.getMinute() == second.getMinute() && first.getHour() == second.getHour() && first.getDay() == second.getDay() && first.getyear() == second.getyear());
}
int Event::read(Time startTime)
{
	int numberOfEvents = Event::allEvents.size();
	for (int index = 0; index < numberOfEvents; index++)
	{
		if (allEvents[index].isEqualTime(allEvents[index].getStartTime(), startTime))
		{
			return index;
		}

	}
	return -1;
}
void Event::deleteAll()
{
	allEvents.clear();
}
void Event::update(Time startTime, Event newEvent)
{
	int eventIndex = read(startTime);
	allEvents[eventIndex].setName(newEvent.getName());
	allEvents[eventIndex].setPlace(newEvent.getPlace());
	allEvents[eventIndex].setDescription(newEvent.getDescription());
	allEvents[eventIndex].setStartTime(newEvent.getStartTime());
	allEvents[eventIndex].setEndTime(newEvent.getEndTime());
	allEvents[eventIndex].setReminderTime(newEvent.getReminderTime());
}
void Event::showEvent(int dataIndex)
{
	cout << "event name :" << Event::allEvents[dataIndex].getName() << endl;
	cout << "event place :" << Event::allEvents[dataIndex].getPlace() << endl;
	cout << "event discreption :" << Event::allEvents[dataIndex].getDescription() << endl;
	cout << "event start time :" << Event::allEvents[dataIndex].getStartTime().getMinute() << '-' <<
		Event::allEvents[dataIndex].getStartTime().getHour() << '-' <<
		Event::allEvents[dataIndex].getStartTime().getDay() << '-' <<
		Event::allEvents[dataIndex].getStartTime().getmonth() << '-' <<
		Event::allEvents[dataIndex].getStartTime().getyear() << endl;

	cout << "event end time :" << Event::allEvents[dataIndex].getEndTime().getMinute() << '-' <<
		Event::allEvents[dataIndex].getEndTime().getHour() << '-' <<
		Event::allEvents[dataIndex].getEndTime().getDay() << '-' <<
		Event::allEvents[dataIndex].getEndTime().getmonth() << '-' <<
		Event::allEvents[dataIndex].getEndTime().getyear() << endl;

	cout << "event Reminder time :" << Event::allEvents[dataIndex].getReminderTime().getMinute() << '-' <<
		Event::allEvents[dataIndex].getReminderTime().getHour() << '-' <<
		Event::allEvents[dataIndex].getReminderTime().getDay() << '-' <<
		Event::allEvents[dataIndex].getReminderTime().getmonth() << '-' <<
		Event::allEvents[dataIndex].getReminderTime().getyear() << endl;
}
void Event::showAll()
{
	for (int i = 0; i < Event::allEvents.size(); i++)
	{
		showEvent(i);
	}
}
void Event::deleteEvent(int index)
{
	Event::allEvents.erase(Event::allEvents.begin() + index);
}
Time Event::changeReminder(Time reminder)
{
	if (reminder.getMinute() < 30) {
		reminder.setHour(reminder.getHour() - 1);
		reminder.setMinute(reminder.getMinute() + 30);
	}
	return reminder;
}
bool Event::isSuitableTime(Time checkedTime)
{
	for (int i = 0; i < Event::allEvents.size(); i++)
	{
		Time startTime = allEvents[i].getStartTime();
		Time endTime = allEvents[i].getEndTime();
		if (startTime.getyear() < checkedTime.getyear() && endTime.getyear() > checkedTime.getyear())
			return false;
		if (startTime.getmonth() < checkedTime.getmonth() && endTime.getmonth() > checkedTime.getmonth())
			return false;
		if (startTime.getDay() < checkedTime.getDay() && endTime.getDay() > checkedTime.getDay())
			return false;
		if (startTime.getHour() < checkedTime.getHour() && endTime.getHour() > checkedTime.getHour())
			return false;
	}
	return true;
}
void Event::createEvent(Event newEvent) {
	if (isSuitableTime(newEvent.getStartTime())) {
		cout << "herrrreee" << endl;
		allEvents.push_back(newEvent);
		cout << allEvents[0].getStartTime().getMinute();
	}
}
int Event::calculateTotalMinutes(Time startTime)
{
	return (startTime.getMinute() + (startTime.getHour() * 60) + (startTime.getDay() * 24 * 60) + (startTime.getmonth() * 30 * 24 * 60));
}
void Event:: sort()
{
	for (int i = 0; i < Event::allEvents.size(); i++)
	{
		for (int j = i+1; j < Event::allEvents.size(); j++)
		{
			if (Event::allEvents[j].getTotalMinutes() < Event::allEvents[i].getTotalMinutes())
				swap(Event::allEvents[i], Event::allEvents[j]);
		}

	}

}
void Event::deleteDoneEvents(int timeNowTotalMinutes)
{
	for (int i = 0; i < Event::allEvents.size(); i++)
	{
		if (timeNowTotalMinutes > Event::allEvents[i].totalMinutes)
			Event::deleteEvent(i);
	}
}







