#include<iostream>
#include"Teacher.h"
#include"Course.h"
using namespace std;

Teacher::Teacher(){

}

Teacher::Teacher(int Tc,char* Pname):Employee(Tc,Pname)
{
	TotalCourses = 0;
	listOfCourse = new Course * [TotalCourses];
	CurrentCourses = 0;
}

void Teacher::addCourse(Course* C)
{
	if (CurrentCourses == TotalCourses)
	{
		Grow(listOfCourse, TotalCourses);
	}
	listOfCourse[CurrentCourses++] = C;
}

int Teacher::getTotalCourse()
{
	return CurrentCourses;
}

char* Teacher::getCourseName(int ind) 
{
	return listOfCourse[ind]->getCourseName();
}

int Teacher::getCourseCode(int ind)
{
	return listOfCourse[ind]->getCourseCode();
}

int Teacher::getTotalStudents(int ind)
{
	return listOfCourse[ind]->getTotalStudents();
}

char* Teacher::getStudentName(int Cind, int Sind)
{
	return listOfCourse[Cind]->getStudentName(Sind);
}

int Teacher::getStudentCode(int Cind, int Sind)
{
	return listOfCourse[Cind]->getStudentCode(Sind);
}

void Teacher::markAttendance(int Cind,int Sind,bool Pres)
{
	listOfCourse[Cind]->markAttendance(Sind,Pres);
}

void Teacher::viewAttendance(int Cind, int Sind)
{
	 listOfCourse[Cind]->viewAttendance(Sind);
}

void Teacher::setMarks(int Cind, int Sind, int Marks)
{
	listOfCourse[Cind]->setMarks(Sind, Marks);
}

void Teacher::viewMarks(int Cind, int Sind)
{
	listOfCourse[Cind]->viewMarks(Sind);
}

void Teacher::setGpa(int Cind, int Sind, float gpa)
{
	listOfCourse[Cind]->setGpa(Sind,gpa);
}

char* Teacher::getTeacherName()
{
	return getPname();
}

int Teacher::getTeacherCode()                         //iskoConfirmkrnaha
{
	return getiD();
}

Teacher::~Teacher()
{
	for (int i = 0; i < CurrentCourses; ++i) {
		delete listOfCourse[i];
	}
	delete[]listOfCourse;
}

