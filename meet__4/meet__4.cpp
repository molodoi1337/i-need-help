#include <Windows.h>
#include <iostream>
#include "Reservoir.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Reservoir r;

    r.AddVodoem("bakal",14,55,23,"sea");
    r.AddVodoem("bub",14,33,75,"sea");
    r.Menu();
 
    
}

