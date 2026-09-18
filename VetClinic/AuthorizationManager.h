#pragma once

namespace AuthorizationManager
{
	Person* loginUser(const string& login, const string& password);
	Client* registerClient(const string& login, const string& password, const string& firstName, const string& lastName, const string& email, const string& phone);
}