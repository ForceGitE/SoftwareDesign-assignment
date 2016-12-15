#ifndef STUDENT_H
#define STUDENT_H


class Student
{
    public:
        Student();
        virtual ~Student();

        string getName();
        void updateScore();
        int getScore();

    protected:

    private:

    string studentname;
    int score;
};

#endif // STUDENT_H
