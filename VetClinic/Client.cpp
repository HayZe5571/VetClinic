#include "GlobalData.h"
#include "People.h"

Client::Client(const string& login, const string& passwordHash, const string& firstName, const string& lastName, const string& email, const string& phoneNumber)
    : Person(login, passwordHash, firstName, lastName, email, "client"), phoneNumber(phoneNumber)
{
}

string Client::getPhoneNumber() const
{
    return this->phoneNumber;
}

vector<string> Client::getPets() const
{
    return this->pets;
}

void Client::setPhoneNumber(const string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Client::setPets(const vector<string>& pets)
{
    this->pets = pets;
}

void Client::addPet(const string& pet)
{
    this->pets.push_back(pet);
}

void Client::removePet(const string& pet)
{
    auto it = find(this->pets.begin(), this->pets.end(), pet);
    if (it != this->pets.end())
    {
        this->pets.erase(it);
    }
}

void Client::input()
{
    Person::input();

    while (true) {
        cout << "Телефон: ";
        getline(cin, phoneNumber);

        if (phoneNumber[0] == '+' && phoneNumber.length() == 13) {
            bool allDigits = true;
            for (int i = 1; i < phoneNumber.length(); i++) {
                if (!isdigit(phoneNumber[i])) {
                    allDigits = false;
                    break;
                }
            }
            if (allDigits) {
                break;
            }
        }
        cout << "Неверный формат телефона! Должен быть в формате +375XXXXXXXXX" << endl;
    }
}

void Client::displayInfo() const
{
    Person::displayInfo();
    cout << "Телефон: " << phoneNumber << endl;
    cout << "Питомцы: ";
    for (auto pet : pets)
    {
        cout << pet << " ";
    }
    cout << endl;
}

void Client::saveToFile(ofstream& file) const
{
    Person::saveToFile(file);
    file << phoneNumber << endl;

    file << pets.size() << endl;
    for (auto pet : pets)
    {
        file << pet << endl;
    }
}

void Client::loadFromFile(ifstream& file)
{
    Person::loadFromFile(file);
    getline(file, phoneNumber);

    int petsCount;
    file >> petsCount;
    file.ignore();

    pets.clear();
    for (int i = 0; i < petsCount; i++)
    {
        string pet;
        getline(file, pet);
        pets.push_back(pet);
    }
}