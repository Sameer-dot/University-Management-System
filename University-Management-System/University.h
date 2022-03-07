#pragma once
#include"Department.h"
#include"Student.h"
#include"Course.h"
#include"HoD.h"

class University{
	char* Uname;
	int TDeparts;
	Department** listOfDepartments;
	int noOfDep;

public:

	University();

	University(char*,int);

	char* getUniversityname();

	void addDepartment(Department*);

	void addCourseinDep(int,Course*);

	void addStudent(int,Student*);

	void addTeacher(int,Teacher*);

	void addHOD(int,HoD*);

	void addITMan(int, ITMan*);

	void StudentFind(int&,int&,int);

	Student* getStudent(int,int);

	int getCoursesAvailable(int);

	char* getCourseName(int,int);

	int getCourseCode(int,int);

	Course* returnCourse(int,int);

	void addStudentinCourse(int,int,Student*);

	void addRegistrationinCourse(int,int,Registration*);

	void removeStudentfromCourse(int,int,int);

	Teacher* TeacherFind(int&,int);

	HoD* HODFind(int&, int);

	int getTotalTeachers(int);

	char* getTeacherName(int, int);

	int getTeacherCode(int,int);

	int getTotalStudents(int);

	char* getStudentName(int, int);

	int getStudentCode(int, int);

	void viewMarks(int, int, int);

	Course* getCourse(int,int);

	Teacher* getTeacher(int,int);

	ITMan* ITManagerFind(int&,int);

	void deleteStudent(int,int);

	void deleteStudentfromCourse(int,int);

	void deleteTeacher(int, int);

	~University();

};