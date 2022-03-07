#include<iostream>
#include"Person.h"
using namespace std;

Person::Person(){
	Pname=NULL;
}

Person::Person(char *PN){
	int size=strlen(PN);
	Pname=new char[size+1];
	int i=0;
	for(i=0; PN[i]!='\0'; i++)
	{
		Pname[i]=PN[i];
	}
	Pname[i]='\0';
}

char* Person::getPname()
{
	return Pname;
}

Person::~Person()
{
	delete[]Pname;
}
