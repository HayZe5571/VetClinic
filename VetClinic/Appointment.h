#pragma once

class Appointment
{
protected:
	int id = 0;
	string date;
	string time;
	bool status = true;
	string clientLogin;
	int animalId = 0;
	string vetLogin;
	string notes;

public:
	Appointment() = default;
	Appointment(int id, const string& date, const string& time, bool status, const string& clientLogin, int animalId, const string& vetLogin, const string& notes);
	Appointment(const Appointment& other) = default;
	virtual ~Appointment() = default;

	int getId() const;
	string getDate() const;
	string getTime() const;
	bool getStatus() const;
	string getClientLogin() const;
	int getAnimalId() const;
	string getVetLogin() const;
	string getNotes() const;

	void setId(int id);
	void setDate(const string& date);
	void setTime(const string& time);
	void setStatus(bool status);
	void setClientLogin(const string& clientLogin);
	void setAnimalId(int animalId);
	void setVetLogin(const string& vetLogin);
	void setNotes(const string& notes);

	static vector<Appointment*> getAppointmentsByDate(const string& date);
	static vector<Appointment*> getAppointmentsByVeterinarian(const string& vetLogin);
	static vector<Appointment*> getAppointmentsByClient(const string& clientLogin);
	static void showCalendarView(const string& month);
	static bool isTimeSlotAvailable(const string& date, const string& time, const string& vetLogin);
	static vector<string> getAvailableTimeSlots(const string& date, const string& vetLogin);

	void input();
	void displayInfo() const;

	void saveToFile(ofstream& file) const;
	void loadFromFile(ifstream& file);
};