#pragma once
#define NOMINMAX

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <concepts>
#include <functional>
#include <random>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <locale>
#include <map>
#include <windows.h>

using namespace std;

inline bool danetka(const string& prompt) {
    cout << prompt + ": ";

    do {
        string answer;
        getline(cin, answer);
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "да" || answer == "д") return true;
        else if (answer == "нет" || answer == "н") return false;
        else cout << "Пожалуйста, введите 'да' или 'нет': ";
    } while (true);
}

inline static string toLower(const string& str) {
    string result = str;
    for (char& c : result)  c = tolower(c);
    return result;
}

inline static string getCurrentDate() {
    time_t now = time(0);
    struct tm localTime;
    localtime_s(&localTime, &now);

    stringstream ss;
    ss << setw(2) << setfill('0') << localTime.tm_mday << "." << setw(2) << setfill('0') << (localTime.tm_mon + 1) << "." << (localTime.tm_year + 1900);
    return ss.str();
}

inline static string getDayOfWeekName(const string& date) {
    vector<string> days = { "пн", "вт", "ср", "чт", "пт", "сб", "вс" };

    size_t firstDot = date.find('.');
    string dayStr = date.substr(0, firstDot);
    int dayNumber = stoi(dayStr);

    string monthYear = date.substr(firstDot + 1);

    if (monthYear == "12.2025") 
    {
        return days[(dayNumber - 1) % 7];
    }
    else if (monthYear == "01.2026") 
    {
        return days[(dayNumber + 2) % 7];
    }
    else if (monthYear == "02.2026") 
    {
        return days[(dayNumber + 5) % 7];
    }

    return days[dayNumber % 7];
}

template<typename T>
T chek(const string& prompt, const string& error, function<T(T)> customCheck = [](T x) { return true; }) {
    cout << "\033[s";
    cout << prompt + ": ";

    T n;
    while (!(cin >> n) || !customCheck(n)) {
        cout << "\033[u" << "\033[0J";
        cerr << error + "! Введите ещё раз: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    return n;
}