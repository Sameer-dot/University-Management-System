#pragma once
#include"Person.h"

class Employee:public Person
{
	int EmpiD;
public:

	Employee();

	Employee(int,char*);

	int getiD();

};