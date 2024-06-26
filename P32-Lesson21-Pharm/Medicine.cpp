#include "Medicine.h"

Medicine::Medicine()
{
	_title = new char[10] {"undefined"};
	_type = TYPES::other;
	_price = 0;
	_country = new char[8] {"Ukraine"};
}

Medicine::Medicine(const char* title, TYPES type, float price, const char* country)
{
	int sizeTitle = strlen(title) + 1; //Порахували розмір
	_title = new char[sizeTitle];//Виділили пам'ять під рядок
	strcpy_s(_title, sizeTitle, title);//Скопіювали символи

	_type = type;
	_price = price;

	int sizeCountry = strlen(country) + 1; //Порахували розмір
	_country = new char[sizeCountry];//Виділили пам'ять під рядок
	strcpy_s(_country, sizeCountry, country);//Скопіювали символи
}

Medicine::Medicine(const Medicine& obj)
{
	int sizeT = strlen(obj._title) + 1;
	this->_title = new char[sizeT];
	strcpy_s(this->_title, sizeT, obj._title);

	this->_type = obj._type;
	this->_price = obj._price;

	int sizeC = strlen(obj._country) + 1;
	this->_country = new char[sizeC];
	strcpy_s(this->_country, sizeC, obj._country);
}

Medicine& Medicine::operator=(const Medicine& obj)
{
	this->~Medicine();

	int sizeT = strlen(obj._title) + 1;
	this->_title = new char[sizeT];
	strcpy_s(this->_title, sizeT, obj._title);

	this->_type = obj._type;
	this->_price = obj._price;

	int sizeC = strlen(obj._country) + 1;
	this->_country = new char[sizeC];
	strcpy_s(this->_country, sizeC, obj._country);

	return *this;
}

Medicine::~Medicine()
{
	delete[] _title;
	delete[] _country;
}

void Medicine::setTitle(const char* title)
{
	if (strlen(title) >= 2) {
		delete[] _title;

		int sizeTitle = strlen(title) + 1; //Порахували розмір
		_title = new char[sizeTitle];//Виділили пам'ять під рядок
		strcpy_s(_title, sizeTitle, title);//Скопіювали символи
	}
}

void Medicine::setType(TYPES type)
{
	_type = type;
}

void Medicine::setPrice(float price)
{
	if (price > 0) {
		_price = price;
	}
}

void Medicine::setCountry(const char* country)
{
	if (strlen(country) >= 2) {
		delete[] _country;

		int sizeCountry = strlen(country) + 1; //Порахували розмір
		_country = new char[sizeCountry];//Виділили пам'ять під рядок
		strcpy_s(_country, sizeCountry, country);//Скопіювали символи
	}
}

const char* Medicine::getTitle() const{ 	return _title;}
TYPES Medicine::getType() const{	return _type;}
float Medicine::getPrice() const{	return _price;}
const char* Medicine::getCountry() const{	return _country;}

void Medicine::showInfo() const{
	cout << "Title: " << _title << endl;
	cout << "Type: ";
	switch (_type)	{
	case other: cout << "other.\n";		break;
	case pills:	cout << "pills.\n";		break;
	case capsules:	cout << "capsules.\n";		break;
	case syrop:	cout << "syrop.\n";		break;
	}
	cout << "Price: " << _price << " UAH\n";
	cout << "Country: " << _country << "\n\n";
}
