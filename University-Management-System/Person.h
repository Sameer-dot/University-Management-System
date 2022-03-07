#pragma once
#include<iostream>
using namespace std;

class Person{
	char* Pname;
public:
	Person();

	Person(char*);

	char* getPname();

	~Person();

};