#include<iostream>
#include"Department.h"
#include"Student.h"
using namespace std;

Department::Department() {
	Dname = NULL;
}

Department::Department(char* DN, int ToC) {
	int size = strlen(DN);
	Dname = new char[size + 1];
	int i = 0;
	for (i = 0; DN[i] != '\0'; i++)
	{
		Dname[i] = DN[i];
	}
	Dname[i] = '\0';

	TotalCourse = 1;
	listOfCourses = new Course * [TotalCourse];
	CurrentCourses = 0;

	TotalStudent = 1;
	listOfStudents = new Student * [TotalStudent];
	CurrentStudents = 0;

	TotalTeacher = 1;
	listOfTeachers = new Teacher * [TotalTeacher];
	CurrentTeachers = 0;
}

void Department::addStudent(Student* S) {
	if (CurrentStudents == TotalStudent)
	{
		Grow(listOfStudents, TotalStudent);
	}
	listOfStudents[CurrentStudents++] = S;
}

void Department::addTeacher(Teacher* T) {
	if (CurrentTeachers == TotalTeacher)
	{
		Grow(listOfTeachers, TotalTeacher);
	}
	listOfTeachers[CurrentTeachers++] = T;
}


void Department::addHOD(HoD* H) {
	HOD = H;
}

void Department::addITMan(ITMan* IT)
{
	ITM = IT;
}

void Department::addCourseinDep(Course* C) {
	if (CurrentCourses == TotalCourse)
	{
		Grow(listOfCourses, TotalCourse);
	}
	listOfCourses[CurrentCourses++] = C;
}

bool Department::FindStudent(int& StudNo, int Rno) {
	for (int i = 0; i < CurrentStudents; i++)
	{
		if (listOfStudents[i]->getRollNo() == Rno) {
			StudNo = i;
			return true;
		}
	}
	return false;
}

Student* Department::getStudent(int SNo) {

	for (int i = 0; i < CurrentStudents; i++)
	{
		return listOfStudents[SNo];
	}
}

int Department::getCoursesAvailable() {
	return CurrentCourses;
}

char* Department::getCourseName(int ind) {
	return listOfCourses[ind]->getCourseName();
}

int Department::getCourseCode(int ind) {
	return listOfCourses[ind]->getCourseCode();
}

Course* Department::returnCourse(int ind) {
	return listOfCourses[ind];
}

void Department::addStudentinCourse(int ind, Student* S) {
	listOfCourses[ind]->addStudentinCourse(S);
}

void Department::addRegistrationinCourse(int ind, Registration* R) {
	listOfCourses[ind]->addRegistrationinCourse(R);
}

void Department::removeStudentfromCourse(int Ccode, int RollNo) {
	for (int i = 0; i < CurrentCourses; i++) {

		if (listOfCourses[i]->getCourseCode() == Ccode) {
			listOfCourses[i]->removeStudentfromCourse(RollNo);
		}
	}
}

Teacher* Department::TeacherFind(int TiD)
{
	for (int i = 0; i < CurrentTeachers; i++) {
		if (listOfTeachers[i]->getiD() == TiD) {
			return listOfTeachers[i];
		}
	}
}

int Department::getTeachiD(int TeachiD) {
	for (int i = 0; i < CurrentTeachers; i++) {
		if (listOfTeachers[i]->getiD() == TeachiD) {
			return listOfTeachers[i]->getiD();
		}
	}
}

int Department::getHiD()
{
	return HOD->getiD();
}

HoD* Department::getHOD()
{
	return HOD;
}


int Department::getTotalTeachers()
{
	return CurrentTeachers;
}

char* Department::getTeacherName(int ind)
{
	return listOfTeachers[ind]->getTeacherName();
}

int Department::getTeacherCode(int ind)
{
	return listOfTeachers[ind]->getTeacherCode();
}

int Department::getTotalStudents()
{
	return CurrentStudents;
}

char* Department::getStudentName(int ind)
{
	return listOfStudents[ind]->getStudentName();
}

int Department::getStudentCode(int ind)
{
	return listOfStudents[ind]->getRollNo();
}

void Department::viewMarks(int Cind, int Sind)
{
	listOfCourses[Cind]->viewMarks(Sind);
}

Course* Department::getCourse(int ind)
{
	return listOfCourses[ind];
}

Teacher* Department::getTeacher(int i)
{
	return listOfTeachers[i];
}

int Department::getITManiD()
{
	return ITM->getiD();
}

ITMan* Department::getITMan()
{
	return ITM;
}

void Department::deleteStudent(int RollNo)
{
	for (int i = 0; i < CurrentStudents; i++) {
		if (listOfStudents[i]->getRollNo() == RollNo)
		{
			delete listOfStudents[i];
			Shrink(listOfStudents, i, CurrentStudents);
		}
	}
}

void Department::deleteStudentfromCourse(int RollNo)
{
	for (int i = 0; i < CurrentCourses; i++) {
		for (int j = 0; j < listOfCourses[i]->getTotalStudents(); j++) {

			if (listOfCourses[i]->getStudentCode(j) == RollNo) {
				listOfCourses[i]->deleteStudentfromCourse(i);
			}
		}
	}
}

void Department::deleteTeacher(int TCode)
{
	for (int i = 0; i < CurrentTeachers; i++) {
		if (listOfTeachers[i]->getTeacherCode() == TCode)
		{
			delete listOfTeachers[i];
			Shrink(listOfTeachers, i, CurrentTeachers);
		}
	}
}

Department::~Department()
{
	delete[]Dname;

	for (int i = 0; i < CurrentCourses; ++i) {
		delete listOfCourses[i];
	}
	delete[]listOfCourses;

	for (int i = 0; i < CurrentStudents; ++i) {
		delete listOfStudents[i];
	}
	delete[]listOfStudents;

	for (int i = 0; i < CurrentTeachers; ++i) {
		delete listOfTeachers[i];
	}
	delete[]listOfTeachers;
}



