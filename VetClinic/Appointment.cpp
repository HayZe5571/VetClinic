#include "GlobalData.h"
#include "Appointment.h"

Appointment::Appointment(int id, const string& date, const string& time, bool status, const string& clientLogin, int animalId, const string& vetLogin, const string& notes)
	: id(id), date(date), time(time), status(status), clientLogin(clientLogin), animalId(animalId), vetLogin(vetLogin), notes(notes)
{
}

int Appointment::getId() const
{
	return this->id;
}

string Appointment::getDate() const
{
	return this->date;
}

string Appointment::getTime() const
{
	return this->time;
}

bool Appointment::getStatus() const
{
	return this->status;
}

string Appointment::getClientLogin() const
{
	return this->clientLogin;
}

int Appointment::getAnimalId() const
{
	return this->animalId;
}

string Appointment::getVetLogin() const
{
	return this->vetLogin;
}

string Appointment::getNotes() const
{
	return this->notes;
}

void Appointment::setId(int id)
{
	this->id = id;
}

void Appointment::setDate(const string& date)
{
	this->date = date;
}

void Appointment::setTime(const string& time)
{
	this->time = time;
}

void Appointment::setStatus(bool status)
{
	this->status = status;
}

void Appointment::setClientLogin(const string& clientLogin)
{
	this->clientLogin = clientLogin;
}

void Appointment::setAnimalId(int animalId)
{
	this->animalId = animalId;
}

void Appointment::setVetLogin(const string& vetLogin)
{
	this->vetLogin = vetLogin;
}

void Appointment::setNotes(const string& notes)
{
	this->notes = notes;
}

vector<Appointment*> Appointment::getAppointmentsByDate(const string& date)
{
	vector<Appointment*> result;
	for (auto appointment : appointments)
	{
		if (appointment->getDate() == date)
		{
			result.push_back(appointment);
		}
	}
	return result;
}

vector<Appointment*> Appointment::getAppointmentsByVeterinarian(const string& vetLogin)
{
	vector<Appointment*> result;
	for (auto appointment : appointments)
	{
		if (appointment->getVetLogin() == vetLogin)
		{
			result.push_back(appointment);
		}
	}
	return result;
}

vector<Appointment*> Appointment::getAppointmentsByClient(const string& clientLogin)
{
	vector<Appointment*> result;
	for (auto appointment : appointments)
	{
		if (appointment->getClientLogin() == clientLogin)
		{
			result.push_back(appointment);
		}
	}
	return result;
}

void Appointment::showCalendarView(const string& month)
{
	cout << "Календарь на " << month << ":" << endl;

	for (auto appointment : appointments)
	{
		if (appointment->getDate().find(month) != string::npos)
		{
			cout << "Запись: " << appointment->getDate() << " " << appointment->getTime()
				<< " - " << appointment->getClientLogin() << endl;
		}
	}
}

bool Appointment::isTimeSlotAvailable(const string& date, const string& time, const string& vetLogin)
{
	for (auto appointment : appointments)
	{
		if (appointment->getDate() == date &&
			appointment->getTime() == time &&
			appointment->getVetLogin() == vetLogin &&
			appointment->getStatus() == true)
		{
			return false;
		}
	}
	return true;
}

vector<string> Appointment::getAvailableTimeSlots(const string& date, const string& vetLogin)
{
	vector<string> allTimeSlots = { "09:00", "10:00", "11:00", "12:00", "14:00", "15:00", "16:00", "17:00" };
	vector<string> availableSlots;

	for (auto time : allTimeSlots)
	{
		if (isTimeSlotAvailable(date, time, vetLogin))
		{
			availableSlots.push_back(time);
		}
	}

	return availableSlots;
}

void Appointment::input()
{
	cout << "Дата (ДД.ММ.ГГГГ): ";
	getline(cin, date);
	cout << "Время (ЧЧ:ММ): ";
	getline(cin, time);
	cout << "Примечания: ";
	getline(cin, notes);
	status = true;
}

void Appointment::displayInfo() const
{
	cout << "ID записи: " << id << endl;
	cout << "Дата: " << date << endl;
	cout << "Время: " << time << endl;
	cout << "Статус: " << status << endl;
	cout << "Клиент: " << clientLogin << endl;
	cout << "ID животного: " << animalId << endl;
	cout << "Ветеринар: " << vetLogin << endl;
	cout << "Примечания: " << notes << endl;
}

void Appointment::saveToFile(ofstream& file) const
{
	file << id << endl;
	file << date << endl;
	file << time << endl;
	file << status << endl;
	file << clientLogin << endl;
	file << animalId << endl;
	file << vetLogin << endl;
	file << notes << endl;
}

void Appointment::loadFromFile(ifstream& file)
{
	file >> id;
	file.ignore();
	getline(file, date);
	getline(file, time);
	file >> status;
	file.ignore();
	getline(file, clientLogin);
	file >> animalId;
	file.ignore();
	getline(file, vetLogin);
	getline(file, notes);
}