#include <iostream>
#include "vector"
//#include <TinyXML2/Include/tinyxml2.h>
#include "tinyxml2.h"
#include "std_lib_facilities.h"
using namespace tinyxml2;

using namespace std;

class LogIn
{
public:
    LogIn(string logname, string password)
    {
        name = logname;
        pass = password;
    }


    bool checkLog()
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

    bool checkName(string name)
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

    bool checkPass(string pass)
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
    string getName()
    {
        return studentname;
    }
    //virtual ~LogIn();

      bool checkAdmin()
    {
        if(name=="admin"&&pass=="admin"){return true;}else{return false;}
    }


protected:
    string name;
    string pass;
    string studentname;


private:
};

class Student
{
public:
    Student() {};
    Student(LogIn logname)
    {
        studentname = logname.getName();
        score= 0;

    };

    string getName()
    {
        return studentname;
    }
    void updateScore()
    {
        score++;
    }
    int getScore()
    {
        return score;
    }



private:

    string studentname;
    int score;
};

class Quiz
{

public:
    Quiz(Student studentquiz)
    {
        studentattempt=studentquiz;
        beginParsing();
    }

    void beginParsing()
    {
        XMLDocument xmlDoc;
        xmlDoc.LoadFile("QuestionBank.xml");
        XMLNode *pRoot = xmlDoc.FirstChild();                   //ptr to the root node element
        //if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

        XMLElement * pElement = pRoot->FirstChildElement("SWQD");   //ptr to the child element--//--assuming no child of the same name
        //if (pElement == 0) return XML_ERROR_PARSING_ELEMENT;

        XMLElement * pQuestionElement = pElement->FirstChildElement("Question"); //ptr to the sub child


        while(pQuestionElement != 0)
        {

            int iOutAnswer;
            //const char * iOutQuestion;
            string iOutQuestion;

            pQuestionElement->QueryIntAttribute("answer",&iOutAnswer);
            mAnswerList.push_back(iOutAnswer);

            iOutQuestion= pQuestionElement->GetText();
            mQuestionList.push_back(iOutQuestion);

            pQuestionElement=pQuestionElement->NextSiblingElement("Question");


        }
    };

    string askQuestion()
    {
        while(!mQuestionList.empty())
        {

            string outputQ = mQuestionList.back();
            cout<<outputQ<<endl;
            int answer;
            cin>>answer;


            typeAnswer(answer);

            mQuestionList.pop_back();
            mAnswerList.pop_back();

        }
        return "end";
    };

    void typeAnswer(int answer)
    {
        int outputA = mAnswerList.back();
        if(answer==outputA)
        { cout<<"answer is correct\n"<<endl; studentattempt.updateScore();  }else{cout<<"not correct\n"<<endl;}
    };

    Student getStudentObj(){return studentattempt;}

protected:

    vector<string> mQuestionList;
    vector<int> mAnswerList;
    Student studentattempt;


};

void creatXML()
{
    XMLDocument xmlDoc;  //new xml doc created

    XMLNode * pRoot = xmlDoc.NewElement("Root");  //makes the root node which contains all the lement in the cdocu
    xmlDoc.InsertFirstChild(pRoot); //explicitly attached the root node elemnt to the xml doc


    XMLElement * pElement = xmlDoc.NewElement("SWQD");//new element made
    //for(int i=0; i<10; i++)
    //{
        XMLElement * pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",10);
        pQuestionElement->SetText("Q10: How many steps in the V-model ? 10, 7 or 9 ?");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q9: Name First step in Waterfall Lifecycle ? 1 Requirement, 2 system design or 3 Implementation.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",2);
        pQuestionElement->SetText("Q8: Name 1 key OOp concept ? 1 chatter, 2 Message Passing or 3 cross-talk.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",3);
        pQuestionElement->SetText("Q7: Which are a type of methods in OOP ? 1 cooking methods, 2 no assignment methods or 3 Hidden Method.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q6: Did you think this Quiz was good ? 1 yes or 2 no.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",2);
        pQuestionElement->SetText("Q5: What testing is done first, 1 White box testing or 2 black box testing. ");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q4: If all our modules work individually, why do we doubt that they'll work when we put them together ? 1 because interfacing is tricky. 2 its grand no problems.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild


        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q3: What is regression Testing. Is it ? 1 Are tests to ensure that changes do not un-intended behaviour or additional errors. 2 set of activities that ensure that software is correct., a test done by the developer.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q2: what is alpha testing? 1 a test that is conducted at the developers site by a customer. 2 the correct test for software beginners guide to testing.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

        pQuestionElement = xmlDoc.NewElement("Question"); //new element made
        pQuestionElement->SetAttribute("answer",1);
        pQuestionElement->SetText("Q1: What is beta testing ? 1 a test that is condcuted at one or more customer sites by the end user of the software 2 free product, bored.");
        pElement->InsertEndChild(pQuestionElement);//attaches the pListElement as subchild

    //}

    pRoot->InsertEndChild(pElement);//attaches the pElemenent as child of root

    xmlDoc.SaveFile("QuestionBank.xml");

}



int main()
{

    string studentname,password;
    while(cin>>studentname>>password){

    cout<<"enter log in details"<<endl;

    LogIn login(studentname,password);
    if(login.checkLog())
    {
        Student studentObj(login);
        //creatXML(); //commented out as we dont want to create an XML file everytime the code runs

        Quiz quiz(studentObj);
        quiz.askQuestion();

        studentObj = quiz.getStudentObj();

        cout<<"students name is \n"<<studentObj.getName()<<"\nscore was \n"<<studentObj.getScore()<<"\n"<<endl;



    }
    else if(login.checkAdmin()){cout<<"admin checked"<<endl; return 0;}

    }

    return 0;
}
