#include "GlobalData.h"
#include "Animals.h"

Reptile::Reptile(int id, const string& name, const string& type, int age, const string& ownerLogin, double bodyTemperature, bool isVenomous)
    : Animal(id, name, type, age, ownerLogin), bodyTemperature(bodyTemperature), isVenomous(isVenomous)
{
}

double Reptile::getBodyTemperature() const
{
    return this->bodyTemperature;
}

bool Reptile::getIsVenomous() const
{
    return this->isVenomous;
}

void Reptile::setBodyTemperature(double bodyTemperature)
{
    this->bodyTemperature = bodyTemperature;
}

void Reptile::setIsVenomous(bool isVenomous)
{
    this->isVenomous = isVenomous;
}

void Reptile::input()
{
    Animal::input();
    bodyTemperature = chek<double>("Температура тела", "Неверная температура", [](double x) { return x > 0 && x < 50; });
    isVenomous = chek<int>("Ядовитый (1-да/0-нет)", "Неверный ввод", [](int x) { return x == 0 || x == 1; });
}

void Reptile::displayInfo() const
{
    Animal::displayInfo();
    cout << "Температура тела: " << bodyTemperature << endl;
    cout << "Ядовитый: " << (isVenomous ? "Да" : "Нет") << endl;
}

void Reptile::saveToFile(ofstream& file) const
{
    Animal::saveToFile(file);
    file << bodyTemperature << endl;
    file << isVenomous << endl;
}

void Reptile::loadFromFile(ifstream& file)
{
    Animal::loadFromFile(file);
    file >> bodyTemperature;
    file.ignore();
    file >> isVenomous;
    file.ignore();
}