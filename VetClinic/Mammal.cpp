#include "GlobalData.h"
#include "Animals.h"

Mammal::Mammal(int id, const string& name, const string& type, int age, const string& ownerLogin, const string& furType, bool isVaccinated)
    : Animal(id, name, type, age, ownerLogin), furType(furType), isVaccinated(isVaccinated)
{
}

string Mammal::getFurType() const
{
    return this->furType;
}

bool Mammal::getIsVaccinated() const
{
    return this->isVaccinated;
}

void Mammal::setFurType(const string& furType)
{
    this->furType = furType;
}

void Mammal::setIsVaccinated(bool isVaccinated)
{
    this->isVaccinated = isVaccinated;
}

void Mammal::input()
{
    Animal::input();
    cout << "Тип шерсти: ";
    getline(cin, furType);
    isVaccinated = chek<int>("Вакцинирован (1-да/0-нет)", "Неверный ввод", [](int x) { return x == 0 || x == 1; });
}

void Mammal::displayInfo() const
{
    Animal::displayInfo();
    cout << "Тип шерсти: " << furType << endl;
    cout << "Вакцинирован: " << (isVaccinated ? "Да" : "Нет") << endl;
}

void Mammal::saveToFile(ofstream& file) const
{
    Animal::saveToFile(file);
    file << furType << endl;
    file << isVaccinated << endl;
}

void Mammal::loadFromFile(ifstream& file)
{
    Animal::loadFromFile(file);
    getline(file, furType);
    file >> isVaccinated;
    file.ignore();
}