#pragma once

namespace PasswordManager
{
	string hashPassword(const string& password);
	bool verifyPassword(const string& password, const string& passwordHash);
	string toLower(const string& str);
	bool isLoginUnique(const string& login);
}