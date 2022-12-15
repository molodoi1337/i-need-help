#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class Reservoir
{
	char* name;
	int* deep;
	int* lenght;
	int* weght;
	int index;
public:
	Reservoir() : name{ new char[index+1]{"no value"} }, deep{ new int[index + 1]{NULL} }, lenght{ new int[index + 1]{NULL} }, weght{ new int[index + 1]{NULL} }, index{0} {
	}
	Reservoir(char* name, int* deep, int* lenght, int* weght);
		
	void addVodoem(char name, int deep, int lenght, int weght);
	void show();
	void dell();	
	void volume();



};

