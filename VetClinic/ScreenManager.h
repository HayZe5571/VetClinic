#pragma once

namespace ScreenManager
{
    void showMainMenu();

    void showLoginScreen();
    void showRegistrationScreen();

    void showClientMenu(Client* client);
    void showVeterinarianMenu(Veterinarian* vet);
    void showAdminMenu();

    void showAppointmentBooking(Client* client);
    Animal* showPetForAppointment(Client* client);
    void showAppointmentWithPet(Client* client, Animal* selectedPet);
    void showClientAppointments(Client* client);
    void showClientPets(Client* client);
    void showVeterinariansSchedule();

    void showAppointmentsManagement();
    void showUsersManagement();
    void showVeterinariansManagement();
    void showStatistics();

    void showSmartCalendar(Veterinarian* vet, Client* client = nullptr);
    void showMonthCalendar(const string& month, Veterinarian* vet, Client* client);
    bool hasAvailableTimeSlots(const string& date, const string& vetLogin);
    bool offerDaySelection(const string& month, Veterinarian* vet, Client* client);
    void showTimeSlotsVisual(const string& date, Veterinarian* vet, Client* client);

    void showAnimalInfo(Animal* animal);
    void setVeterinarianSchedule(Veterinarian* vet);

    void showVeterinarianPersonalSchedule(Veterinarian* vet);
    void showVeterinarianScheduleForAll();
    void showVeterinariansList(bool isAdmin = false);
    void showAppointmentsSchedule(bool isAdmin = false);
}