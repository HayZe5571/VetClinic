#include "GlobalData.h"

void ScreenManager::showMainMenu()
{
    while (true)
    {
        system("cls");
        cout << "###################################" << endl;
        cout << "#  ВЕТКЛИНИКА УСЫ, ЛАПЫ И ХВОСТ   #" << endl;
        cout << "###################################" << endl;
        cout << endl;
        cout << "1. Войти в систему" << endl;
        cout << "2. Зарегистрироваться" << endl;
        cout << "3. Выйти из программы" << endl;
        cout << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 1 && x <= 3; });

        switch (choice)
        {
        case 1:
            showLoginScreen();
            system("cls");
            break;
        case 2:
            showRegistrationScreen();
            system("cls");
            break;
        case 3:
            return;
        }
    }
}

void ScreenManager::showLoginScreen()
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#           ВХОД В СИСТЕМУ        #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    string login, password;
    cout << "Логин: ";
    getline(cin, login);
    cout << "Пароль: ";
    getline(cin, password);

    Person* user = AuthorizationManager::loginUser(login, password);
    if (user != nullptr)
    {
        cout << "Вход выполнен! Добро пожаловать, " << user->getFirstName() << endl;

        if (user->getRole() == "client")
        {
            showClientMenu(static_cast<Client*>(user));
            return;
        }
        else if (user->getRole() == "admin")
        {
            showAdminMenu();
            return;
        }
        else if (user->getRole() == "veterinarian")
        {
            showVeterinarianMenu(static_cast<Veterinarian*>(user));
            return;
        }
    }
    else
    {
        cout << "Ошибка входа! Неверный логин или пароль" << endl;
        system("pause");
    }
}

void ScreenManager::showRegistrationScreen()
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#         РЕГИСТРАЦИЯ             #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    string login, password, firstName, lastName, email, phone;
    cout << "Логин: ";
    getline(cin, login);
    cout << "Пароль: ";
    getline(cin, password);
    cout << "Имя: ";
    getline(cin, firstName);
    cout << "Фамилия: ";
    getline(cin, lastName);
    cout << "Email: ";
    getline(cin, email);
    cout << "Телефон: ";
    getline(cin, phone);

    Client* newClient = AuthorizationManager::registerClient(login, password, firstName, lastName, email, phone);
    if (newClient)
    {
        FileManager::saveClients();
        cout << "Регистрация завершена" << endl;
    }
    system("pause");
}

void ScreenManager::showClientMenu(Client* client)
{
    while (true)
    {
        system("cls");
        cout << "###################################" << endl;
        cout << "#        ЛИЧНЫЙ КАБИНЕТ           #" << endl;
        cout << "###################################" << endl;
        cout << "Добро пожаловать, " << client->getFirstName() << " " << client->getLastName() << endl;
        cout << endl;
        cout << "1. Записаться на прием" << endl;
        cout << "2. Мои записи" << endl;
        cout << "3. Мои питомцы" << endl;
        cout << "4. Расписание врачей" << endl;
        cout << "5. Выйти из аккаунта" << endl;
        cout << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 1 && x <= 5; });

        switch (choice)
        {
        case 1:
            showAppointmentBooking(client);
            system("cls");
            break;
        case 2:
            showClientAppointments(client);
            system("cls");
            break;
        case 3:
            showClientPets(client);
            system("cls");
            break;
        case 4:
            showVeterinariansSchedule();
            system("pause");
            system("cls");
            break;
        case 5:
            FileManager::saveClients();
            return;
        }
    }
}

void ScreenManager::showVeterinarianMenu(Veterinarian* vet)
{
    while (true)
    {
        system("cls");
        cout << "###################################" << endl;
        cout << "#        ПАНЕЛЬ ВЕТЕРИНАРА        #" << endl;
        cout << "###################################" << endl;
        cout << "Добро пожаловать, " << vet->getFirstName() << " " << vet->getLastName() << endl;
        cout << endl;
        cout << "1. Мое расписание" << endl;
        cout << "2. Список всех врачей" << endl;
        cout << "3. Расписание всех врачей" << endl;
        cout << "4. Выйти из аккаунта" << endl;
        cout << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 1 && x <= 4; });

        switch (choice)
        {
        case 1:
            showVeterinarianPersonalSchedule(vet);
            system("cls");
            break;
        case 2:
            showVeterinariansList(false);
            system("pause");
            system("cls");
            break;
        case 3:
            showAppointmentsSchedule(false);
            system("pause");
            system("cls");
            break;
        case 4:
            return;
        }
    }
}

void ScreenManager::showAdminMenu()
{
    while (true)
    {
        system("cls");
        cout << "###################################" << endl;
        cout << "#      ПАНЕЛЬ АДМИНИСТРАТОРА      #" << endl;
        cout << "###################################" << endl;
        cout << endl;
        cout << "1. Управление записями" << endl;
        cout << "2. Управление пользователями" << endl;
        cout << "3. Просмотр работающих врачей" << endl;
        cout << "4. Просмотр статистики" << endl;
        cout << "5. Выйти из аккаунта" << endl;
        cout << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 1 && x <= 5; });

        switch (choice)
        {
        case 1:
            showAppointmentsManagement();
            system("cls");
            break;
        case 2:
            showUsersManagement();
            system("cls");
            break;
        case 3:
            showVeterinariansManagement();
            system("cls");
            break;
        case 4:
            showStatistics();
            system("pause");
            system("cls");
            break;
        case 5:
            return;
        }
    }
}

void ScreenManager::showAppointmentBooking(Client* client)
{
    Animal* selectedPet = showPetForAppointment(client);
    if (selectedPet == nullptr)
    {
        return;
    }
    showAppointmentWithPet(client, selectedPet);
}

Animal* ScreenManager::showPetForAppointment(Client* client)
{
    while (true)
    {
        system("cls");
        cout << "###################################" << endl;
        cout << "#     ВЫБОР ПИТОМЦА ДЛЯ ЗАПИСИ    #" << endl;
        cout << "###################################" << endl;
        cout << endl;

        vector<Animal*> clientAnimals;
        for (auto animal : animals)
        {
            if (animal->getOwnerLogin() == client->getLogin())
            {
                clientAnimals.push_back(animal);
            }
        }

        if (clientAnimals.empty())
        {
            cout << "У вас нет питомцев" << endl;
            cout << "1. Добавить питомца" << endl;
            cout << "0. Назад" << endl;

            int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x == 0 || x == 1; });

            if (choice == 0)
            {
                return nullptr;
            }

            cout << "Выберите тип животного: " << endl;
            cout << "1. Млекопитающее" << endl;
            cout << "2. Птица" << endl;
            cout << "3. Рептилия" << endl;

            int typeChoice = chek<int>("Ваш выбор", "Неверный выбор", [](int x) { return x >= 1 && x <= 3; });

            Animal* newAnimal = nullptr;
            switch (typeChoice)
            {
            case 1:
                newAnimal = new Mammal();
                break;
            case 2:
                newAnimal = new Bird();
                break;
            case 3:
                newAnimal = new Reptile();
                break;
            }

            if (newAnimal)
            {
                newAnimal->input();
                int newId = animals.empty() ? 1 : animals.back()->getId() + 1;
                newAnimal->setId(newId);
                newAnimal->setOwnerLogin(client->getLogin());
                animals.push_back(newAnimal);
                FileManager::saveAnimals();
                cout << "Питомец успешно добавлен" << endl;
                system("pause");
            }
            continue;
        }

        for (int i = 0; i < clientAnimals.size(); i++)
        {
            cout << i + 1 << ". " << clientAnimals[i]->getName() << " (" << clientAnimals[i]->getType() << ", возраст: " << clientAnimals[i]->getAge() << ")" << endl;
        }

        cout << "0. Назад" << endl;
        int choice = chek<int>("Выберите номер питомца", "Неверный выбор", [&](int x) { return x >= 0 && x <= clientAnimals.size(); });

        if (choice == 0)
        {
            return nullptr;
        }
        else if (choice > 0 && choice <= clientAnimals.size())
        {
            return clientAnimals[choice - 1];
        }
    }
}

void ScreenManager::showAppointmentWithPet(Client* client, Animal* selectedPet)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#        ЗАПИСЬ НА ПРИЕМ          #" << endl;
    cout << "###################################" << endl;
    cout << "Питомец: " << selectedPet->getName() << endl;
    cout << endl;

    cout << "Выберите врача:" << endl;
    for (int i = 0; i < veterinarians.size(); i++)
    {
        cout << i + 1 << ". " << veterinarians[i]->getFirstName() << " " << veterinarians[i]->getLastName() << " (" << veterinarians[i]->getSpecialization() << ")" << endl;
    }

    int vetChoice = chek<int>("Ваш выбор", "Неверный выбор врача", [&](int x) { return x >= 1 && x <= veterinarians.size(); });

    Veterinarian* selectedVet = veterinarians[vetChoice - 1];

    showSmartCalendar(selectedVet, client);
}

void ScreenManager::showClientAppointments(Client* client)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#           МОИ ЗАПИСИ            #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    vector<Appointment*> clientAppointments;
    for (auto appointment : appointments)
    {
        if (appointment->getClientLogin() == client->getLogin())
        {
            clientAppointments.push_back(appointment);
        }
    }

    if (clientAppointments.empty())
    {
        cout << "У вас нет записей" << endl;
        return;
    }

    cout << setw(4) << left << "№" << setw(8) << left << "ID"
        << setw(20) << left << "Дата" << setw(20) << left << "Время"
        << setw(20) << left << "Статус" << setw(20) << left << "Врач" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < clientAppointments.size(); i++)
    {
        cout << setw(4) << left << i + 1
            << setw(8) << left << clientAppointments[i]->getId()
            << setw(20) << left << clientAppointments[i]->getDate()
            << setw(20) << left << clientAppointments[i]->getTime();

        if (clientAppointments[i]->getStatus()) 
        {
            cout << setw(20) << left << "активна";
        }
        else 
        {
            cout << "\033[31m" << setw(20) << left << "ОТМЕНА" << "\033[0m";
        }

        cout << setw(20) << left << clientAppointments[i]->getVetLogin() << endl;
    }

    cout << endl << "0. Назад" << endl;
    int choice = chek<int>("Введите номер записи для отмены", "Неверный выбор", [&](int x) { return x >= 0 && x <= clientAppointments.size(); });

    if (choice == 0) return;

    if (choice > 0 && choice <= clientAppointments.size())
    {
        Appointment* selectedAppointment = clientAppointments[choice - 1];

        if (!selectedAppointment->getStatus())
        {
            cout << "Эту запись нельзя отменить (статус: отменена)" << endl;
            system("pause");
            return;
        }

        if (danetka("Вы уверены что хотите отменить запись"))
        {
            selectedAppointment->setStatus(false);
            FileManager::saveAppointments();
            cout << "Запись отменена" << endl;
            system("pause");
        }
        else
        {
            cout << "Отмена отмены записи" << endl;
            system("pause");
        }
    }
}

void ScreenManager::showClientPets(Client* client)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#           МОИ ПИТОМЦЫ           #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    vector<Animal*> clientAnimals;
    for (auto animal : animals)
    {
        if (animal->getOwnerLogin() == client->getLogin())
        {
            clientAnimals.push_back(animal);
        }
    }

    if (clientAnimals.empty())
    {
        cout << "У вас нет питомцев" << endl;
        return;
    }

    cout << setw(4) << left << "№" << setw(8) << left << "ID"
        << setw(20) << left << "Кличка" << setw(20) << left << "Вид"
        << setw(20) << left << "Возраст" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < clientAnimals.size(); i++)
    {
        cout << setw(4) << left << i + 1
            << setw(8) << left << clientAnimals[i]->getId()
            << setw(20) << left << clientAnimals[i]->getName()
            << setw(20) << left << clientAnimals[i]->getType()
            << setw(20) << left << clientAnimals[i]->getAge() << endl;
    }

    cout << endl;
    cout << "0. Назад" << endl;
    int choice = chek<int>("Введите номер питомца для подробной информации", "Неверный выбор", [&](int x) { return x >= 0 && x <= clientAnimals.size(); });

    if (choice == 0) return;

    if (choice > 0 && choice <= clientAnimals.size())
    {
        showAnimalInfo(clientAnimals[choice - 1]);
    }
    system("pause");
}

void ScreenManager::showVeterinariansSchedule()
{
    showAppointmentsSchedule(false);
}

void ScreenManager::showAppointmentsManagement()
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#       УПРАВЛЕНИЕ ЗАПИСЯМИ       #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    for (auto appointment : appointments)
    {
        cout << "ID: " << setw(3) << appointment->getId()
            << " | Клиент: " << setw(12) << appointment->getClientLogin()
            << " | Дата: " << setw(14) << appointment->getDate()
            << " | Время: " << setw(13) << appointment->getTime()
            << " | Статус: " << setw(12) << (appointment->getStatus() ? "активна" : "отменена") << endl;
    }

    cout << endl;
    cout << "1. Создать запись" << endl;
    cout << "2. Удалить запись" << endl;
    cout << "0. Назад" << endl;
    int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 0 && x <= 2; });

    if (choice == 0) return;

    if (choice == 1)
    {
        if (!clients.empty())
        {
            showAppointmentBooking(clients[0]);
        }
        else
        {
            cout << "Нет клиентов для создания записи" << endl;
            system("pause");
        }
        return;
    }

    if (choice == 2)
    {
        int id = chek<int>("Введите ID записи для удаления", "Неверный ID");

        bool found = false;
        for (auto it = appointments.begin(); it != appointments.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete* it;
                appointments.erase(it);
                FileManager::saveAppointments();
                cout << "Запись удалена" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Запись с таким ID не найдена" << endl;
        }
        system("pause");
        return;
    }
}

void ScreenManager::showUsersManagement()
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#    УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ    #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    for (int i = 0; i < clients.size(); i++)
    {
        cout << setw(3) << i + 1 << ". Логин: " << setw(13) << clients[i]->getLogin()
            << " | Имя: " << setw(15) << clients[i]->getFirstName()
            << " | Телефон: " << setw(13) << clients[i]->getPhoneNumber() << endl;
    }

    cout << endl;
    cout << "1. Добавить пользователя" << endl;
    cout << "2. Удалить пользователя" << endl;
    cout << "0. Назад" << endl;
    int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 0 && x <= 2; });

    if (choice == 0) return;

    if (choice == 1)
    {
        showRegistrationScreen();
        return;
    }

    if (choice == 2)
    {
        string login;
        cout << "Введите логин пользователя для удаления: ";
        getline(cin, login);

        if (login == "bozhenka7" || login == "admin")
        {
            cout << "Нельзя удалить администратора" << endl;
            system("pause");
            return;
        }

        bool found = false;
        for (auto it = clients.begin(); it != clients.end(); ++it)
        {
            if ((*it)->getLogin() == login)
            {
                delete* it;
                clients.erase(it);
                FileManager::saveClients();
                cout << "Пользователь удален" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Пользователь с таким логином не найден" << endl;
        }
        system("pause");
        return;
    }
} 

void ScreenManager::showVeterinariansManagement()
{
    showVeterinariansList(true);
}

void ScreenManager::showStatistics()
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#           СТАТИСТИКА            #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    cout << "Всего клиентов: " << clients.size() << endl;
    cout << "Всего врачей: " << veterinarians.size() << endl;
    cout << "Всего животных: " << animals.size() << endl;
    cout << "Всего записей: " << appointments.size() << endl;

    int activeAppointments = 0;
    int cancelledAppointments = 0;
    for (auto appointment : appointments)
    {
        if (appointment->getStatus())
        {
            activeAppointments++;
        }
        else
        {
            cancelledAppointments++;
        }
    }
    cout << "Активных записей: " << activeAppointments << endl;
    cout << "Отмененных записей: " << cancelledAppointments << endl;
}

void ScreenManager::showAnimalInfo(Animal* animal)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#      ИНФОРМАЦИЯ О ПИТОМЦЕ       #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    if (!animal)
    {
        cout << "Животное не найдено" << endl;
        return;
    }

    animal->displayInfo();

    cout << endl << "Медицинская история:" << endl;
    vector<string> medicalHistory = animal->getMedicalHistory();
    if (medicalHistory.empty())
    {
        cout << "  Нет записей" << endl;
    }
    else
    {
        for (auto record : medicalHistory)
        {
            cout << "  - " << record << endl;
        }
    }

    cout << endl << "Аллергии:" << endl;
    vector<string> allergies = animal->getAllergies();
    if (allergies.empty())
    {
        cout << "  Нет аллергий" << endl;
    }
    else
    {
        for (auto allergy : allergies)
        {
            cout << "  - " << allergy << endl;
        }
    }
}

void ScreenManager::showSmartCalendar(Veterinarian* vet, Client* client)
{
    vector<string> availableMonths = { "12.2025", "01.2026", "02.2026" };

    cout << "Выберите месяц:" << endl;
    for (int i = 0; i < availableMonths.size(); i++)
    {
        cout << i + 1 << ". " << availableMonths[i] << endl;
    }

    int monthChoice = chek<int>("Ваш выбор", "Неверный месяц", [&](int x) { return x >= 1 && x <= availableMonths.size(); });

    string selectedMonth = availableMonths[monthChoice - 1];
    showMonthCalendar(selectedMonth, vet, client);
}

void ScreenManager::showMonthCalendar(const string& month, Veterinarian* vet, Client* client)
{
    system("cls");
    cout << "# " << month << endl;
    cout << "Пн   Вт   Ср   Чт   Пт   Сб   Вс" << endl;
    cout << "---------------------------------" << endl;

    int daysInMonth = 31;
    string monthNum = month.substr(0, 2);
    if (monthNum == "02") daysInMonth = 28;
    else if (monthNum == "04" || monthNum == "06" || monthNum == "09" || monthNum == "11") daysInMonth = 30;

    int startDayOfWeek = 0;

    if (month == "12.2025") startDayOfWeek = 0;
    else if (month == "01.2026") startDayOfWeek = 3;
    else if (month == "02.2026") startDayOfWeek = 6;

    int day = 1;
    for (int week = 0; week < 6; week++)
    {
        for (int dayOfTheWeek = 0; dayOfTheWeek < 7; dayOfTheWeek++)
        {
            if (week == 0 && dayOfTheWeek < startDayOfWeek) {
                cout << "     ";
                continue;
            }

            if (day > daysInMonth)
            {
                cout << "     ";
                continue;
            }

            string fullDate = (day < 10 ? "0" : "") + to_string(day) + "." + month;
            if (vet->isWorkingDay(fullDate) && hasAvailableTimeSlots(fullDate, vet->getLogin()))
            {
                cout << "\033[32m" << setw(2) << day << "\033[0m   ";
            }
            else
            {
                cout << "\033[90m" << setw(2) << day << "\033[0m   ";
            }
            day++;
        }
        cout << endl;
    }

    offerDaySelection(month, vet, client);
}

bool ScreenManager::hasAvailableTimeSlots(const string& date, const string& vetLogin)
{
    vector<string> timeSlots = { "09:00", "10:00", "11:00", "12:00", "14:00", "15:00", "16:00", "17:00" };
    for (auto time : timeSlots)
    {
        if (Appointment::isTimeSlotAvailable(date, time, vetLogin))
        {
            return true;
        }
    }
    return false;
}

bool ScreenManager::offerDaySelection(const string& month, Veterinarian* vet, Client* client)
{
    cout << "\nВыберите день для записи (число) или 0 для выхода";

    int day = chek<int>("", "Неверный день", [&](int x) { if (x == 0) return true; return x >= 1 && x <= 31; });

    if (day == 0) return false;

    string selectedDate = to_string(day) + "." + month;

    if (vet->isWorkingDay(selectedDate) && hasAvailableTimeSlots(selectedDate, vet->getLogin()))
    {
        showTimeSlotsVisual(selectedDate, vet, client);
        return true;
    }
    else
    {
        cout << "Выбранный день недоступен для записи" << endl;
        system("pause");
    }

    return false;
}

void ScreenManager::showTimeSlotsVisual(const string& date, Veterinarian* vet, Client* client)
{
    vector<string> timeSlots = { "09:00", "10:00", "11:00", "12:00", "14:00", "15:00", "16:00", "17:00" };

    while (true) {
        system("cls");
        cout << "Расписание на " << date << ":\n";
        cout << "Время:   ";
        for (auto time : timeSlots)
        {
            cout << time << "   ";
        }
        cout << "\nСтатус:  ";

        for (auto time : timeSlots)
        {
            bool available = Appointment::isTimeSlotAvailable(date, time, vet->getLogin());
            cout << (available ? "|_______" : "|ХXXXXXX");
        }
        cout << "|" << endl;

        cout << "Выберите время (9-17) или 0 для отмены: ";
        int timeChoice = chek<int>("", "Неверный выбор времени", [&](int x) { return x == 0 || (x >= 9 && x <= 17); });

        if (timeChoice == 0) return;

        string selectedTime = timeSlots[timeChoice - 9];

        if (!Appointment::isTimeSlotAvailable(date, selectedTime, vet->getLogin()))
        {
            cout << "Выбранное время уже занято" << endl;
            system("pause");
            continue;
        }

        int newId = appointments.empty() ? 1 : appointments.back()->getId() + 1;
        Appointment* newAppointment = new Appointment(newId, date, selectedTime, true, client->getLogin(), 0, vet->getLogin(), "Новая запись");
        appointments.push_back(newAppointment);
        FileManager::saveAppointments();

        cout << "Запись создана успешно" << endl;
        system("pause");
        return;
    }
}

void ScreenManager::setVeterinarianSchedule(Veterinarian* vet)
{
    cout << "Выберите тип графика:" << endl;
    cout << "1. 5/2 (пн-пт)" << endl;
    cout << "2. 2/2 (сменный график)" << endl;

    int choice = chek<int>("Ваш выбор", "Неверный выбор", [](int x) { return x == 1 || x == 2; });

    if (choice == 1)
    {
        vet->setScheduleType("5/2");
        vet->setWorkSchedule({ "пн", "вт", "ср", "чт", "пт" });
        cout << "График 5/2 установлен" << endl;
    }
    else
    {
        vet->setScheduleType("2/2");
        vet->setShiftId(rand() % 1000);
        cout << "Сменный график 2/2 установлен" << endl;
    }
}

void ScreenManager::showVeterinarianPersonalSchedule(Veterinarian* vet)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#         МОЕ РАСПИСАНИЕ          #" << endl;
    cout << "###################################" << endl;
    cout << "Врач: " << vet->getFirstName() << " " << vet->getLastName() << " (" << vet->getSpecialization() << ")" << endl;
    cout << endl;

    vector<Appointment*> vetAppointments = Appointment::getAppointmentsByVeterinarian(vet->getLogin());

    if (vetAppointments.empty())
    {
        cout << "У вас нет записей" << endl;
        return;
    }

    cout << setw(4) << left << "№" << setw(20) << left << "Дата" << setw(20) << left << "Время"
        << setw(20) << left << "Клиент" << setw(20) << left << "Питомец" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    int displayIndex = 1;
    for (int i = 0; i < vetAppointments.size(); i++)
    {
        if (vetAppointments[i]->getStatus()) 
        {
            cout << setw(4) << left << displayIndex
                << setw(20) << left << vetAppointments[i]->getDate()
                << setw(20) << left << vetAppointments[i]->getTime()
                << setw(20) << left << vetAppointments[i]->getClientLogin();

            string petInfo = "не найден";
            for (auto animal : animals) 
            {
                if (animal->getId() == vetAppointments[i]->getAnimalId()) 
                {
                    petInfo = animal->getName() + " (" + animal->getType() + ")";
                    break;
                }
            }
            cout << setw(20) << left << petInfo << endl;
            displayIndex++;
        }
    }

    if (displayIndex == 1) 
    {
        cout << "Нет активных записей" << endl;
        return;
    }

    cout << endl << "0. Назад" << endl;
    int choice = chek<int>("Введите номер записи для просмотра информации о питомце", "Неверный выбор", [&](int x) { return x >= 0 && x <= displayIndex - 1; });

    if (choice == 0) return;

    int activeIndex = 0;
    for (int i = 0; i < vetAppointments.size(); i++) 
    {
        if (vetAppointments[i]->getStatus()) 
        {
            activeIndex++;
            if (activeIndex == choice) 
            {
                for (auto animal : animals) 
                {
                    if (animal->getId() == vetAppointments[i]->getAnimalId()) 
                    {
                        showAnimalInfo(animal);
                        break;
                    }
                }
                break;
            }
        }
    }
    system("pause");
}

void ScreenManager::showVeterinarianScheduleForAll()
{
    showAppointmentsSchedule(false);
}

void ScreenManager::showVeterinariansList(bool isAdmin)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#        СПИСОК ВРАЧЕЙ           #" << endl;
    cout << "###################################" << endl;
    cout << endl;

    cout << setw(4) << left << "№" << setw(20) << left << "Логин"
        << setw(20) << left << "Имя" << setw(20) << left << "Фамилия"
        << setw(20) << left << "Специализация"<< setw(20) << left << "График работы" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < veterinarians.size(); i++)
    {
        cout << setw(4) << left << i + 1
            << setw(20) << left << veterinarians[i]->getLogin()
            << setw(20) << left << veterinarians[i]->getFirstName()
            << setw(20) << left << veterinarians[i]->getLastName()
            << setw(20) << left << veterinarians[i]->getSpecialization()
            << setw(5) << left << veterinarians[i]->getScheduleType() << endl;
    }

    if (isAdmin) 
    {
        cout << endl << "1. Удалить врача" << endl;
        cout << "2. Настроить график врача" << endl;
        cout << "0. Назад" << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 0 && x <= 2; });

        if (choice == 1) 
        {
            int vetNumber = chek<int>("Введите номер врача для удаления", "Неверный номер", [&](int x) { return x >= 1 && x <= veterinarians.size(); });

            Veterinarian* vetToDelete = veterinarians[vetNumber - 1];
            
            bool hasActiveAppointments = false;
            for (auto app : appointments) 
            {
                if (app->getVetLogin() == vetToDelete->getLogin() && app->getStatus()) 
                {
                    hasActiveAppointments = true;
                    break;
                }
            }

            if (hasActiveAppointments) 
            {
                cout << "Нельзя удалить врача с активными записями" << endl;
            }
            else if (danetka("Вы уверены что хотите удалить врача " + vetToDelete->getFirstName() + " " + vetToDelete->getLastName() + "?"))
            {
                delete vetToDelete;
                veterinarians.erase(veterinarians.begin() + (vetNumber - 1));
                FileManager::saveVeterinarians();
                cout << "Врач удален" << endl;
            }
        }
        else if (choice == 2)
        {
            int vetNumber = chek<int>("Введите номер врача для настройки графика", "Неверный номер", [&](int x) { return x >= 1 && x <= veterinarians.size(); });

            setVeterinarianSchedule(veterinarians[vetNumber - 1]);
            FileManager::saveVeterinarians();
        }
    }
}

void ScreenManager::showAppointmentsSchedule(bool isAdmin)
{
    system("cls");
    cout << "###################################" << endl;
    cout << "#       РАСПИСАНИЕ ВРАЧЕЙ        #" << endl;
    cout << "###################################" << endl;
    cout << endl;
    
    cout << setw(4) << left << "№"
        << setw(20) << left << "Врач"
        << setw(20) << left << "Специализация"
        << setw(20) << left << "Дата"
        << setw(20) << left << "Время"
        << setw(20) << left << "Клиент" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    int counter = 1;
    for (auto vet : veterinarians)
    {
        vector<Appointment*> vetAppointments = Appointment::getAppointmentsByVeterinarian(vet->getLogin());
        for (auto app : vetAppointments)
        {
            if (app->getStatus())
            {
                cout << setw(4) << left << counter++
                    << setw(20) << left << (vet->getFirstName() + " " + vet->getLastName())
                    << setw(20) << left << vet->getSpecialization()
                    << setw(20) << left << app->getDate()
                    << setw(20) << left << app->getTime()
                    << setw(20) << left << app->getClientLogin() << endl;
            }
        }
    }

    if (isAdmin)
    {
        cout << endl << "1. Создать запись" << endl;
        cout << "2. Удалить запись" << endl;
        cout << "0. Назад" << endl;

        int choice = chek<int>("Выберите действие", "Неверный выбор", [](int x) { return x >= 0 && x <= 2; });

        if (choice == 1) 
        {
            if (!clients.empty())
            {
                showAppointmentBooking(clients[0]);
            }
        }
        else if (choice == 2) 
        {
            int appointmentId = chek<int>("Введите ID записи для удаления", "Неверный ID");

            bool found = false;
            for (auto it = appointments.begin(); it != appointments.end(); ++it) 
            {
                if ((*it)->getId() == appointmentId) 
                {
                    if (danetka("Вы уверены что хотите удалить запись ID " + to_string(appointmentId) + "?")) 
                    {
                        delete* it;
                        appointments.erase(it);
                        FileManager::saveAppointments();
                        cout << "Запись удалена" << endl;
                        found = true;
                    }

                    break;
                }
            }

            if (!found)
            {
                cout << "Запись с таким ID не найдена" << endl;
            }
            system("pause");
        }
    }
}