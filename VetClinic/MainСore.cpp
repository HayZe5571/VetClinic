#include "GlobalData.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    FileManager::loadAllData();

    if (animals.empty() || appointments.empty() || clients.empty() || veterinarians.empty()) {
        initializeTestData();
        FileManager::saveAllData();
    }

    bool adminExists = false;
    for (auto client : clients) {
        if (client->getLogin() == "bozhenka7") {
            adminExists = true;
            break;
        }
    }

    if (!adminExists) {
        Client* admin = new Client("bozhenka7", PasswordManager::hashPassword("08022007"), "Боженка", "Попова", "b@gmail.com", "+375291111111");
        admin->setRole("admin");
        clients.push_back(admin);
        FileManager::saveClients();
    }

    ScreenManager::showMainMenu();


    FileManager::saveAllData();
    cout << "До свидания" << endl;
    return 0;
}