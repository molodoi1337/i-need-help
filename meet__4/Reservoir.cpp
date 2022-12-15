#include "Reservoir.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Reservoir::Reservoir(char* name, int* deep, int* lenght, int* weght) {
	this->name = name;
	this->deep = deep;
	this->lenght = lenght;
	this->weght = weght;
	this->index = 0;
}

void Reservoir::addVodoem(char name, int deep, int lenght, int weght) {

	this->name[index] = name;     //не забыть сделать вычетание индексов!!!!!!!!
	this->deep[index] = deep;
	this->lenght[index] = lenght;
	this->weght[index] = weght;

	index++;
}

void Reservoir::show() {
	for (int i = 0; i < index; i++) {
		cout << "index-> " << i << endl;
		cout << "name-> " << name[i] << endl;
		cout << "deep-> " << deep[i] << endl;
		cout << "lenght-> " << lenght[i] << endl;
		cout << "weght-> " << weght[i] << endl;
	}
}

void  Reservoir::dell() {//как поставить на место имеющихся массивов новые?
	char* name2 = new char[index-1];
	int* deep2 = new int[index-1];
	int* lenght2 = new int[index-1];
	int* weght2 = new int[index-1];
	int a;
	cout << "which object to delete?(enter index)"<<endl;
	cin >> a;
	for (int i = 0; i < index; i++) {
		if (i != a) {
			//strcmp(name2[i], name[i]);//ggggggggggggggggggg
			name2[i] = name[i];
			deep2[i] = deep[i];
			lenght2[i] = lenght[i];
			weght2[i] = weght[i];
		}
	}
}

void  Reservoir::volume() {
	cout << "volume which object needed?";
	int b; cin >> b;
	cout << lenght * weght * deep;//опять проблемма,2 первых подчеркиваются,а последний нет
}

