#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include "Second.h"
#include "First.h"
using namespace std ;

void PrintMenu() {
	cout << "Menu:" << endl;
	cout << "1 - Load info from file" << endl;
	cout << "2 - Enter a person's data" << endl;
	cout << "3 - Get result" << endl;
	cout << "0 - Exit" << endl;
}

void PrintSubMenu() {
	cout << "1 - Vector" << endl;
	cout << "2 - Map" << endl;
}

void main() {
	setlocale(LC_ALL, "Russian");
	int iMenu = -1, iSubMenu = -1;
	PrintMenu();
	Application* a = new Application();
	string filename = "txt.txt";
	while (iMenu != 0) {
		cout << "Select item - ";
		cin >> iMenu;
		switch (iMenu) {
			case 1:
			{
				a->Read();
				break;
			}
			case 2:
			{
				a->FullNameUser();
				a->DateOfBirth();
				break;
			}
			case 3:
			{
				PrintSubMenu();
				cin >> iSubMenu;
				if (iSubMenu == 1)
					a->SeachWithVector();
				else if (iSubMenu == 2)
					a->SearchWithMap();
				break;
			}
		}
	}
	delete a;	
}
