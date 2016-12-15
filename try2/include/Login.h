#ifndef LOGIN_H
#define LOGIN_H


class Login
{
    public:
        Login();
        virtual ~Login();
        LogIn(string logname, string password);
        bool checkLog();
        bool checkName(string name);
        bool checkPass(string pass);
        string getName();

    protected:
    string name;
    string pass;
    string studentname;
};

#endif // LOGIN_H
