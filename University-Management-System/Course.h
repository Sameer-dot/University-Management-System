#pragma once
#include"Teacher.h"
#include"Student.h"
#include"Template.h"


class Course{

	char* Cname;
	int CourseCode;
	Teacher* Teach;
	static int noOfStuds;
	Student** listOfStudents;
	int CurrentStudents;
	static int MaxRegis;
	Registration** listOfRegistrations;
	int CurrentRegistrations;

public:
	Course();

	Course(int,char*);

	char* getCourseName();

	int getCourseCode();

	void addStudentinCourse(Student*);

	void addRegistrationinCourse(Registration*);

	void removeStudentfromCourse(int);

	int getTotalStudents();

	char* getStudentName(int);

	int getStudentCode(int);

	void markAttendance(int,bool);

	void viewAttendance(int);

	void setMarks(int,int);

	void viewMarks(int);

	void setGpa(int, float);

	void assignTeacher(Teacher*);

	void deleteStudentfromCourse(int);

	~Course();

};