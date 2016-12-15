#include <iostream>
#include "vector"
//#include <TinyXML2/Include/tinyxml2.h>
#include "tinyxml2.h"
#include "std_lib_facilities.h"
#include "Student.h"
#include "Login.h"
using namespace tinyxml2;

using namespace std;

Login::LogIn(string logname, string password)
    {
        name = logname;
        pass = password;
    }

Login::~Login()
{
    //dtor
}

bool LogIn::checkLog()
    {

        if(checkName(name)&&checkPass(pass))
        {
            studentname = name;
            return true;
        }
        else
        {
            return false;
        }
    }

bool Login::checkName(string name)
    {
        // using std::find with array and pointer:
        string a[]= {"warren","peter","eoin","ciaran"};
        string *p;

        p = std::find (a, a+4, name);
        if (p != a+4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

bool Login::checkPass(string pass)
    {
        // using std::find with array and pointer:
        string a[]= {"ww","pp","ee","cc"};
        string *p;

        p = std::find (a, a+4, pass);
        if (p != a+4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

string Login::getName()
    {
        return studentname;
    }
    //virtual ~LogIn();

      bool checkAdmin()
    {
        if(name=="admin"&&pass=="admin"){return true;}else{return false;}
    }
