#pragma once

class Animal
{
protected:
	int id = 0;
	string name;
	string type;
	int age = 0;
	string ownerLogin;
	vector<string> medicalHistory;
	vector<string> allergies;

public:
	Animal() = default;
	Animal(int id, const string& name, const string& type, int age, const string& ownerLogin);
	Animal(const Animal& other) = default;
	virtual ~Animal() = default;

	int getId() const;
	string getName() const;
	string getType() const;
	int getAge() const;
	string getOwnerLogin() const;
	vector<string> getMedicalHistory() const;
	vector<string> getAllergies() const;

	void setId(int id);
	void setName(const string& name);
	void setType(const string& type);
	void setAge(int age);
	void setOwnerLogin(const string& ownerLogin);
	void setMedicalHistory(const vector<string>& medicalHistory);
	void setAllergies(const vector<string>& allergies);

	void addMedicalRecord(const string& record);
	void removeMedicalRecord(const string& record);
	void addAllergy(const string& allergy);
	void removeAllergy(const string& allergy);

	virtual void input() = 0;
	virtual void displayInfo() const;

	virtual void saveToFile(ofstream& file) const;
	virtual void loadFromFile(ifstream& file);
	virtual string getClassName() const { return "ANIMAL"; }
};

class Bird : public Animal
{
protected:
	double wingspan = 0.0;
	bool canFly = true;

public:
	Bird() = default;
	Bird(int id, const string& name, const string& type, int age, const string& ownerLogin, double wingspan, bool canFly);
	Bird(const Bird& other) = default;
	virtual ~Bird() = default;

	double getWingspan() const;
	bool getCanFly() const;

	void setWingspan(double wingspan);
	void setCanFly(bool canFly);

	void input() override;
	void displayInfo() const override;

	void saveToFile(ofstream& file) const override;
	void loadFromFile(ifstream& file) override;
	string getClassName() const override { return "BIRD"; }
};

class Mammal : public Animal
{
protected:
	string furType;
	bool isVaccinated = true;

public:
	Mammal() = default;
	Mammal(int id, const string& name, const string& type, int age, const string& ownerLogin, const string& furType, bool isVaccinated);
	Mammal(const Mammal& other) = default;
	virtual ~Mammal() = default;

	string getFurType() const;
	bool getIsVaccinated() const;

	void setFurType(const string& furType);
	void setIsVaccinated(bool isVaccinated);

	void input() override;
	void displayInfo() const override;

	void saveToFile(ofstream& file) const override;
	void loadFromFile(ifstream& file) override;
	string getClassName() const override { return "MAMMAL"; }
};

class Reptile : public Animal
{
protected:
	double bodyTemperature = 0.0;
	bool isVenomous = true;

public:
	Reptile() = default;
	Reptile(int id, const string& name, const string& type, int age, const string& ownerLogin, double bodyTemperature, bool isVenomous);
	Reptile(const Reptile& other) = default;
	virtual ~Reptile() = default;

	double getBodyTemperature() const;
	bool getIsVenomous() const;

	void setBodyTemperature(double bodyTemperature);
	void setIsVenomous(bool isVenomous);

	void input() override;
	void displayInfo() const override;

	void saveToFile(ofstream& file) const override;
	void loadFromFile(ifstream& file) override;
	string getClassName() const override { return "REPTILE"; }
};