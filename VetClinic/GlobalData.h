#pragma once

#include "MyIncludes.h"

#include "People.h"
#include "Animals.h"
#include "Appointment.h"

#include "AuthorizationManager.h"
#include "FileManager.h"
#include "PasswordManager.h"
#include "ScreenManager.h"

extern vector<Client*> clients;
extern vector<Veterinarian*> veterinarians;
extern vector<Animal*> animals;
extern vector<Appointment*> appointments;

extern const string CLIENTS_FILE;
extern const string VETERINARIANS_FILE;
extern const string ANIMALS_FILE;
extern const string APPOINTMENTS_FILE;

void initializeTestData();