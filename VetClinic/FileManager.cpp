#include "GlobalData.h"

void FileManager::saveAllData()
{
    saveClients();
    saveVeterinarians();
    saveAnimals();
    saveAppointments();
}

void FileManager::loadAllData()
{
    loadVeterinarians();
    loadClients();
    loadAnimals();
    loadAppointments();
}

void FileManager::saveClients()
{
    ofstream file(CLIENTS_FILE);
    if (!file.is_open()) return;

    file << clients.size() << endl;
    for (auto client : clients)
    {
        client->saveToFile(file);
    }
    file.close();
}

void FileManager::saveVeterinarians()
{
    ofstream file(VETERINARIANS_FILE);
    if (!file.is_open()) return;

    file << veterinarians.size() << endl;
    for (auto vet : veterinarians)
    {
        vet->saveToFile(file);
    }
    file.close();
}

void FileManager::saveAnimals()
{
    ofstream file(ANIMALS_FILE);
    if (!file.is_open()) return;

    file << animals.size() << endl;
    for (auto animal : animals)
    {
        file << animal->getClassName() << endl;
        animal->saveToFile(file);
    }
    file.close();
}

void FileManager::saveAppointments()
{
    ofstream file(APPOINTMENTS_FILE);
    if (!file.is_open()) return;

    file << appointments.size() << endl;
    for (auto appointment : appointments)
    {
        appointment->saveToFile(file);
    }
    file.close();
}

void FileManager::loadClients()
{
    for (auto client : clients) delete client;
    clients.clear();

    ifstream file(CLIENTS_FILE);
    if (!file.is_open()) return;

    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++)
    {
        Client* client = new Client();
        client->loadFromFile(file);
        clients.push_back(client);
    }
    file.close();
}

void FileManager::loadVeterinarians()
{
    for (auto vet : veterinarians) delete vet;
    veterinarians.clear();

    ifstream file(VETERINARIANS_FILE);
    if (!file.is_open()) return;

    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++)
    {
        Veterinarian* vet = new Veterinarian();
        vet->loadFromFile(file);
        veterinarians.push_back(vet);
    }
    file.close();
}

void FileManager::loadAnimals()
{
    for (auto animal : animals) delete animal;
    animals.clear();

    ifstream file(ANIMALS_FILE);
    if (!file.is_open()) return;

    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++)
    {
        string className;
        getline(file, className);

        Animal* animal = nullptr;
        if (className == "MAMMAL") animal = new Mammal();
        else if (className == "BIRD") animal = new Bird();
        else if (className == "REPTILE") animal = new Reptile();

        if (animal)
        {
            animal->loadFromFile(file);
            animals.push_back(animal);
        }
    }
    file.close();
}

void FileManager::loadAppointments()
{
    for (auto appointment : appointments) delete appointment;
    appointments.clear();

    ifstream file(APPOINTMENTS_FILE);
    if (!file.is_open()) return;

    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; i++)
    {
        Appointment* appointment = new Appointment();
        appointment->loadFromFile(file);
        appointments.push_back(appointment);
    }
    file.close();
}