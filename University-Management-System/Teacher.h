#pragma once
#include<iostream>
#include"Employee.h"
class Course;
using namespace std;

class Teacher:public Employee
{
	int TotalCourses;
	Course** listOfCourse;
	int CurrentCourses;

public:

	Teacher();

	Teacher(int,char*);

	void addCourse(Course*);

	int getTotalCourse();

	char* getCourseName(int);

	int getCourseCode(int);

	int getTotalStudents(int);

	char* getStudentName(int, int);

	int getStudentCode(int,int);

	void markAttendance(int,int,bool);

	void viewAttendance(int, int);

	void setMarks(int,int,int);

	void viewMarks(int, int);

	void setGpa(int, int, float);

	char* getTeacherName();

	int getTeacherCode();

	~Teacher();
};