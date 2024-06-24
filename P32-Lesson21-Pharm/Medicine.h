#pragma once
#include <iostream>
using namespace std;

enum TYPES {
	other,
	pills = 1,	//пігулки
	capsules,	//капсули
	syrop		//сироп
};

class Medicine
{
	char* _title;
	TYPES _type;
	float _price;
	char* _country;

public:
	Medicine();
	Medicine(const char* title, TYPES type, float price,const char* country);
	Medicine(const Medicine& obj); //Конструктор копіювання
	Medicine& operator = (const Medicine& obj); //Оператор присвоювання
	~Medicine();

	void setTitle(const char* title);
	void setType(TYPES type);
	void setPrice(float price);
	void setCountry(const char* country);

	const char* getTitle()const;
	TYPES getType()const;
	float getPrice()const;
	const char* getCountry()const;

	void showInfo()const;
};

