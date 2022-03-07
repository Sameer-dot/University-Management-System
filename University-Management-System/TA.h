#pragma once
#include"Student.h"
#include"Teacher.h"

template <class Type>
class TA :public Student, public Teacher {
	
		
	TA(int T, char* S) :Student(T, S), Teacher(T, S) {}

};
