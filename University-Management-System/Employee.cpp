#include<iostream>
#include"Employee.h"
using namespace std;


Employee::Employee() {
	EmpiD = 0;
}

Employee::Employee(int EiD, char* Pname) :Person(Pname) {
	EmpiD = EiD;
}

int Employee::getiD()
{
	return EmpiD;
}

