#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class User {
private:
	string Target1 = "", Target2 = "", Target3 = "", zodiacSign = "", phoneNumber = "", description = "";
	int Date[3];
public:
	User();
	User(string, string, string, string,int[3], string, string);
	string GetTarget1();
	string GetTarget2();
	string GetTarget3();
	string PhoneNumber();
	string ZodiacSign();
	string Description();
	int Day();
	int Month();
	int Year();
	~User();
};