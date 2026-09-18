#pragma once

class Person
{
protected:
	string login;
	string passwordHash;
	string firstName;
	string lastName;
	string email;
	string role;

public:
	Person() = default;
	Person(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& role);
	Person(const Person& other) = default;
	virtual ~Person() = default;

	string getLogin() const;
	string getPasswordHash() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	string getRole() const;

	void setLogin(const string& login);
	void setPasswordHash(const string& passwordHash);
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setEmail(const string& email);
	void setRole(const string& role);

	bool checkPassword(const string& password) const;
	virtual void input() = 0;
	virtual void displayInfo() const = 0;

	virtual void saveToFile(ofstream& file) const;
	virtual void loadFromFile(ifstream& file);
};

class Client : public Person
{
protected:
	string phoneNumber;
	vector<string> pets;

public:
	Client() = default;
	Client(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& phoneNumber);
	Client(const Client& other) = default;
	virtual ~Client() = default;

	string getPhoneNumber() const;
	vector<string> getPets() const;

	void setPhoneNumber(const string& phoneNumber);
	void setPets(const vector<string>& pets);

	void addPet(const string& pet);
	void removePet(const string& pet);

	void input() override;
	void displayInfo() const override;

	void saveToFile(ofstream& file) const override;
	void loadFromFile(ifstream& file) override;
};

class Veterinarian : public Person
{
protected:
	string specialization;
	string scheduleType;
	vector<string> workSchedule;
	int shiftId;

public:
	Veterinarian() = default;
	Veterinarian(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& specialization);
	Veterinarian(const Veterinarian& other) = default;
	virtual ~Veterinarian() = default;

	string getSpecialization() const;
	string getScheduleType() const;
	vector<string> getWorkSchedule() const;
	int getShiftId() const;

	void setSpecialization(const string& specialization);
	void setScheduleType(const string& scheduleType);
	void setWorkSchedule(const vector<string>& workSchedule);
	void setShiftId(int shiftId);

	void addWorkDay(const string& day);
	void removeWorkDay(const string& day);

	bool isWorkingDay(const string& date);

	void input() override;
	void displayInfo() const override;

	void saveToFile(ofstream& file) const override;
	void loadFromFile(ifstream& file) override;
};