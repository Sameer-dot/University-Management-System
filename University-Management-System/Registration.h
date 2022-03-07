#pragma once 
class Student;
class Course;

class Registration{
	Student* Sid;
	Course* Cid;
	float GPA;
	bool* listOfAttendance;
	int CurrentAttendance;
	int* listOfMarks;
	int CurrentMarks;
public:

	Registration();

	Registration(Student*,Course*,float);

	void setGpa(float);

	void setCourse(Course*);

	float getGpa();

	void getallAttendanceOfCourse();

	void markAttendance(bool);

	void viewAttendance();

	void setMarks(int);

	void viewMarks();

	~Registration();
};