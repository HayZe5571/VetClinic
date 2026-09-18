#include "GlobalData.h"

string PasswordManager::hashPassword(const string& password)
{
    size_t hash = std::hash<string>{}(password);
    stringstream ss;
    ss << setw(16) << setfill('0') << hash;
    return ss.str();
}

bool PasswordManager::verifyPassword(const string& password, const string& passwordHash)
{
    return hashPassword(password) == passwordHash;
}

string PasswordManager::toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool PasswordManager::isLoginUnique(const string& login)
{
    string lowerLogin = toLower(login);

    for (auto client : clients)
    {
        if (toLower(client->getLogin()) == lowerLogin)
            return false;
    }

    for (auto vet : veterinarians)
    {
        if (toLower(vet->getLogin()) == lowerLogin)
            return false; 
    }

    return true;
}