#pragma once
#include"Course.h"
#include"Student.h"
#include"Teacher.h"
#include"ITMan.h"
#include"HoD.h"

class Department{
	char* Dname;

	ITMan* ITM;

	HoD* HOD;

	Student** listOfStudents;
	int CurrentStudents;

	Teacher** listOfTeachers;
	int CurrentTeachers;
	
	Course** listOfCourses;
	int CurrentCourses;

	int TotalStudent;
	int TotalTeacher;
	int TotalCourse;

public:

	Department();

	Department(char*,int);


	void addStudent(Student*);

	void addTeacher(Teacher*);

	void addCourseinDep(Course*);

	void addHOD(HoD*);

	void addITMan(ITMan*);
	
	bool FindStudent(int&,int);

	Student* getStudent(int);

	int getCoursesAvailable();

	char* getCourseName(int);

	int getCourseCode(int);

	Course* returnCourse(int);

	void addStudentinCourse(int,Student*);

	void addRegistrationinCourse(int,Registration*);

	void removeStudentfromCourse(int,int);

	Teacher* TeacherFind(int);

	int getTeachiD(int);

	int getHiD();	

	HoD* getHOD();

	int getTotalTeachers();

	char* getTeacherName(int);

	int getTeacherCode(int);

	int getTotalStudents();

	char* getStudentName(int);

	int getStudentCode(int);

	void viewMarks(int, int);

	Course* getCourse(int);

	Teacher* getTeacher(int);

	int getITManiD();

	ITMan* getITMan();

	void deleteStudent(int);

	void deleteStudentfromCourse(int);

	void deleteTeacher(int);

	~Department();

};