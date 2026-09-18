#include "GlobalData.h"

Person* AuthorizationManager::loginUser(const string& login, const string& password)
{
	for (auto client : clients)
	{
		if (client->getLogin() == login && PasswordManager::verifyPassword(password, client->getPasswordHash()))
		{
			return client;
		}
	}

	for (auto vet : veterinarians)
	{
		if (vet->getLogin() == login && PasswordManager::verifyPassword(password, vet->getPasswordHash()))
		{
			return vet;
		}
	}

	return nullptr;
}

Client* AuthorizationManager::registerClient(const string& login, const string& password, const string& firstName, const string& lastName, const string& email, const string& phone)
{
	if (!PasswordManager::isLoginUnique(login))
	{
		cout << "Ошибка: Логин уже занят" << endl;
		return nullptr;
	}

	if (login.empty() || password.empty() || firstName.empty() || lastName.empty() || email.empty() || phone.empty())
	{
		cout << "Ошибка: Все поля должны быть заполнены" << endl;
		return nullptr;
	}

	if (email.find('@') == string::npos)
	{
		cout << "Ошибка: Некорректный email" << endl;
		return nullptr;
	}

	string hashedPassword = PasswordManager::hashPassword(password);

	Client* newClient = new Client(login, hashedPassword, firstName, lastName, email, phone);
	clients.push_back(newClient);

	cout << "Регистрация успешна" << endl;
	return newClient;
}