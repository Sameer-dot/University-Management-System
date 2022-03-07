#include<iostream>
#include"Course.h"
#include"Registration.h"
using namespace std;

int Course::noOfStuds = 50;
int Course::MaxRegis = 50;

Course::Course() {
	Cname = NULL;
}

Course::Course(int Ccode, char* CN) {

	CourseCode = Ccode;

	int size = strlen(CN);
	Cname = new char[size + 1];
	int i = 0;
	for (i = 0; CN[i] != '\0'; i++)
	{
		Cname[i] = CN[i];
	}
	Cname[i] = '\0';



	listOfStudents = new Student* [noOfStuds];
	CurrentStudents = 0;

	listOfRegistrations = new Registration* [MaxRegis];
	CurrentRegistrations = 0;
}

char* Course::getCourseName() {
	return Cname;
}

int Course::getCourseCode() {
	return CourseCode;
}

void Course::addStudentinCourse(Student* S) {
	listOfStudents[CurrentStudents++] = S;
}

void Course::addRegistrationinCourse(Registration* R) {
	listOfRegistrations[CurrentRegistrations++] = R;
}

void Course::removeStudentfromCourse(int RollNo) {
	for (int i = 0; i < CurrentStudents; i++) {
		if (listOfStudents[i]->getRollNo() == RollNo) {
			listOfStudents[i] = NULL;
			Shrink(listOfStudents, i, CurrentStudents);
		}
	}
}

int Course::getTotalStudents()
{
	return CurrentStudents;
}

char* Course::getStudentName(int Sind)
{
	return listOfStudents[Sind]->getStudentName();
}

int Course::getStudentCode(int Sind)
{
	return listOfStudents[Sind]->getRollNo();
}

void Course::markAttendance(int Rind, bool Pres)
{
	listOfRegistrations[Rind]->markAttendance(Pres);
}

void Course::viewAttendance(int Sind)
{
	listOfRegistrations[Sind]->viewAttendance();
}

void Course::setMarks(int Sind, int Marks)
{
	listOfRegistrations[Sind]->setMarks(Marks);
}

void Course::viewMarks(int Sind)
{
	listOfRegistrations[Sind]->viewMarks();
}

void Course::setGpa(int Sind, float gpa)
{
	listOfRegistrations[Sind]->setGpa(gpa);
}

void Course::assignTeacher(Teacher* T)
{
	Teach = T;
}



void Course::deleteStudentfromCourse(int ind)
{
	listOfStudents[ind]=NULL;
	Shrink(listOfStudents, ind, CurrentStudents);
}

Course::~Course()
{
	delete []Cname;

	for (int i = 0; i < CurrentRegistrations; ++i) {
		delete listOfRegistrations[i];
	}
	delete[]listOfRegistrations;

	for (int i = 0; i < CurrentStudents; ++i) {
		delete listOfStudents[i];
	}

	delete[]listOfStudents;
}


