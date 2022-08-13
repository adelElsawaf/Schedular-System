#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <sstream>
#include"Event.h"
#include <vector>
#include <algorithm>
#include<fstream>
#include <ctime>
using namespace std;
void menu()
{
	cout << "please enter you choice " << endl;
	cout << "Press <1> to Create an event" << endl;
	cout << "press <2> to Display an event" << endl;
	cout << "press <3> to Display all events" << endl;
	cout << "press <4> to Update an event" << endl;
	cout << "press <5> to delete event" << endl;
	cout << "press <6> to delete all events " << endl;
	cout << "press <7> to show the upcoming event " << endl;
	cout << "press <8> to exit " << endl;
}
void loadData(string fileLocation)
{
	ifstream readData;
	string rowInfo;
	readData.open(fileLocation);
	vector<string> data;
	while (getline(readData, rowInfo, ','))
	{

		data.push_back(rowInfo);

	}
	if (data.empty())
	{
		for (int vecIndex = 0; vecIndex < data.size(); vecIndex += 18)
		{
			Time statrT = Time(stoi(data[vecIndex + 3]), stoi(data[vecIndex + 4]), stoi(data[vecIndex + 5]), stoi(data[vecIndex + 6]), stoi(data[vecIndex + 7]));
			Time endT = Time(stoi(data[vecIndex + 8]), stoi(data[vecIndex + 9]), stoi(data[vecIndex + 10]), stoi(data[vecIndex + 11]), stoi(data[vecIndex + 12]));
			Time reminderT = Time(stoi(data[vecIndex + 13]), stoi(data[vecIndex + 14]), stoi(data[vecIndex + 15]), stoi(data[vecIndex + 16]), stoi(data[vecIndex + 17]));
			Event obj = Event(data[vecIndex], data[vecIndex + 1], data[vecIndex + 2], statrT, endT, reminderT);
			Event::allEvents.push_back(obj);
		}
	}
	else
	{
		for (int vecIndex = 0; vecIndex < data.size() - 1; vecIndex += 18)
		{
			Time statrT = Time(stoi(data[vecIndex + 3]), stoi(data[vecIndex + 4]), stoi(data[vecIndex + 5]), stoi(data[vecIndex + 6]), stoi(data[vecIndex + 7]));
			Time endT = Time(stoi(data[vecIndex + 8]), stoi(data[vecIndex + 9]), stoi(data[vecIndex + 10]), stoi(data[vecIndex + 11]), stoi(data[vecIndex + 12]));
			Time reminderT = Time(stoi(data[vecIndex + 13]), stoi(data[vecIndex + 14]), stoi(data[vecIndex + 15]), stoi(data[vecIndex + 16]), stoi(data[vecIndex + 17]));
			Event obj = Event(data[vecIndex], data[vecIndex + 1], data[vecIndex + 2], statrT, endT, reminderT);
			Event::allEvents.push_back(obj);
		}
	}
}
int main()
{
	time_t currentTime = time(0);
	tm* now = localtime(&currentTime);
	string eventName, eventPlace, eventDesicription;
	int timeMinute, timeHour, timeDay, timeMonth, timeYear;
	ofstream writeInEventsFile;
	loadData("eventdata.csv");
	while (true)
	{
		menu();
		Time nowTime = Time(now->tm_min, now->tm_hour, now->tm_mday, now->tm_mon, now->tm_year);
		Event::sort();
		Event::deleteDoneEvents(Event::calculateTotalMinutes(nowTime));
		/*if (Event::read(nowTime) == -1)
		{
			cout << "there is no upcoming events now " <<endl;
		}
		else
		{
			Event::showEvent(Event::read(nowTime));
		}*/
		for (int i = 0; i < Event::allEvents.size(); i++) {

			if (Event::isEqualTime(nowTime, Event::allEvents[i].getReminderTime()))
			{
				cout << "YOU HAVE AN EVENT" << Event::allEvents[i].getName() << " AFTER 30 MINUTES " << endl;

			}
		}
		int operationChoice;
		cin >> operationChoice;
		if (operationChoice == 1)
		{
			cout << "please enter the event name" << endl;
			cin >> eventName;
			cout << "please enter the event place :" << endl;
			cin >> eventPlace;
			cout << "please enter the event discription" << endl;
			cin >> eventDesicription;
			cout << "enter event Start date" << endl;
			cout << "enter start minute";
			cin >> timeMinute;
			cout << "enter start Hour" << endl;
			cin >> timeHour;
			cout << "enter start Day" << endl;
			cin >> timeDay;
			cout << "enter start month" << endl;
			cin >> timeMonth;
			cout << "enter start Year" << endl;
			cin >> timeYear;
			Time startTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			cout << "enter event end time" << endl;
			cout << "enter end minute" << endl;
			cin >> timeMinute;
			cout << "enter end Hour" << endl;
			cin >> timeHour;
			cout << "enter end Day" << endl;
			cin >> timeDay;
			cout << "enter end month" << endl;
			cin >> timeMonth;
			cout << "enter end Year" << endl;
			cin >> timeYear;
			Time endTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			Time reminderTime = Time(Event::changeReminder(startTime).getMinute(), Event::changeReminder(startTime).getHour(), Event::changeReminder(startTime).getDay(), Event::changeReminder(startTime).getmonth(), Event::changeReminder(startTime).getyear());
			Event::createEvent(Event(eventName, eventPlace, eventDesicription, startTime, endTime, reminderTime));
		}
		else if (operationChoice == 2)
		{
			cout << "enter event Start date" << endl;
			cout << "enter start minute";
			cin >> timeMinute;
			cout << "enter start Hour" << endl;
			cin >> timeHour;
			cout << "enter start Day" << endl;
			cin >> timeDay;
			cout << "enter start month" << endl;
			cin >> timeMonth;
			cout << "enter start Year" << endl;
			cin >> timeYear;
			Time startTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			int index = Event::read(startTime);
			Event::showEvent(index);
		}
		else if (operationChoice == 3)
		{
			Event::showAll();
		}
		else if (operationChoice == 4)
		{
			cout << "please enter the event time you want to update" << endl;
			cout << "enter start minute";
			cin >> timeMinute;
			cout << "enter start Hour" << endl;
			cin >> timeHour;
			cout << "enter start Day" << endl;
			cin >> timeDay;
			cout << "enter start month" << endl;
			cin >> timeMonth;
			cout << "enter start Year" << endl;
			cin >> timeYear;
			Time oldEventStartTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			cout << "plz enter new event data" << endl;
			cout << "enter event name" << endl;
			cin >> eventName;
			cout << "enter event place" << endl;
			cin >> eventPlace;
			cout << "enter event description" << endl;
			cin >> eventDesicription;
			cout << "enter event start time" << endl;
			cout << "enter start minute" << endl;
			cin >> timeMinute;
			cout << "enter start Hour" << endl;
			cin >> timeHour;
			cout << "enter start Day" << endl;
			cin >> timeDay;
			cout << "enter start month" << endl;
			cin >> timeMonth;
			cout << "enter start Year" << endl;
			cin >> timeYear;
			Time startTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			cout << "enter event end time" << endl;
			cout << "enter end minute" << endl;
			cin >> timeMinute;
			cout << "enter end Hour" << endl;
			cin >> timeHour;
			cout << "enter end Day" << endl;
			cin >> timeDay;
			cout << "enter end month" << endl;
			cin >> timeMonth;
			cout << "enter end Year" << endl;
			cin >> timeYear;
			Time endTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			Event::update(oldEventStartTime, Event(eventName, eventPlace, eventDesicription, startTime, endTime, endTime));
		}
		else if (operationChoice == 5)
		{
			cout << "enter event Start date" << endl;
			cout << "enter start minute";
			cin >> timeMinute;
			cout << "enter start Hour" << endl;
			cin >> timeHour;
			cout << "enter start Day" << endl;
			cin >> timeDay;
			cout << "enter start month" << endl;
			cin >> timeMonth;
			cout << "enter start Year" << endl;
			cin >> timeYear;
			Time startTime = Time(timeMinute, timeHour, timeDay, timeMonth, timeYear);
			int index = Event::read(startTime);
			Event::deleteEvent(index);
		}
		else if (operationChoice == 6)
		{
			Event::deleteAll();
		}
		else if (operationChoice == 7)
		{
			Event::showEvent(0);
		}
		else if (operationChoice == 8)
		{
			writeInEventsFile.open("eventdata.csv");
			int numberOfEvents = Event::allEvents.size();
				for (int i = 0; i < numberOfEvents; i++)
			{
				writeInEventsFile << Event::allEvents[i].getName() << ',' + Event::allEvents[i].getPlace() << ',' << Event::allEvents[i].getDescription() << ',' <<
					to_string(Event::allEvents[i].getStartTime().getMinute()) << ',' << to_string(Event::allEvents[i].getStartTime().getHour()) << ',' <<
					to_string(Event::allEvents[i].getStartTime().getDay()) << ',' << to_string(Event::allEvents[i].getStartTime().getmonth()) << ','
					<< to_string(Event::allEvents[i].getStartTime().getyear()) << ',' <<
					to_string(Event::allEvents[i].getEndTime().getMinute()) << ',' << to_string(Event::allEvents[i].getEndTime().getHour()) << ',' <<
					to_string(Event::allEvents[i].getEndTime().getDay()) << ',' << to_string(Event::allEvents[i].getEndTime().getmonth()) <<
					',' << to_string(Event::allEvents[i].getEndTime().getyear()) << ',' <<
					to_string(Event::allEvents[i].getReminderTime().getMinute()) << ',' << to_string(Event::allEvents[i].getReminderTime().getHour()) << ',' <<
					to_string(Event::allEvents[i].getReminderTime().getDay()) << ',' << to_string(Event::allEvents[i].getReminderTime().getmonth()) << ',' <<
					to_string(Event::allEvents[i].getReminderTime().getyear()) << ',';
			}
			writeInEventsFile.close();
			break;
		}
	}
}