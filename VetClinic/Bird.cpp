#include "GlobalData.h"
#include "Animals.h"

Bird::Bird(int id, const string& name, const string& type, int age, const string& ownerLogin, double wingspan, bool canFly)
    : Animal(id, name, type, age, ownerLogin), wingspan(wingspan), canFly(canFly)
{
}

double Bird::getWingspan() const
{
    return this->wingspan;
}

bool Bird::getCanFly() const
{
    return this->canFly;
}

void Bird::setWingspan(double wingspan)
{
    this->wingspan = wingspan;
}

void Bird::setCanFly(bool canFly)
{
    this->canFly = canFly;
}

void Bird::input()
{
    Animal::input();
    wingspan = chek<double>("Размах крыльев", "Неверный размах крыльев", [](double x) { return x > 0; });
    canFly = chek<int>("Умеет летать (1-да/0-нет)", "Неверный ввод", [](int x) { return x == 0 || x == 1; });
}

void Bird::displayInfo() const
{
    Animal::displayInfo();
    cout << "Размах крыльев: " << wingspan << endl;
    cout << "Умеет летать: " << (canFly ? "Да" : "Нет") << endl;
}

void Bird::saveToFile(ofstream& file) const
{
    Animal::saveToFile(file);
    file << wingspan << endl;
    file << canFly << endl;
}

void Bird::loadFromFile(ifstream& file)
{
    Animal::loadFromFile(file);
    file >> wingspan;
    file.ignore();
    file >> canFly;
    file.ignore();
}