#include "Student.h"
#include "Registration.h"
#include"Course.h"

int Student::MaxCourses = 5;
int Student::NoOFRegistrations = 50;

Student::Student() {
	RollNo = 0;
}

Student::Student(int RN, char* Pname) :Person(Pname)
{
	RollNo = RN;
	listOfCourses = new Course * [MaxCourses];
	CurrentCourses = 0;

	listOfRegistrations = new Registration * [NoOFRegistrations];
	CurrentRegs = 0;
}

int Student::getRollNo() {
	return RollNo;
}
void Student::addCourse(Course* C) {
	listOfCourses[CurrentCourses++] = C;
}

void Student::addRegistration(Registration* R) {
	listOfRegistrations[CurrentRegs++] = R;
}

int Student::getCourseCount() {
	return CurrentCourses;
}

char* Student::getCourseName(int index) {
	return listOfCourses[index]->getCourseName();
}

int Student::getCourseCode(int index) {
	return listOfCourses[index]->getCourseCode();
}

void Student::removeCourse(int ind) {
	listOfCourses[ind] = NULL;
	Shrink(listOfCourses, ind, CurrentCourses);
	delete listOfRegistrations[ind];
	listOfRegistrations[ind] = NULL;
	Shrink(listOfRegistrations, ind, CurrentRegs);
}

void Student::WidrawCourse(int ind) {
	listOfCourses[ind] = NULL;
	Shrink(listOfCourses, ind, CurrentCourses);
	listOfRegistrations[ind]->setGpa(50);
	listOfRegistrations[ind]->setCourse(NULL);
}

float Student::getGpa(int ind) {
	return listOfRegistrations[ind]->getGpa();
}

void Student::viewMarks(int ind)
{
	return listOfRegistrations[ind]->viewMarks();
}

void Student::getallAttendanceOfCourse(int ind) {
	listOfRegistrations[ind]->getallAttendanceOfCourse();
}

char* Student::getStudentName()
{
	return getPname();
}

Student::~Student()
{
	for (int i = 0; i < CurrentCourses; ++i) {
		delete listOfCourses[i];
	}
	delete[]listOfCourses;

	for (int i = 0; i < CurrentRegs; ++i) {
		delete listOfRegistrations[i];
	}
	delete[]listOfRegistrations;


	
}


