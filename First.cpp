#include "stdafx.h"
#include <string>
#include "First.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string surname, name , middleName, zodiacSign, descriprion, phoneNumber;
int day, month, year;
char symbols;

Application::Application() {}

struct FO {

	bool operator()(User a) {

		bool result1 = (year == a.Year()
			? (month == a.Month() ? day <= a.Day() : false)
			: !(year > a.Year()));

		bool result2 = (surname == a.GetTarget1() ? (name == a.GetTarget2() ? (middleName == a.GetTarget3()) : false)
			: !(surname != a.GetTarget1()));	

		return surname == a.GetTarget1() && result1 && result2;
	}
};

void Application::Read() {
	string namefile = "txt.txt";

	try {
		ifstream ifsInputFile(namefile);
		if (!ifsInputFile.is_open()) {
			cout << "Can't open this file!" << endl;
			return;
		}

		while (!ifsInputFile.eof()) {
			ifsInputFile >> surname >> name >> middleName >> zodiacSign >> day >> symbols >> month >> symbols >> year >> phoneNumber >> descriprion;

			vec1.push_back(User(surname, name, middleName, zodiacSign, new int[3]{ day, month, year }, phoneNumber, descriprion));

			map1.insert(pair<string, User>(surname, User(surname, name, middleName, zodiacSign, new int[3]{ day, month, year }, phoneNumber, descriprion)));
		}
	}
	catch (const exception&) {
		cout << "We got some problems!" << endl;
	}
}

void Application::SearchWithMap() {
	int cou = map1.count(surname);
	int i = 0;
	auto itm = map1.find(surname);
	bool result1, result2;	
	while( i < cou) {
		result1 = (year == (*itm).second.Year()
			? (month == (*itm).second.Month() ? day == (*itm).second.Day() : false)
			: (year >(*itm).second.Year()));
		result2 = (surname == (*itm).second.GetTarget1() ? (name == (*itm).second.GetTarget2() ? middleName == (*itm).second.GetTarget3() :false): (surname !=(*itm).second.GetTarget1()));
		if (result1 && result2)
			cout << (*itm).first << " " << (*itm).second.GetTarget2() << " " << (*itm).second.Day() << " " << (*itm).second.Month()<<" " << (*itm).second.Year() << " " << (*itm).second.GetTarget3()  << " " << (*itm).second.PhoneNumber() << " " << (*itm).second.ZodiacSign()<< " " << (*itm).second.Description() << endl;
		++itm;
		++i;
	}
}

void Application::SeachWithVector() {
	vector<User>::iterator it = vec1.begin();
	cout << "Result: ";
	while (it != vec1.end()) {
		it = find_if(it, vec1.end(), FO());
		if (it != vec1.end()) {		
			cout << it->GetTarget1() << " " << it->GetTarget2() << " " << it->GetTarget3() << " " << it->Day() << " " << it->Month() << " " << it->Year() << " " << it->PhoneNumber() << " " << it->ZodiacSign() << " " << it->Description();
			++it;
		}
	}
	cout << endl;
}

void Application::FullNameUser() {
	cout << "Input you full name!"<< endl;
	cin >> surname;
	cin >> name;
	cin >> middleName;
}

void Application::DateOfBirth() {
	cout << "Input your date of birht!"<<endl;
	cin >> day;
	cin >> month;
	cin >> year;

}

Application::~Application() { }