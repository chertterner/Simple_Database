#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;
class Database
{
	string events;
	string date;
	map<string,vector<string>>map_events_dates;
public:
	Database()
	{
		cout << "Commands in the database: \n\n";
		cout << "1.Add: date(day,month,year), event - adding a new event in the current date;\n";
		cout << "2.Del: date(day,month,year), event - delete event in the current date;\n";
		cout << "3.Del_all: date(day,month,year) - delete event in the current date;\n";
		cout << "4.Find: date(day,month,year) - find and print events in the current date;\n";
		cout << "5.Print - print all events;\n";
		cout << "6.Exit.\n\n ";
	}
	void Add_event_in_data()
	{
		cout << "Enter date\n";
		cin >> date;
		cout << "Enter event\n";
		cin >> events;
		map_events_dates[date].push_back(events);

	}
	void Del_event_in_data()
	{
		cout << "Enter date\n";
		cin >> date;
		cout << "Enter event\n";
		cin >> events;
		try
		{
			auto it = map_events_dates.find(date);
			if (it == map_events_dates.end())
			{
				throw runtime_error("Can't find date\n ");
			}
			auto it1 = find(it->second.begin(), it->second.end(), events);
			if (it1 != it->second.end())
			{
				it->second.erase(it1);
			}
			else
			{
				throw runtime_error("Can't find event\n ");
			}
		}
		catch (runtime_error&er)
		{
			cout << er.what();
		}
		
	}
	void Del_all_events_in_data()
	{
		cout << "Enter date\n";
		cin >> date;
		auto it = map_events_dates.find(date);
		if (it == map_events_dates.end())
		{
			cout << "Can't find date\n";
			return;
		}
		map_events_dates.erase(date);
	}
	void Find_date()
	{
		cout << "Enter date\n";
		cin >> date;
		auto it=map_events_dates.find(date);
		if (it == map_events_dates.end())
		{
			cout << "Can't find date\n";
			return;
		}
		for (const auto&a : it->second)
		{
			cout << a << endl;
		}
	}
	void Print_all()const
	{
		if (map_events_dates.empty())
		{
			cout << "We don't have any dates\n";
			return;
		}
		for (const auto&a : map_events_dates)
		{
			cout << a.first << ": " << endl;
			for (const auto&j : a.second)
			{
				cout << j << endl;
			}
		}
	}
};
void Programm_Loop(Database&database, bool&ex);
int main()
{
	Database database;
	bool ex = true;
	Programm_Loop(database, ex);
	system("pause");
	return 0;
}
void Programm_Loop(Database&database, bool&ex)
{

	while (ex)
	{
		try
		{
			string com;
			cout << "Enter a command\n";
			cin >> com;
			if (com == "Add")
			{
				database.Add_event_in_data();
				continue;
			}
			if (com == "Del")
			{
				database.Del_event_in_data();
				continue;
			}
			if (com == "Del_all")
			{
				database.Del_all_events_in_data();
				continue;
			}
			if (com == "Find")
			{
				database.Find_date();
				continue;
			}
			if (com == "Print")
			{
				database.Print_all();
				continue;
			}
			if (com == "Exit")
			{
				ex = false;
				continue;
			}
			throw runtime_error("Wrong command\n");
		}
		catch (runtime_error&er)
		{
			cout << er.what();
		}
	}
}