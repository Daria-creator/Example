#pragma once

#include "stdafx.h"
#include "Second.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Application
{
private:

	multimap <string, User> map1;

	vector<User> vec1;

public :
	Application();
	void Read();
	void SearchWithMap();
	void SeachWithVector();
	void FullNameUser();
	void DateOfBirth();
	~Application();
};


