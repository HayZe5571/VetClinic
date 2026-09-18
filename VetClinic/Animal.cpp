#include "GlobalData.h"
#include "Animals.h"

Animal::Animal(int id, const string& name, const string& type, int age, const string& ownerLogin)
	: id(id), name(name), type(type), age(age), ownerLogin(ownerLogin)
{
}

int Animal::getId() const
{
	return this->id;
}

string Animal::getName() const
{
	return this->name;
}

string Animal::getType() const
{
	return this->type;
}

int Animal::getAge() const
{
	return this->age;
}

string Animal::getOwnerLogin() const
{
	return this->ownerLogin;
}

vector<string> Animal::getMedicalHistory() const
{
	return this->medicalHistory;
}

vector<string> Animal::getAllergies() const
{
	return this->allergies;
}

void Animal::setId(int id)
{
	this->id = id;
}

void Animal::setName(const string& name)
{
	this->name = name;
}

void Animal::setType(const string& type)
{
	this->type = type;
}

void Animal::setAge(int age)
{
	this->age = age;
}

void Animal::setOwnerLogin(const string& ownerLogin)
{
	this->ownerLogin = ownerLogin;
}

void Animal::setMedicalHistory(const vector<string>& medicalHistory)
{
	this->medicalHistory = medicalHistory;
}

void Animal::setAllergies(const vector<string>& allergies)
{
	this->allergies = allergies;
}

void Animal::addMedicalRecord(const string& record)
{
	this->medicalHistory.push_back(record);
}

void Animal::removeMedicalRecord(const string& record)
{
	auto it = find(this->medicalHistory.begin(), this->medicalHistory.end(), record);
	if (it != this->medicalHistory.end())
	{
		this->medicalHistory.erase(it);
	}
}

void Animal::addAllergy(const string& allergy)
{
	this->allergies.push_back(allergy);
}

void Animal::removeAllergy(const string& allergy)
{
	auto it = find(this->allergies.begin(), this->allergies.end(), allergy);
	if (it != this->allergies.end())
	{
		this->allergies.erase(it);
	}
}

void Animal::input()
{
	cout << "Кличка питомца: ";
	getline(cin, name);
	cout << "Вид животного: ";
	getline(cin, type);
	age = chek<int>("Возраст", "Неверный возраст", [](int x) { return x >= 0 && x <= 50; });
}

void Animal::displayInfo() const
{
	cout << "ID: " << id << endl;
	cout << "Кличка: " << name << endl;
	cout << "Вид: " << type << endl;
	cout << "Возраст: " << age << endl;
	cout << "Владелец: " << ownerLogin << endl;
}

void Animal::saveToFile(ofstream& file) const
{
	file << id << endl;
	file << name << endl;
	file << type << endl;
	file << age << endl;
	file << ownerLogin << endl;

	file << medicalHistory.size() << endl;
	for (const string& record : medicalHistory)
	{
		file << record << endl;
	}

	file << allergies.size() << endl;
	for (const string& allergy : allergies)
	{
		file << allergy << endl;
	}
}

void Animal::loadFromFile(ifstream& file)
{
	file >> id;
	file.ignore();
	getline(file, name);
	getline(file, type);
	file >> age;
	file.ignore();
	getline(file, ownerLogin);

	int medHistoryCount;
	file >> medHistoryCount;
	file.ignore();

	medicalHistory.clear();
	for (int i = 0; i < medHistoryCount; i++)
	{
		string record;
		getline(file, record);
		medicalHistory.push_back(record);
	}

	int allergiesCount;
	file >> allergiesCount;
	file.ignore();

	allergies.clear();
	for (int i = 0; i < allergiesCount; i++)
	{
		string allergy;
		getline(file, allergy);
		allergies.push_back(allergy);
	}
}