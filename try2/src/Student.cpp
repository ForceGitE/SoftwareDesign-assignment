#include <iostream>
#include "vector"
//#include <TinyXML2/Include/tinyxml2.h>
#include "tinyxml2.h"
#include "std_lib_facilities.h"
#include "Student.h"
#include "Login.h"
using namespace tinyxml2;

using namespace std;


Student::Student(LogIn logname)
    {
        studentname = logname.getName();
        score= 0;

    }


Student::~Student()
{
    //dtor
}

string Student::getName()
    {
        return studentname;
    }

    void Student::updateScore()
    {
        score++;
    }

     int Student::getScore()
    {
        return score;
    }

