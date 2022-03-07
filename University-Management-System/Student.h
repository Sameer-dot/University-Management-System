#pragma once
#include<iostream>
#include"Person.h"
#include"Template.h"
class Registration;
class Course;
using namespace std;

class Student:public Person
{
	int RollNo;
	
	static int MaxCourses;
	Course** listOfCourses;
	int CurrentCourses;

	static int NoOFRegistrations;
	Registration** listOfRegistrations;
	int CurrentRegs;

public:

	Student();

	Student(int,char*);

	int getRollNo();

	void addCourse(Course*);

	void addRegistration(Registration*);

	int getCourseCount();

	char* getCourseName(int);

	int getCourseCode(int);

	void removeCourse(int);

	void WidrawCourse(int);

	float getGpa(int);

	void viewMarks(int);

	void getallAttendanceOfCourse(int);

	char* getStudentName();

	~Student();
};
