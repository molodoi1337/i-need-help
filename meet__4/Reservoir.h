#pragma once
#include <Windows.h>
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

class Reservoir
{
	string* name;
	int* deep;
	int* lenght;
	int* weght;
	int index = 0;
	string* type;
public:
	Reservoir() : name{ new string[35]{"no value"} }, deep{ new int[25]{NULL} }, lenght{ new int[25]{NULL} }, weght{ new int[26]{NULL} }, type{ new string[15]{"lake"}}{}
	Reservoir(string* name, int* deep, int* lenght, int* weght, string type);
		
	void AddVodoem(string name, int deep, int lenght, int weght, string type);// type(sea, ocean, lake or river)"<<endl;
	void Show();
	void Dell();	
	void Volume();
	void Menu();
	void Square();
	bool Check();
	char comparison();
	void Writing_File();
};

