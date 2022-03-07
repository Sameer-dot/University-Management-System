#include<iostream>
#include<fstream>
#include"University.h"
#include"Department.h"
#include"Person.h"
#include"Employee.h"
#include"Student.h"
#include"Teacher.h"
#include"Registration.h"
#include"ITMan.h"
#include"HoD.h"
#include"Course.h"
#include<cstdio>
#include"Exception.h"
using namespace std;

University* fileread()
{
	char UniversityName[50];
	int TotalDeps;
	char DepartmentName[50];
	int TotalCourse;
	int Ccode;
	char CName[25];
	int TotalFaculty;
	int TeacherCode;
	char TeacherName[25];
	int TotalStudents;
	int RollNo;
	char StudentName[25];
	char ABC;

	ifstream file;
	file.open("data.txt");
	file.getline(UniversityName, 50, '\n');
	file >> TotalDeps;
	University* U = new University(UniversityName, TotalDeps);
	ABC = file.get();
	for (int i = 0; i < TotalDeps; i++) {
		file.getline(DepartmentName, 50, '\n');
		file >> TotalCourse;
		Department* D = new Department(DepartmentName, TotalCourse);
		U->addDepartment(D);
		for (int j = 0; j < TotalCourse; j++) {
			file >> Ccode;
			file.get();
			file.getline(CName, 25, '\n');
			Course* C = new Course(Ccode, CName);
			U->addCourseinDep(i, C);
		}
		file >> TotalFaculty;
		file >> TeacherCode;
		file.get();
		file.getline(TeacherName, 25, '\n');
		HoD* H = new HoD(TeacherCode, TeacherName);
		U->addHOD(i, H);
		for (int k = 0; k < TotalFaculty - 1; k++) {
			file >> TeacherCode;
			file.get();
			file.getline(TeacherName, 25, '\n');
			Teacher* T = new Teacher(TeacherCode, TeacherName);
			U->addTeacher(i, T);
		}
		file >> TeacherCode;
		file >> TeacherCode;
		file.get();
		file.getline(TeacherName, 25, '\n');
		ITMan* It = new ITMan(TeacherCode, TeacherName);
		U->addITMan(i, It);
		file >> TotalStudents;
		for (int l = 0; l < TotalStudents; l++) {
			file >> RollNo;
			file.get();
			file.getline(StudentName, 25, '\n');
			Student* S = new Student(RollNo, StudentName);
			U->addStudent(i, S);
		}
	}
	return U;
}

void Menu() {
	cout << endl;
	cout << "\t\t\t\t  -------------------------------\n";
	cout << "\t\t\t\t              Menu\n";
	cout << "\t\t\t\t  -------------------------------\n";
	cout << "\t\t\t\t  Press 1 To Login As a Student\n";
	cout << "\t\t\t\t  Press 2 To Login As a Teacher\n";
	cout << "\t\t\t\t  Press 3 To Login As a IT-Manager\n";
	cout << "\t\t\t\t  Press 4 To Login As a HOD\n";
	cout << "\t\t\t\t  Press 5 to End Program\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
}

int StudentLogin(int u, char p[]) {
	try {
		int user;
		char password[50];
		bool Check = false;
		fstream fin;
		fin.open("Studentlogin.txt");
		if (!fin)
		{
			throw FileUnableToOpen("File Unable To Open!");
		}
		else {
			while (!fin.eof())
			{
				fin >> user >> password;
				if (user = u && strcmp(password, p) == 0)
					Check = true;
			}
			fin.close();
		}
		return Check;
	}
	catch (FileUnableToOpen exc) {
		cout << "In Catch Block: " << exc.what() << endl << endl;
	}

}

int TeacherLogin(int u, char p[]) {
	try {
		int user;
		char password[50];
		bool Check = false;
		fstream fin;
		fin.open("Teacherlogin.txt");
		if (!fin)
		{
			throw FileUnableToOpen("File Unable To Open!");
		}
		else {
			while (!fin.eof())
			{
				fin >> user >> password;
				if (user = u && strcmp(password, p) == 0)
					Check = true;
			}
			fin.close();
		}
		return Check;
	}
	catch (FileUnableToOpen exc) {
		cout << "In Catch Block: " << exc.what() << endl << endl;
	}
}

int ITManLogin(int u, char p[]) {
	try {
		int user;
		char password[50];
		bool Check = false;
		fstream fin;
		fin.open("ITManlogin.txt");
		if (!fin)
		{
			throw FileUnableToOpen("File Unable To Open!");
		}
		else {
			while (!fin.eof())
			{
				fin >> user >> password;
				if (user = u && strcmp(password, p) == 0)
					Check = true;
			}
			fin.close();
		}
		return Check;
	}
	catch (FileUnableToOpen exc) {
		cout << "In Catch Block: " << exc.what() << endl << endl;
	}
}

int HODLogin(int u, char p[]) {
	try {
		int user;
		char password[50];
		bool Check = false;
		fstream fin;
		fin.open("HODlogin.txt");
		if (!fin)
		{
			throw FileUnableToOpen("File Unable To Open!");
		}
		else {
			while (!fin.eof())
			{
				fin >> user >> password;
				if (user = u && strcmp(password, p) == 0)
					Check = true;
			}
			fin.close();
		}
		return Check;
	}
	catch (FileUnableToOpen exc) {
		cout << "In Catch Block: " << exc.what() << endl << endl;
	}
}


void StudentManage(int iD, University* U, char pass[]) {
	int DepNo = 0, StudNo = 0;
	U->StudentFind(DepNo, StudNo, iD);
	Student* S = U->getStudent(DepNo, StudNo);

	bool flag = false;
	while (!flag)
	{
		cout << endl;
		cout << "Press 1 to Register a Course\n";
		cout << "Press 2 to UnRegister a Course\n";
		cout << "Press 3 to Withdraw a Course\n";
		cout << "Press 4 to View marksheet of a specific course\n";
		cout << "Press 5 to View attendance of a specific course\n";
		cout << "Press 6 to Change password\n";
		cout << "Press 7 to LogOut\n";
		int Num;
		cout << "Enter: ";
		cin >> Num;
		if (Num >= 1 && Num <= 7)
		{
			if (Num == 1)
			{
				int i = 0;
				cout << endl;
				for (i = 0; i < U->getCoursesAvailable(DepNo); i++)
				{
					cout << "Course Name: " << i << ". " << U->getCourseName(DepNo, i);
					cout << "\t";
					cout << "Course Code: " << U->getCourseCode(DepNo, i);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int num;
					cout << "To Register Course, Press Course Number: ";
					cin >> num;
					while (num > i || num < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					Course* C = U->returnCourse(DepNo, num);
					S->addCourse(C);
					Registration* R = new Registration(S, C, 0);              //3rd
					S->addRegistration(R);
					U->addStudentinCourse(DepNo, num, S);
					U->addRegistrationinCourse(DepNo, num, R);
					cout << endl;
					cout << "Course Registered Successfully!\n\n";
					cout << "Press -1 to exit Otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 2)
			{
				int i = 0;
				cout << endl;
				for (i = 0; i < S->getCourseCount(); i++)
				{
					cout << "Course Name: " << i << ". " << S->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << S->getCourseCode(i);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int num;
					cout << "To Un-Register a Course,Press Course Number: ";
					cin >> num;
					while (num > i || num < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					int Ccode;
					Ccode = S->getCourseCode(num);
					S->removeCourse(num);
					U->removeStudentfromCourse(DepNo, Ccode, iD);
					cout << endl;
					cout << "Course Un-Registered Successfully!\n\n";
					cout << "Press -1 to exit Otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 3)
			{
				int i = 0;
				cout << endl;
				for (i = 0; i < S->getCourseCount(); i++)
				{
					cout << "Course Name: " << i << ". " << S->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << S->getCourseCode(i);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int num;
					cout << "To Withdraw a Course,Press Course NUmber: ";
					cin >> num;
					while (num > i || num < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					int Ccode;
					Ccode = S->getCourseCode(num);
					S->WidrawCourse(num);
					U->removeStudentfromCourse(DepNo, Ccode, iD);
					cout << endl;
					cout << "Course Withdrawn Successfully!\n\n";
					cout << "Press -1 to exit Otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 4)
			{
				int i = 0;
				cout << endl;
				for (i = 0; i < S->getCourseCount(); i++)
				{
					cout << "Course Name: " << i << ". " << S->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << S->getCourseCode(i);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int num;
					cout << "To see Marksheet, Press Course Number: ";
					cin >> num;
					while (num > i || num < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					cout << "Your Marks are: ";
					S->viewMarks(num);
					cout << "/100";
					cout << "Your Gpa in Course is: " << S->getGpa(num);
					cout << endl;
					cout << "Press -1 to exit Otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 5)
			{
				int i = 0;
				cout << endl;
				for (i = 0; i < S->getCourseCount(); i++)
				{
					cout << "Course Name: " << i << ". " << S->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << S->getCourseCode(i);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int num;
					cout << "To see the Attendance of a specific Course, Press Course Number: ";
					cin >> num;
					while (num > i || num < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					S->getallAttendanceOfCourse(num);
					cout << endl;
					cout << "Press -1 to exit Otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 6)
			{
				char password[50];
				cout << "Enter your Current Password: ";
				cin >> password;
				while ((strcmp(password, pass) == 0)) {
					cout << "Enter your New Password: ";
					cin >> password;
					ofstream fout;
					fout.open("Studentlogin.txt", ios::app);
					if (!fout)
					{
						cout << "Unable to open file!" << endl;
					}
					else
					{
						fout << iD << " ";
						fout << password << "\n";
					}
					fout.close();
				}
				int ID;
				char pass1[50];
				ifstream Read;
				Read.open("Studentlogin.txt");
				ofstream Write;
				Write.open("New.txt");
				Read >> ID >> pass1;
				while (!Read.eof()) {
					if ((strcmp(pass1, pass) != 0)) {
						Write << ID << " " << pass1 << endl;
					}
					else {
						cout << "Hurray!";
					}
					Read >> ID >> pass1;
				}
				Write.close();
				Read.close();
				remove("Studentlogin.txt");
				rename("New.txt", "Studentlogin.txt");
			}
			else {
				flag = true;
				cout << "\n\t\t\t\t   You Logged Out Successfully:}\n";
			}
		}
		else
			flag = true;
	}


}


void TeacherManage(int iD, University* U, char pass[]) {
	int DepNo = 0;
	Teacher* T = U->TeacherFind(DepNo, iD);
	bool flag = false;
	while (!flag)
	{
		cout << endl;
		cout << "Press 1 to Manage Attendance of Students\n";
		cout << "Press 2 to View Attendance of Students\n";
		cout << "Press 3 to Manage Evaluations of Students\n";
		cout << "Press 4 to View Evaluations of Students\n";
		cout << "Press 5 to Assign Grades to Students\n";
		cout << "Press 6 to LogOut\n";
		int Num;
		cout << "Enter: ";
		cin >> Num;
		if (Num >= 1 && Num <= 7)
		{
			if (Num == 1) {
				int i = 0;
				cout << endl;
				for (i = 0; i < T->getTotalCourse(); i++) {
					cout << "Course Name: " << i << ". " << T->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << T->getCourseCode(i);
					cout << endl << endl;
				}
				int num;
				cout << "To Select Course,Press Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < T->getTotalStudents(num); j++) {
					cout << "Student Name: " << j << ". " << T->getStudentName(num, j);
					cout << "\t";
					cout << "StudentCode: " << T->getStudentCode(num, j);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "To mark the Attendace of any Student Press Student Num: ";
					cin >> Num1;
					cout << endl;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					cout << endl;
					bool Presence;
					cout << "Mark the Attendance of Student by writing True or False : ";
					cin >> Presence;
					T->markAttendance(num, Num1, Presence);
					cout << endl;
					cout << "Press -1 to Exit otherwise Press Any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 2) {
				int i = 0;
				cout << endl;
				for (i = 0; i < T->getTotalCourse(); i++) {
					cout << "Course Name: " << i << ". " << T->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << T->getCourseCode(i);
					cout << endl << endl;
				}
				int num;
				cout << "To Select Course,Press Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < T->getTotalStudents(num); j++) {
					cout << "Student Name: " << j << ". " << T->getStudentName(num, j);
					cout << "\t";
					cout << "StudentCode: " << T->getStudentCode(num, j);
					cout << endl << endl;
				}
				int ENum = 0;
				while (ENum != -1) {
					cout << endl;
					int Num1;
					cout << "To view the Attendace of any Student Press Student Number: ";
					cin >> Num1;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					cout << "Student's Attendace(1 for Present 0 for Absent): ";
					T->viewAttendance(num, Num1);
					cout << endl << endl;
					cout << "Press -1 to Exit otherwise Press Any Number: ";
					cin >> ENum;
					cout << endl;
				}
			}
			else if (Num == 3) {
				int i = 0;
				cout << endl;
				for (i = 0; i < T->getTotalCourse(); i++) {
					cout << "Course Name: " << i << ". " << T->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << T->getCourseCode(i);
					cout << endl << endl;
				}
				int num;
				cout << "To Select Course,Press Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < T->getTotalStudents(num); j++) {
					cout << "Student Name: " << j << ". " << T->getStudentName(num, j);
					cout << "\t";
					cout << "StudentCode: " << T->getStudentCode(num, j);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "To mark the Marks of any Student Press Student Num: ";
					cin >> Num1;
					cout << endl;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					int Marks;
					cout << "Write Marks of the Student: ";
					cin >> Marks;
					T->setMarks(num, Num1, Marks);
					cout << endl << endl;
					cout << "Press -1 to Exit otherwise Press Any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 4) {
				int i = 0;
				cout << endl;
				for (i = 0; i < T->getTotalCourse(); i++) {
					cout << "Course Name: " << i << ". " << T->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << T->getCourseCode(i);
					cout << endl << endl;
				}
				int num;
				cout << "To Select Course,Press Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < T->getTotalStudents(num); j++) {
					cout << "Student Name: " << j << ". " << T->getStudentName(num, j);
					cout << "\t";
					cout << "StudentCode: " << T->getStudentCode(num, j);
					cout << endl << endl;
				}
				int ENum = 0;
				while (ENum != -1) {
					int Num1;
					cout << endl;
					cout << "To view the Marks of any Student Press Student Num: ";
					cin >> Num1;
					cout << endl;
					while (Num1 > i || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					cout << "Student's Marks: ";
					T->viewMarks(num, Num1);
					cout << "/100";
					cout << endl << endl;
					cout << "Press -1 to Exit otherwise Press Any Number: ";
					cin >> ENum;
					cout << endl;
				}
			}
			else if (Num == 5) {
				int i = 0;
				cout << endl;
				for (i = 0; i < T->getTotalCourse(); i++) {
					cout << "Course Name: " << i << ". " << T->getCourseName(i);
					cout << "\t";
					cout << "Course Code: " << T->getCourseCode(i);
					cout << endl << endl;
				}
				int num;
				cout << "To Select Course,Press Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}

				cout << endl;
				int j = 0;
				for (j = 0; j < T->getTotalStudents(num); j++) {
					cout << "Student Name: " << j << ". " << T->getStudentName(num, j);
					cout << "\t";
					cout << "StudentCode: " << T->getStudentCode(num, j);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					int Num1;
					cout << endl;
					cout << "To mark the Gpa of any Student Press Student Num: ";
					cin >> Num1;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> num;
					}
					float Gpa;
					cout << "Write Gpa of the Student: ";
					cin >> Gpa;
					cout << endl;
					T->setGpa(num, Num1, Gpa);
					cout << "Press -1 to Exit otherwise Press Any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else {
			flag = true;
			cout << "\n\t\t\t\t   You Logged Out Successfully:}\n";
			}
		}
		else
			flag = true;
	}
}


void ITManage(int iD, University* U, char pass[]) {
	int DepNo = 0;
	ITMan* IT = U->ITManagerFind(DepNo, iD);
	bool flag = false;
	while (!flag)
	{
		cout << endl;
		cout << "Press 1 to Create Account oF Teacher\n";
		cout << "Press 2 to Delete Account oF Teacher\n";
		cout << "Press 3 to Create Account oF Students\n";
		cout << "Press 4 to Delete Account of Students\n";
		cout << "Press 5 to Maintain Accounts of Students and Teachers\n";
		cout << "Press 6 to LogOut\n";
		int Num;
		cout << "Enter: ";
		cin >> Num;
		if (Num >= 1 && Num <= 7)
		{
			if (Num == 1) {
				char TName[25];
				int TCode;
				char Password[25];

				cout << endl;
				cout << "Enter Teacher's Name: ";
				cin.get();
				cin.getline(TName, 25);
				cout << "Enter Teacher's iD/Code: ";
				cin >> TCode;
				cout << "Enter Password for Teacher's Account: ";
				cin >> Password;
				Teacher* T = new Teacher(TCode, TName);
				U->addTeacher(DepNo, T);
				ofstream fin;
				fin.open("Teacherlogin.txt", ios::app);
				fin << endl << TCode << " " << Password;

				char UniversityName[50];
				int TotalDeps;
				char DepartmentName[50];
				int TotalCourse;
				int Ccode;
				char CName[25];
				int TotalFaculty;
				int TeacherCode;
				char TeacherName[25];
				int TotalStudents;
				int RollNo;
				char StudentName[25];
				char ABC;

				ofstream fout;
				ifstream file;
				file.open("data.txt");
				fout.open("Temp.txt");

				file.getline(UniversityName, 50, '\n');
				fout << UniversityName << endl;

				file >> TotalDeps;
				fout << TotalDeps << endl;

				ABC = file.get();
				for (int i = 0; i < TotalDeps; i++) {
					file.getline(DepartmentName, 50, '\n');
					fout << DepartmentName << endl;

					file >> TotalCourse;
					fout << TotalCourse << endl;

					for (int j = 0; j < TotalCourse; j++) {

						file >> Ccode;
						fout << Ccode << " ";
						file.get();

						file.getline(CName, 25, '\n');
						fout << CName << endl;

					}
					file >> TotalFaculty;
					if (i == DepNo) {
						fout << TotalFaculty + 1 << endl;
					}
					else
						fout << TotalFaculty << endl;
					for (int k = 0; k < TotalFaculty + 1; k++) {
						if (k != TotalFaculty) {

							file >> TeacherCode;
							fout << TeacherCode << " ";
							file.get();
							file.getline(TeacherName, 25, '\n');
							fout << TeacherName << endl;
						}
						else if (i == DepNo) {
							fout << T->getiD() << " " << T->getPname() << endl;
						}
					}
					file >> TeacherCode;
					fout << TeacherCode << endl;

					file >> TeacherCode;
					fout << TeacherCode << " ";
					file.get();
					file.getline(TeacherName, 25, '\n');
					fout << TeacherName << endl;

					file >> TotalStudents;
					fout << TotalStudents << endl;

					for (int l = 0; l < TotalStudents; l++) {
						file >> RollNo;
						fout << RollNo << " ";
						file.get();
						file.getline(StudentName, 25, '\n');
						fout << StudentName << endl;
					}
				}
				fout.close();
				file.close();
				remove("data.txt");
				rename("Temp.txt", "data.txt");
				cout << "Account Created Successfully!\n\n";
			}

			else if (Num == 2) {
				cout << endl;
				char TName[25];
				cout << "Enter Teacher's Name: ";
				cin.get();
				cin.getline(TName, 25);
				int TCode;
				cout << "Enter Teacher's ID/Code: ";
				cin >> TCode;
				char pass1[25];
				cout << "Enter Teacher's Password: ";
				cin >> pass1;
				U->deleteTeacher(DepNo, TCode);


				int ID;
				ifstream Read;
				Read.open("Teacherlogin.txt");
				ofstream Write;
				Write.open("New.txt");
				Read >> ID >> pass1;
				while (!Read.eof()) {
					if (ID != TCode) {
						Write << ID << " " << pass1 << endl;
					}
					else {
						cout << "Account Deleted Successfully!\n";
					}
					Read >> ID >> pass1;
				}
				Write.close();
				Read.close();
				remove("Teacherlogin.txt");
				rename("New.txt", "Teacherlogin.txt");
				char UniversityName[50];
				int TotalDeps;
				char DepartmentName[50];
				int TotalCourse;
				int Ccode;
				char CName[25];
				int TotalFaculty;
				int TeacherCode;
				char TeacherName[25];
				int TotalStudents;
				int RollNo;
				char StudentName[25];
				int ITTotal;
				char ABC;

				ofstream fout;
				ifstream file;
				file.open("data.txt");
				fout.open("Temp.txt");

				file.getline(UniversityName, 50, '\n');
				fout << UniversityName << endl;

				file >> TotalDeps;
				fout << TotalDeps << endl;

				ABC = file.get();
				for (int i = 0; i < TotalDeps; i++) {
					file.getline(DepartmentName, 50, '\n');
					fout << DepartmentName << endl;

					file >> TotalCourse;
					fout << TotalCourse << endl;

					for (int j = 0; j < TotalCourse; j++) {

						file >> Ccode;
						fout << Ccode << " ";
						file.get();

						file.getline(CName, 25, '\n');
						fout << CName << endl;

					}
					if (i == DepNo) {
						file >> TotalFaculty;
						fout << --TotalFaculty << endl;
					}
					else {
						file >> TotalFaculty;
						fout << TotalFaculty << endl;
					}
					file >> TeacherCode;
					fout << TeacherCode << " ";
					file.get();
					file.getline(TeacherName, 25, '\n');
					fout << TeacherName << endl;

					if (i == DepNo) {
						for (int k = 0; k < TotalFaculty; k++) {
							file >> TeacherCode;
							file.get();
							file.getline(TeacherName, 25, '\n');
							if (TeacherCode != TCode) {
								fout << TeacherCode << " ";
								fout << TeacherName << endl;
							}
						}
					}
					else {
						for (int k = 0; k < TotalFaculty - 1; k++) {
							file >> TeacherCode;
							file.get();
							file.getline(TeacherName, 25, '\n');
							if (TeacherCode != TCode) {
								fout << TeacherCode << " ";
								fout << TeacherName << endl;
							}
						}
					}

					file >> ITTotal;
					fout << ITTotal << endl;

					file >> TeacherCode;
					fout << TeacherCode << " ";
					file.get();
					file.getline(TeacherName, 25, '\n');
					fout << TeacherName << endl;

					file >> TotalStudents;
					fout << TotalStudents << endl;

					for (int l = 0; l < TotalStudents; l++) {
						file >> RollNo;
						fout << RollNo << " ";
						file.get();
						file.getline(StudentName, 25, '\n');
						fout << StudentName << endl;
					}
				}
				fout.close();
				file.close();
				remove("data.txt");
				rename("Temp.txt", "data.txt");
			}

			else if (Num == 3) {

				char SName[25];
				int SCode;
				char Password[25];
				cout << endl;
				cout << "Enter Student's Name: ";
				cin.get();
				cin.getline(SName, 25);
				cout << "Enter Student's iD/Code: ";
				cin >> SCode;
				cout << "Enter Password for Student's Account: ";
				cin >> Password;
				Student* S = new Student(SCode, SName);
				U->addStudent(DepNo, S);
				ofstream fin;
				fin.open("Studentlogin.txt", ios::app);
				fin << endl << SCode << " " << Password;


				char UniversityName[50];
				int TotalDeps;
				char DepartmentName[50];
				int TotalCourse;
				int Ccode;
				char CName[25];
				int TotalFaculty;
				int TeacherCode;
				char TeacherName[25];
				int TotalStudents;
				int RollNo;
				char StudentName[25];
				char ABC;

				ofstream fout;
				ifstream file;
				file.open("data.txt");
				fout.open("Temp.txt");

				file.getline(UniversityName, 50, '\n');
				fout << UniversityName << endl;

				file >> TotalDeps;
				fout << TotalDeps << endl;

				ABC = file.get();
				for (int i = 0; i < TotalDeps; i++) {
					file.getline(DepartmentName, 50, '\n');
					fout << DepartmentName << endl;

					file >> TotalCourse;
					fout << TotalCourse << endl;

					for (int j = 0; j < TotalCourse; j++) {

						file >> Ccode;
						fout << Ccode << " ";
						file.get();

						file.getline(CName, 25, '\n');
						fout << CName << endl;

					}
					file >> TotalFaculty;
					fout << TotalFaculty << endl;
					for (int k = 0; k < TotalFaculty; k++) {
						file >> TeacherCode;
						fout << TeacherCode << " ";
						file.get();
						file.getline(TeacherName, 25, '\n');
						fout << TeacherName << endl;
					}
					file >> TeacherCode;
					fout << TeacherCode << endl;

					file >> TeacherCode;
					fout << TeacherCode << " ";
					file.get();
					file.getline(TeacherName, 25, '\n');
					fout << TeacherName << endl;

					file >> TotalStudents;
					if (i == DepNo) {
						fout << TotalStudents + 1 << endl;
					}
					else
						fout << TotalStudents << endl;


					for (int l = 0; l < TotalStudents + 1; l++) {
						if (l != TotalStudents) {
							file >> RollNo;
							fout << RollNo << " ";
							file.get();
							file.getline(StudentName, 25, '\n');
							fout << StudentName << endl;
						}
						else if (i == DepNo) {
							fout << S->getRollNo() << " " << S->getPname() << endl;
						}
					}
				}
				fout.close();
				file.close();
				remove("data.txt");
				rename("Temp.txt", "data.txt");
				cout << "Account Created Successfully!\n\n";

			}

			else if (Num == 4) {
				cout << endl;
				char SName[25];
				cout << "Enter Student's Name: ";
				cin.get();
				cin.getline(SName, 25);
				int SCode;
				cout << "Enter Student's ID/Code: ";
				cin >> SCode;
				char pass1[25];
				cout << "Enter Student's Password: ";
				cin >> pass1;
				U->deleteStudentfromCourse(DepNo, SCode);
				U->deleteStudent(DepNo, SCode);
				int ID;
				ifstream Read;
				Read.open("Studentlogin.txt");
				ofstream Write;
				Write.open("New.txt");
				Read >> ID >> pass1;
				while (!Read.eof()) {
					if (ID != SCode) {
						Write << ID << " " << pass1 << endl;
					}
					else {
						cout << "Account Deleted Successfully!";
					}
					Read >> ID >> pass1;
				}
				Write.close();
				Read.close();
				remove("Studentlogin.txt");
				rename("New.txt", "Studentlogin.txt");

				char UniversityName[50];
				int TotalDeps;
				char DepartmentName[50];
				int TotalCourse;
				int Ccode;
				char CName[25];
				int TotalFaculty;
				int TeacherCode;
				char TeacherName[25];
				int TotalStudents;
				int RollNo;
				char StudentName[25];
				char ABC;

				ofstream fout;
				ifstream file;
				file.open("data.txt");
				fout.open("Temp.txt");

				file.getline(UniversityName, 50, '\n');
				fout << UniversityName << endl;

				file >> TotalDeps;
				fout << TotalDeps << endl;
				ABC = file.get();
				for (int i = 0; i < TotalDeps; i++) {

					file.getline(DepartmentName, 50, '\n');
					fout << DepartmentName << endl;

					file >> TotalCourse;
					fout << TotalCourse << endl;

					for (int j = 0; j < TotalCourse; j++) {

						file >> Ccode;
						fout << Ccode << " ";
						file.get();

						file.getline(CName, 25, '\n');
						fout << CName << endl;

					}
					file >> TotalFaculty;
					fout << TotalFaculty << endl;
					for (int k = 0; k < TotalFaculty; k++) {
						file >> TeacherCode;
						fout << TeacherCode << " ";
						file.get();
						file.getline(TeacherName, 25, '\n');
						fout << TeacherName << endl;
					}
					file >> TeacherCode;
					fout << TeacherCode << endl;

					file >> TeacherCode;
					fout << TeacherCode << " ";
					file.get();
					file.getline(TeacherName, 25, '\n');
					fout << TeacherName << endl;

					if (i == DepNo) {
						file >> TotalStudents;
						fout << --TotalStudents << endl;
					}
					else {
						file >> TotalStudents;
						fout << TotalStudents << endl;
					}

					for (int l = 0; l < TotalStudents; l++) {
						file >> RollNo;
						file.get();
						file.getline(StudentName, 25, '\n');
						if (RollNo != SCode) {
							fout << RollNo << " ";
							fout << StudentName << endl;
						}
					}
					if (i == DepNo) {
						file >> RollNo;
						file.get();
						file.getline(StudentName, 25, '\n');
						fout << RollNo << " ";
						fout << StudentName << endl;
					}
				}
				fout.close();
				file.close();
				remove("data.txt");
				rename("Temp.txt", "data.txt");
			}

			else if (Num == 5) {
				bool flag = false;
				while (!flag) {
					int num;
					cout << endl;
					cout << "Press 1 to change the Password of Student\n";
					cout << "Press 2 to change the Password of Teacher\n";
					cout << "Enter Number: ";
					cin >> num;
					if (num == 1) {
						int ID;
						cout << "Enter Student's iD: ";
						cin >> ID;
						char passs[25], pass1[25];
						cout << "Enter Current Password: ";
						cin >> passs;
						cout << "Enter your New Password: ";
						cin >> pass1;
						ofstream fout;
						fout.open("Studentlogin.txt", ios::app);
						if (!fout)
						{
							cout << "Unable to open file!" << endl;
						}
						else
						{
							fout << endl << ID << " ";
							fout << pass1 << "\n";
						}
						fout.close();
						char pass2[25];
						ifstream Read;
						Read.open("Studentlogin.txt");
						ofstream Write;
						Write.open("New.txt");
						Read >> ID >> pass2;
						while (!Read.eof()) {
							if ((strcmp(pass2, passs) != 0)) {
								Write << ID << " " << pass2 << endl;
							}
							else {
								cout << "Password Changed!\n";
							}
							Read >> ID >> pass2;
						}
						Write.close();
						Read.close();
						remove("Studentlogin.txt");
						rename("New.txt", "Studentlogin.txt");
					}
					else if (num == 2) {
						int ID;
						cout << "Enter Teacher's iD: ";
						cin >> ID;
						char passs[25], pass1[25];
						cout << "Enter Current Password: ";
						cin >> passs;
						cout << "Enter your New Password: ";
						cin >> pass1;
						ofstream fout;
						fout.open("Teacherlogin.txt", ios::app);
						if (!fout)
						{
							cout << "Unable to open file!" << endl;
						}
						else
						{
							fout << endl << ID << " ";
							fout << pass1 << "\n";
						}
						fout.close();
						char pass2[25];
						ifstream Read;
						Read.open("Teacherlogin.txt");
						ofstream Write;
						Write.open("New.txt");
						Read >> ID >> pass2;
						while (!Read.eof()) {
							if ((strcmp(pass2, passs) != 0)) {
								Write << ID << " " << pass2 << endl;
							}
							else {
								cout << "Password Changed Successfully!";
							}
							Read >> ID >> pass2;
						}
						Write.close();
						Read.close();
						remove("Teacherlogin.txt");
						rename("New.txt", "Teacherlogin.txt");

					}
					else
						flag = true;
				}
			}
			else {
			flag = true;
			cout << "\n\t\t\t\t   You Logged Out Successfully:}\n";
			}
		}
		else
			flag = true;
	}
}


void HODManage(int iD, University* U, char pass[]) {
	int DepNo = 0;
	HoD* H = U->HODFind(DepNo, iD);
	bool flag = false;
	while (!flag)
	{
		cout << endl;
		cout << "Press 1 to Assign Course to Teacher\n";
		cout << "Press 2 to Register a Course for Student\n";
		cout << "Press 3 to UnRegister a Course for Student\n";
		cout << "Press 4 to View Grades of a Specific Course\n";
		cout << "Press 5 to LogOut\n";
		int Num;
		cout << "Enter: ";
		cin >> Num;
		if (Num >= 1 && Num <= 6)
		{
			if (Num == 1) {
				int i = 0;
				cout << endl;
				for (i = 0; i < U->getCoursesAvailable(DepNo); i++)
				{
					cout << "Course Name: " << i << ". " << U->getCourseName(DepNo, i);
					cout << "\t";
					cout << "Course Code: " << U->getCourseCode(DepNo, i);
					cout << endl;
				}
				int num;
				cout << endl;
				cout << "Select a course to assign it to Teacher,Press Course Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				Course* C = U->getCourse(DepNo, num);
				cout << endl;
				int k = 0;
				for (k = 0; k < U->getTotalTeachers(DepNo); k++) {
					cout << "Teacher Name: " << k << ". " << U->getTeacherName(DepNo, k);
					cout << "\t";
					cout << "Teacher Code: " << k << U->getTeacherCode(DepNo, k);
					cout << endl;
				}
				cout << endl;
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "Press Teacher Number to Assign him Selected Course: ";
					cin >> Num1;
					while (Num1 > k || Num < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					Teacher* T = U->getTeacher(DepNo, Num1);
					T->addCourse(C);
					C->assignTeacher(T);
					cout << "Course Assigned Successfully!\n\n";
					cout << "Press -1 to exit otherwise Press Any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 2) {
				int i = 0;
				cout << endl;
				for (i = 0; i < U->getCoursesAvailable(DepNo); i++) {
					cout << "Course Name: " << i << ". " << U->getCourseName(DepNo, i);
					cout << "\t";
					cout << "Course Code: " << U->getCourseCode(DepNo, i);
					cout << endl;
				}
				cout << endl;
				int num;
				cout << "To Register a Course for Student,Press Course Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < U->getTotalStudents(DepNo); j++) {
					cout << "Student Name: " << j << ". " << U->getStudentName(DepNo, j);
					cout << "\t";
					cout << "StudentCode: " << U->getStudentCode(DepNo, j);
					cout << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "Press Student Number to Assign him Selected Course: ";
					cin >> Num1;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					Student* S = U->getStudent(DepNo, Num1);
					Course* C = U->returnCourse(DepNo, num);
					S->addCourse(C);
					Registration* R = new Registration(S, C, 0);              //3rd
					S->addRegistration(R);
					U->addStudentinCourse(DepNo, num, S);
					U->addRegistrationinCourse(DepNo, num, R);
					cout << "Course Registered Successfully!\n\n";
					cout << "Press -1 to exit otherwise Press Any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 3) {
				cout << endl;
				int i = 0;
				for (i = 0; i < U->getTotalStudents(DepNo); i++) {
					cout << "Student Name: " << i << ". " << U->getStudentName(DepNo, i);
					cout << "\t";
					cout << "StudentCode: " << U->getStudentCode(DepNo, i);
					cout << endl << endl;
				}
				int num;
				cout << "To Un-Register a Course for any Student Press Student Number: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				Student* S = U->getStudent(DepNo, num);
				int SiD = S->getRollNo();
				int k = 0;
				cout << endl;
				for (k = 0; k < S->getCourseCount(); k++)
				{
					cout << k << ". " << "Course Name: " << S->getCourseName(k);
					cout << "\t";
					cout << "Course Code: " << S->getCourseCode(k);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "To un-register Course for Selected Student,Press Course Number: ";
					cin >> Num1;
					while (Num1 > k || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					int Ccode;
					Ccode = S->getCourseCode(Num1);
					S->removeCourse(Num1);
					U->removeStudentfromCourse(DepNo, Ccode, SiD);
					cout << "Course Un-Registered Successfully!\n\n";
					cout << "Press -1 to exit otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else if (Num == 4) {
				int i = 0;
				cout << endl;
				for (i = 0; i < U->getCoursesAvailable(DepNo); i++) {
					cout << "Course Name: " << i << ". " << U->getCourseName(DepNo, i);
					cout << "\t";
					cout << "Course Code: " << U->getCourseCode(DepNo, i);
					cout << endl << endl;
				}
				int num;
				cout << "Press a Course Number To ciew Marks of Student in it: ";
				cin >> num;
				while (num > i || num < 0) {
					cout << "Press the Right Number: ";
					cin >> num;
				}
				cout << endl;
				int j = 0;
				for (j = 0; j < U->getTotalStudents(DepNo); j++) {
					cout << "Student Name: " << j << ". " << U->getStudentName(DepNo, j);
					cout << "\t";
					cout << "StudentCode: " << U->getStudentCode(DepNo, j);
					cout << endl << endl;
				}
				int Emp = 0;
				while (Emp != -1) {
					cout << endl;
					int Num1;
					cout << "To view the Marks of any Student,Press Student Number: ";
					cin >> Num1;
					while (Num1 > j || Num1 < 0) {
						cout << "Press the Right Number: ";
						cin >> Num1;
					}
					Teacher* T = H;
					T->viewMarks(num, Num1);
					cout << "Press -1 to Exit otherwise Press any Number: ";
					cin >> Emp;
					cout << endl;
				}
			}
			else {
			flag = true;
			cout << "\n\t\t\t\t   You Logged Out Successfully:}\n";
			}
		}
		else
			flag = true;
	}
}


int main()
{
	University* U = fileread();
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t" << U->getUniversityname() << endl;
	cout << "------------------------------------------------------------------------------------------------------------";
	int Choice;
	do{
		Menu();
		int u;
		char p[50];
		cout << endl;
		cout << "Enter Your Choice: ";
		cin >> Choice;
		switch (Choice)
		{
		case 1:
			cout << endl;
			cout << "Enter User ID: ";
			cin >> u;
			cout << "Enter Password: ";
			cin >> p;
			if (StudentLogin(u, p))
				StudentManage(u, U, p);
			else
				cout << "\n\t\t\t\t  INCORRECT PASSWORD OR USER ID:(\n";
			break;
		case 2:
			cout << endl;
			cout << "Enter User ID: ";
			cin >> u;
			cout << "Enter Password: ";
			cin >> p;
			if (TeacherLogin(u, p))
				TeacherManage(u, U, p);
			else
				cout << "\n\t\t\t\t  INCORRECT PASSWORD OR USER ID:(\n";
			break;
		case 3:
			cout << endl;
			cout << "Enter User ID: ";
			cin >> u;
			cout << "Enter Password: ";
			cin >> p;
			if (ITManLogin(u, p))
				ITManage(u, U, p);
			else
				cout << "\n\t\t\t\t  INCORRECT PASSWORD OR USER ID:(\n";
			break;
		case 4:
			cout << endl;
			cout << "Enter User ID: ";
			cin >> u;
			cout << "Enter Password: ";
			cin >> p;
			if (HODLogin(u, p))
				HODManage(u, U, p);
			else
				cout << "\n\t\t\t\t  INCORRECT PASSWORD OR USER ID:(\n";
			break;
		default:
			if (Choice<1 || Choice>5) {
				cout << "\nYou Pressed Wrong Number:(\n";
			}
			break;
		}
	} while (Choice!=5);
	cout << "\n\t\t\t\t\t  GOOD BYE:}\n";
	return 0;
}