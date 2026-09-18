#include "GlobalData.h"
#include "People.h"

Person::Person(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& role)
	: login(login), passwordHash(passwordHash), firstName(firstName), lastName(lastName), email(email), role(role)
{
}

string Person::getLogin() const
{
	return this->login;
}

string Person::getPasswordHash() const
{
	return this->passwordHash;
}

string Person::getFirstName() const
{
	return this->firstName;
}

string Person::getLastName() const
{
	return this->lastName;
}

string Person::getEmail() const
{
	return this->email;
}

string Person::getRole() const
{
	return this->role;
}

void Person::setLogin(const string& login)
{
	this->login = login;
}

void Person::setPasswordHash(const string& passwordHash)
{
	this->passwordHash = passwordHash;
}

void Person::setFirstName(const string& firstName)
{
	this->firstName = firstName;
}

void Person::setLastName(const string& lastName)
{
	this->lastName = lastName;
}

void Person::setEmail(const string& email)
{
	this->email = email;
}

void Person::setRole(const string& role)
{
	this->role = role;
}

bool Person::checkPassword(const string& password) const
{
	return PasswordManager::verifyPassword(password, this->passwordHash);
}

void Person::input()
{
	cout << "Логин: ";
	getline(cin, login);

	string password;
	cout << "Пароль: ";
	getline(cin, password);
	passwordHash = PasswordManager::hashPassword(password);

	cout << "Имя: ";
	getline(cin, firstName);
	cout << "Фамилия: ";
	getline(cin, lastName);
	cout << "Email: ";
	getline(cin, email);
}

void Person::displayInfo() const
{
	cout << "Логин: " << login << endl;
	cout << "Имя: " << firstName << endl;
	cout << "Фамилия: " << lastName << endl;
	cout << "Email: " << email << endl;
	cout << "Роль: " << role << endl;
}

void Person::saveToFile(ofstream& file) const
{
	file << login << endl;
	file << passwordHash << endl;
	file << firstName << endl;
	file << lastName << endl;
	file << email << endl;
	file << role << endl;
}

void Person::loadFromFile(ifstream& file)
{
	getline(file, login);
	getline(file, passwordHash);
	getline(file, firstName);
	getline(file, lastName);
	getline(file, email);
	getline(file, role);
}