#include "GlobalData.h"
#include "People.h"

Veterinarian::Veterinarian(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& specialization)
	: Person(login, passwordHash, firstName, lastName, email, "veterinarian"), specialization(specialization), shiftId(-1)
{
}

string Veterinarian::getSpecialization() const
{
	return this->specialization;
}

string Veterinarian::getScheduleType() const
{
	return this->scheduleType;
}

vector<string> Veterinarian::getWorkSchedule() const
{
	return this->workSchedule;
}

int Veterinarian::getShiftId() const
{
	return this->shiftId;
}

void Veterinarian::setSpecialization(const string& specialization)
{
	this->specialization = specialization;
}

void Veterinarian::setScheduleType(const string& type) {
	scheduleType = type;

	if (type == "5/2")
	{
		workSchedule = { "пн", "вт", "ср", "чт", "пт" };
		shiftId = -1;
	}
	else if (type == "2/2")
	{
		workSchedule = { "2/2" };
		shiftId = 0;
		for (char c : login) 
		{
			shiftId += c;
		}
		shiftId %= 2;
	}
}

void Veterinarian::setWorkSchedule(const vector<string>& workSchedule)
{
	this->workSchedule = workSchedule;
}

void Veterinarian::setShiftId(int shiftId)
{
	this->shiftId = shiftId;
}

void Veterinarian::addWorkDay(const string& day)
{
	this->workSchedule.push_back(day);
}

void Veterinarian::removeWorkDay(const string& day)
{
	auto it = find(this->workSchedule.begin(), this->workSchedule.end(), day);
	if (it != this->workSchedule.end())
	{
		this->workSchedule.erase(it);
	}
}

bool Veterinarian::isWorkingDay(const string& date)
{
	if (scheduleType == "5/2")
	{
		string dayOfWeek = getDayOfWeekName(date);
		for (auto day : workSchedule)
		{
			if (day == dayOfWeek) return true;
		}
		return false;
	}
	else if (scheduleType == "2/2")
	{
		string dayOfWeek = getDayOfWeekName(date);

		if (shiftId % 2 == 0) 
		{
			return (dayOfWeek == "пн" || dayOfWeek == "вт" || dayOfWeek == "пт" || dayOfWeek == "сб");
		}
		else
		{
			return (dayOfWeek == "ср" || dayOfWeek == "чт" || dayOfWeek == "вс");
		}
	}
	return false;
}

void Veterinarian::input()
{
	Person::input();
	cout << "Специализация: ";
	getline(cin, specialization);
}

void Veterinarian::displayInfo() const
{
	Person::displayInfo();
	cout << "Специализация: " << specialization << endl;
}

void Veterinarian::saveToFile(ofstream& file) const
{
	Person::saveToFile(file);
	file << specialization << endl;
	file << scheduleType << endl;
	file << shiftId << endl;

	file << workSchedule.size() << endl;
	for (auto day : workSchedule)
	{
		file << day << endl;
	}
}

void Veterinarian::loadFromFile(ifstream& file)
{
	Person::loadFromFile(file);
	getline(file, specialization);
	getline(file, scheduleType);
	file >> shiftId;
	file.ignore();

	int scheduleCount;
	file >> scheduleCount;
	file.ignore();

	workSchedule.clear();
	for (int i = 0; i < scheduleCount; i++)
	{
		string day;
		getline(file, day);
		workSchedule.push_back(day);
	}
}