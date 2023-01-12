#include "Reservoir.h"
#include <Windows.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Reservoir::Reservoir(string* name, int* deep, int* lenght, int* weght, string type) {
	this->name = name;
	this->deep = deep;
	this->lenght = lenght;
	this->weght = weght;
	this->index = 1;
}

void Reservoir::AddVodoem(string name, int deep, int lenght, int weght, string type) {        //cout << "add name,deep,lenght,weght,type(sea,ocean,lake or river)"<<endl;
	system("cls");
	//if (type != "sea" || "ocean" || "lake" || "river") exit(0);
	this->name[index] = name;     
	this->deep[index] = deep;
	this->lenght[index] = lenght;
	this->weght[index] = weght;
	this->type[index] = type;
	index++;
}

void Reservoir::Show() {
	system("cls");
	for (int i = 0; i < index; i++) {
		cout << "index-> " << i << endl;
		cout << "name-> " << name[i] << endl;
		cout << "deep-> " << deep[i] << endl;
		cout << "lenght-> " << lenght[i] << endl;
		cout << "weght-> " << weght[i] << endl;
		cout << "type-> " << type[i] << endl;
		cout << endl;
	}
	cout << endl;
}

void  Reservoir::Dell() {
	system("cls");
	string* name2 = new string[index-1];
	int* deep2 = new int[index-1];
	int* lenght2 = new int[index-1];
	int* weght2 = new int[index-1];
	string* type2 = new string[index - 1];
	int a;
	cout << "which object to delete?(enter index)"<<endl;
	Show();
	cin >> a;
	for (int i = 0, j = 0; i < index; j < i, i++, j++) {
		if (i != a) {
			name2[j] = name[i];
			deep2[j] = deep[i];
			lenght2[j] = lenght[i];
			weght2[j] = weght[i];
			type2[j] = type[i];
		}
		else
			j--;
	}
	delete[] name;
	delete[] deep;
	delete[] lenght;
	delete[] weght;
	delete[]type;
	name = name2;
	deep = deep2;
	lenght = lenght2;
	weght = weght2;
	type = type2;
	index--;
}

void  Reservoir::Volume() {
	system("cls");
	cout << "volume which object needed?(index)"<<endl;
	Show();
	int b; cin >> b;
	cout << lenght[b] * weght[b] * deep[b]/3<<" " << "km^3 (m^3)  смотр€ что указывали в параметрах" << endl;
}

void Reservoir::Square() {
	system("cls");
	cout << "полощадь какого водоема нужна?(enter index)";
	Show(); int a; cin >> a;

	cout<<weght[a]* lenght[a]<<" "<<"m^3/km^3(в зависимости от ед.из. введенных данных" << endl;
	
}

bool Reservoir::Check() {
	system("cls");
	cout << "типы каких водоемов нужно сравнить ?(enter index)" << endl;
	Show();
	cout << "введите индекс 1-ого водоема" << endl; int a; cin >> a;
	cout << "введите индекс 2-ого водоема" << endl; int b; cin >> b;

	if (type[a] == type[b]) return true;
	else return false;
}

char Reservoir::comparison() {
	cout << "полощади каких водоемов нужно сравнить ?(enter index)"<<endl; int a, b;
	Show();
	cout << "введите индекс 1-ого водоема" << endl; cin >> a;
	cout << "введите индекс 2-ого водоема" << endl; cin >> b; 

	int a2 = weght[a] * lenght[a], b2 = weght[b] * lenght[b];
	if (a2 == b2) return '=';
	else if (a2 > b2) return '>';
	else return '<';
	
}

void Reservoir::Writing_File() {
	cout << "ƒанные о каком водоеме хотите занести в файл?(enter index)"<<endl;
	int a; cin >> a;
	string path;
	ofstream out;
	cout << "укажите путь к файлу(пример:D:\\file.txt)\n≈сли файла с таким названием нет,то он создастс€ автоматически."<<endl;
	cin >> path;
	out.open(path,ios::app);
	if (out.is_open()) {   
		out << "index-> " << a << endl;
		out << "name-> " << name[a] << endl;
		out << "deep-> " << deep[a] << endl;
		out << "lenght-> " << lenght[a] << endl;
		out << "weght-> " << weght[a] << endl;
		out << "type-> " << type[a] << endl;
	}
	out << "-----------------------------------------------\n";
	out.close();
}

void Reservoir::Menu() {
	system("cls");
	string str = "1->add \n2->delete\n3->show\n4->volume\n5->square\n6->checking for uniformity\n7->comparison square\n8->writing ot a file\n0->exit";
	int a;
	string name,type; int deep, lenght, weght;
	do {
		cout << str;
		cin >> a;

		switch (a)
		{
		case 1:
			cout << "enter name,deep,lenght,weght,type:" << endl;	
			cin >> name >> deep >> lenght >> weght>>type;
			Reservoir::AddVodoem(name, deep, lenght, weght,type);
			break;
		case 2:
			Dell();
			break;
		case 3:
			Show();
		case 4:
			Volume();
			break;
		case 5:
			Square();
		case 6:
			Check();
		case 7:
			comparison();
		case 8:
			Writing_File();
		default:
			break;
		}
	} while (a != 0);

}
