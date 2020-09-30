#include "stdafx.h"
#include "Second.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

User::User()
{
}

User::User(string s, string n, string m, string z, int d[3], string p, string des  ) : Target1(s),Target2(n),Target3(m), zodiacSign(z), phoneNumber(p), description(des)
{
	for (int i = 0; i < 3; ++i)

		Date[i] = d[i];
}

string User::GetTarget1()
{
	return Target1;
}

string User::GetTarget2()
{
	return Target2;
}

string User::GetTarget3()
{
	return Target3;
}

string User::PhoneNumber()
{
	return phoneNumber;
}

string User::ZodiacSign()
{
	return zodiacSign;
}

string User::Description()
{
	return description;
}

int User::Day()
{
	return Date[0];
}

int User::Month()
{
	return Date[1];
}

int User::Year()
{
	return Date[2];
}

User::~User() { }