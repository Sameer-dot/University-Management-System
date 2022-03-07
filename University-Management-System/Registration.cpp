#include<iostream>
#include"Registration.h"
#include"Course.h"
using namespace std;

Registration::Registration(){
	GPA=0;
}

Registration::Registration(Student* S,Course* C,float gpa){
	Sid=S;
	Cid=C;
	GPA=gpa;
	listOfAttendance=new bool[30];
	CurrentAttendance = 0;

	listOfMarks = new int[4];
	CurrentMarks = 0;
} 

void Registration::setGpa(float gpa){
	this->GPA=gpa;
}

float Registration::getGpa(){
	return GPA;
}

void Registration::setCourse(Course* C)
{
	Cid=C;
}

void Registration::getallAttendanceOfCourse(){
	for(int i=0;i<CurrentAttendance;i++){
		cout << endl;
		cout<<"Lecture No "<<i<<". ";
		cout<<listOfAttendance[i];
	}
}

void Registration::markAttendance(bool Pres)
{
	listOfAttendance[CurrentAttendance++] = Pres;
}

void Registration::viewAttendance()
{
	for (int i = 0; i < CurrentAttendance; i++) {
		cout << listOfAttendance[i]<< "   ";
	}
}

void Registration::setMarks(int Marks)
{
	listOfMarks[CurrentMarks++] = Marks;
}

void Registration::viewMarks()
{
	for (int i = 0; i < CurrentMarks; i++) {
		cout << listOfMarks[i] << "   ";
	}
}

Registration::~Registration()
{
	delete[]listOfAttendance;
	delete[]listOfMarks;
}
