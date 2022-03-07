#include<iostream>
#include"University.h"
using namespace std;
University::University() {
	Uname = NULL;
}

University::University(char* UN, int TD) {
	int size = strlen(UN);
	Uname = new char[size + 1];
	int i = 0;
	for (i = 0; UN[i] != '\0'; i++)
	{
		Uname[i] = UN[i];
	}
	Uname[i] = '\0';

	TDeparts = 1;
	listOfDepartments = new Department * [TDeparts];
	noOfDep = 0;

}

char* University::getUniversityname()
{
	return Uname;
}

void University::addDepartment(Department* D) {
	if (noOfDep == TDeparts)
	{
		Grow(listOfDepartments, TDeparts);
	}
	listOfDepartments[noOfDep++] = D;
}

void University::addCourseinDep(int ind, Course* C) {
	listOfDepartments[ind]->addCourseinDep(C);
}

void University::addStudent(int ind, Student* S) {
	listOfDepartments[ind]->addStudent(S);
}

void University::addTeacher(int ind, Teacher* T) {
	listOfDepartments[ind]->addTeacher(T);
}

void University::addHOD(int ind, HoD* H) {
	listOfDepartments[ind]->addHOD(H);
}

void University::addITMan(int ind, ITMan* IT)
{
	listOfDepartments[ind]->addITMan(IT);
}

void University::StudentFind(int& DNo, int& StudNo, int RNo) {
	for (int i = 0; i < noOfDep; i++)
	{
		if (listOfDepartments[i]->FindStudent(StudNo, RNo))
		{
			DNo = i;
		}
	}
}

Student* University::getStudent(int DNo, int SNo) {
	return listOfDepartments[DNo]->getStudent(SNo);
}

int University::getCoursesAvailable(int DepNo) {
	return listOfDepartments[DepNo]->getCoursesAvailable();
}

char* University::getCourseName(int DNo, int ind) {
	return listOfDepartments[DNo]->getCourseName(ind);
}

int University::getCourseCode(int DNo, int ind) {
	return listOfDepartments[DNo]->getCourseCode(ind);
}

Course* University::returnCourse(int DNo, int ind) {
	return listOfDepartments[DNo]->returnCourse(ind);
}

void University::addStudentinCourse(int DNo, int ind, Student* S) {
	listOfDepartments[DNo]->addStudentinCourse(ind, S);

}

void University::addRegistrationinCourse(int DNo, int ind, Registration* R) {
	listOfDepartments[DNo]->addRegistrationinCourse(ind, R);
}

void University::removeStudentfromCourse(int DNo, int Ccode, int RNo) {
	listOfDepartments[DNo]->removeStudentfromCourse(Ccode, RNo);
}

Teacher* University::TeacherFind(int& DNo, int TeachiD) {
	for (int i = 0; i < noOfDep; i++) {
		if (listOfDepartments[i]->getTeachiD(TeachiD) == TeachiD) {
			DNo = i;
			return listOfDepartments[DNo]->TeacherFind(TeachiD);
		}

	}
}


HoD* University::HODFind(int& DNo, int HiD)
{
	for (int i = 0; i < noOfDep; i++) {
		if (listOfDepartments[i]->getHiD() == HiD)
		{
			DNo = i;
			return listOfDepartments[i]->getHOD();
		}
	}
}

int University::getTotalTeachers(int DNo)
{
	return listOfDepartments[DNo]->getTotalTeachers();
}

char* University::getTeacherName(int DNo, int ind)
{
	return listOfDepartments[DNo]->getTeacherName(ind);
}

int University::getTeacherCode(int DNo, int ind)
{
	return listOfDepartments[DNo]->getTeacherCode(ind);
}

int University::getTotalStudents(int DNo)
{
	return listOfDepartments[DNo]->getTotalStudents();
}

char* University::getStudentName(int DNo, int ind)
{
	return listOfDepartments[DNo]->getStudentName(ind);
}

int University::getStudentCode(int DNo, int ind)
{
	return listOfDepartments[DNo]->getStudentCode(ind);
}

void University::viewMarks(int DNo, int Cind, int Sind)
{
	listOfDepartments[DNo]->viewMarks(Cind, Sind);
}

Course* University::getCourse(int DNo, int ind)
{
	return listOfDepartments[DNo]->getCourse(ind);
}

Teacher* University::getTeacher(int DNo, int ind)
{
	return listOfDepartments[DNo]->getTeacher(ind);
}

ITMan* University::ITManagerFind(int& DNo, int ITMiD)
{
	for (int i = 0; i < noOfDep; i++) {
		if (listOfDepartments[i]->getITManiD() == ITMiD) {
			DNo = i;
			return listOfDepartments[i]->getITMan();
		}
	}
}

void University::deleteStudent(int DepNo, int RollNo)
{
	listOfDepartments[DepNo]->deleteStudent(RollNo);
}

void University::deleteStudentfromCourse(int DepNo, int RollNo)
{
	listOfDepartments[DepNo]->deleteStudentfromCourse(RollNo);
}

void University::deleteTeacher(int DepNo, int TCode)
{
	listOfDepartments[DepNo]->deleteTeacher(TCode);
}

University::~University()
{
	delete[]Uname;

	for (int i = 0; i < noOfDep; ++i) {
		delete listOfDepartments[i];
	}

	delete[]listOfDepartments;
}
