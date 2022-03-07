#include<iostream>
#include "ITMan.h"
using namespace std;

ITMan::ITMan(){
	ITMCode=0;
}

ITMan::ITMan(int ITMiD,char* Pname):Employee(ITMiD,Pname){}