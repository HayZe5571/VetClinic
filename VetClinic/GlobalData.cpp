#include "GlobalData.h"

vector<Client*> clients;
vector<Veterinarian*> veterinarians;
vector<Animal*> animals;
vector<Appointment*> appointments;

const string CLIENTS_FILE = "data/clients.txt"; 
const string VETERINARIANS_FILE = "data/veterinarians.txt";
const string ANIMALS_FILE = "data/animals.txt";
const string APPOINTMENTS_FILE = "data/appointments.txt";

void initializeTestData() {
    vector<Veterinarian*> newVets = {
        new Veterinarian("vet_smith", PasswordManager::hashPassword("1234"), "Джон", "Смит", "smith@clinic.by", "Хирург"),
        new Veterinarian("vet_lee", PasswordManager::hashPassword("1234"), "Мария", "Ли", "lee@clinic.by", "Терапевт"),
        new Veterinarian("vet_ivanov", PasswordManager::hashPassword("1234"), "Алексей", "Иванов", "ivanov@clinic.by", "Кардиолог"),
        new Veterinarian("vet_petrova", PasswordManager::hashPassword("1234"), "Ольга", "Петрова", "petrova@clinic.by", "Дерматолог"),
        new Veterinarian("vet_kuznetsov", PasswordManager::hashPassword("1234"), "Сергей", "Кузнецов", "kuznetsov@clinic.by", "Ортопед"),
        new Veterinarian("vet_volkova", PasswordManager::hashPassword("1234"), "Елена", "Волкова", "volkova@clinic.by", "Невролог"),
        new Veterinarian("vet_kozlov", PasswordManager::hashPassword("1234"), "Игорь", "Козлов", "kozlov@clinic.by", "Офтальмолог"),
        new Veterinarian("vet_fedorov", PasswordManager::hashPassword("1234"), "Павел", "Федоров", "fedorov@clinic.by", "Стоматолог"),
        new Veterinarian("vet_orlova", PasswordManager::hashPassword("1234"), "Анна", "Орлова", "orlova@clinic.by", "Эндокринолог"),
        new Veterinarian("vet_zhukov", PasswordManager::hashPassword("1234"), "Михаил", "Жуков", "zhukov@clinic.by", "Онколог")
    };

    newVets[0]->setScheduleType("5/2");
    newVets[1]->setScheduleType("2/2");
    newVets[2]->setScheduleType("5/2");
    newVets[3]->setScheduleType("2/2");
    newVets[4]->setScheduleType("5/2");
    newVets[5]->setScheduleType("2/2");
    newVets[6]->setScheduleType("5/2");
    newVets[7]->setScheduleType("2/2");
    newVets[8]->setScheduleType("5/2");
    newVets[9]->setScheduleType("2/2");

    vector<Client*> newClients = {
        new Client("ivanov", PasswordManager::hashPassword("1111"), "Иван", "Петров", "ivan@mail.com", "+375291111111"),
        new Client("sidorova", PasswordManager::hashPassword("1111"), "Анна", "Сидорова", "anna@mail.com", "+375292222222"),
        new Client("smirnov", PasswordManager::hashPassword("1111"), "Дмитрий", "Смирнов", "smirnov@mail.com", "+375293333333"),
        new Client("kozlov", PasswordManager::hashPassword("1111"), "Екатерина", "Козлова", "kozlov@mail.com", "+375294444444"),
        new Client("novikov", PasswordManager::hashPassword("1111"), "Андрей", "Новиков", "novikov@mail.com", "+375295555555"),
        new Client("morozova", PasswordManager::hashPassword("1111"), "Светлана", "Морозова", "morozova@mail.com", "+375296666666"),
        new Client("volkov", PasswordManager::hashPassword("1111"), "Максим", "Волков", "volkov@mail.com", "+375297777777"),
        new Client("fedorova", PasswordManager::hashPassword("1111"), "Наталья", "Федорова", "fedorova@mail.com", "+375298888888"),
        new Client("popov", PasswordManager::hashPassword("1111"), "Артем", "Попов", "popov@mail.com", "+375299999999"),
        new Client("sokolov", PasswordManager::hashPassword("1111"), "Виктория", "Соколова", "sokolov@mail.com", "+375290000000")
    };

    vector<Animal*> newAnimals = {
        new Mammal(1, "Барсик", "Кот", 3, "ivanov", "Короткая", true),
        new Bird(2, "Кеша", "Попугай", 2, "sidorova", 25.5, true),
        new Mammal(3, "Шарик", "Собака", 5, "smirnov", "Длинная", true),
        new Reptile(4, "Гена", "Черепаха", 10, "kozlov", 22.0, false),
        new Mammal(5, "Мурка", "Кошка", 4, "novikov", "Пушистая", true),
        new Bird(6, "Гоша", "Канарейка", 1, "morozova", 15.0, true),
        new Mammal(7, "Рекс", "Собака", 6, "volkov", "Гладкая", true),
        new Reptile(8, "Зоя", "Ящерица", 3, "fedorova", 25.5, false),
        new Mammal(9, "Пушистик", "Кролик", 2, "popov", "Пух", true),
        new Bird(10, "Чижик", "Воробей", 1, "sokolov", 12.0, true),
        new Mammal(11, "Тузик", "Собака", 7, "ivanov", "Кудрявая", true),
        new Reptile(12, "Вася", "Змея", 4, "sidorova", 28.0, true)
    };

    vector<Appointment*> newAppointments = {
        new Appointment(1, "15.12.2025", "10:00", true, "ivanov", 1, "vet_smith", "Плановый осмотр"),
        new Appointment(2, "16.12.2025", "14:00", true, "sidorova", 2, "vet_lee", "Вакцинация"),
        new Appointment(3, "17.12.2025", "11:00", true, "smirnov", 3, "vet_ivanov", "Консультация"),
        new Appointment(4, "18.12.2025", "15:00", true, "kozlov", 4, "vet_petrova", "Профилактика"),
        new Appointment(5, "19.12.2025", "09:00", true, "novikov", 5, "vet_kuznetsov", "Осмотр"),
        new Appointment(6, "20.12.2025", "16:00", true, "morozova", 6, "vet_smith", "Лечение"),
        new Appointment(7, "21.12.2025", "12:00", true, "volkov", 7, "vet_lee", "Вакцинация"),
        new Appointment(8, "22.12.2025", "14:00", true, "fedorova", 8, "vet_ivanov", "Консультация"),
        new Appointment(9, "23.12.2025", "10:00", true, "popov", 9, "vet_petrova", "Осмотр"),
        new Appointment(10, "24.12.2025", "11:00", true, "sokolov", 10, "vet_kuznetsov", "Профилактика"),
        new Appointment(11, "25.12.2025", "15:00", true, "ivanov", 11, "vet_smith", "Повторный прием"),
        new Appointment(12, "26.12.2025", "13:00", true, "sidorova", 12, "vet_lee", "Контрольный осмотр")
    };

    for (auto vet : newVets) veterinarians.push_back(vet);
    for (auto client : newClients) clients.push_back(client);
    for (auto animal : newAnimals) animals.push_back(animal);
    for (auto appointment : newAppointments) appointments.push_back(appointment);

    cout << "Тестовые данные созданы: " << endl;
    cout << "- Ветеринаров: " << veterinarians.size() << endl;
    cout << "- Клиентов: " << clients.size() << endl;
    cout << "- Животных: " << animals.size() << endl;
    cout << "- Записей: " << appointments.size() << endl;
}