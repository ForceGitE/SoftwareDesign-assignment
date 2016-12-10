#include <iostream>
#include "vector"
//#include <TinyXML2/Include/tinyxml2.h>
#include "tinyxml2.h"
#include "std_lib_facilities.h"
using namespace tinyxml2;
using namespace std;

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif
//void XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { cout<<"Error: %i\n"<<a_eResult);}// return a_eResult; }


//LOADING AND EXTRACTING DATA FROM XML FILE

int main()
{

    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile("SavedData.xml");
    XMLCheckResult(eResult);

    XMLNode *pRoot = xmlDoc.FirstChild();                   //ptr to the root node element
    //if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
    if (pRoot == 0) return XML_ERROR_FILE_READ_ERROR;


    XMLElement * pElement = pRoot->FirstChildElement("IntValue");   //ptr to the child element--
    //if (pElement == nullptr) XML_ERROR_PARSING_ELEMENT;             //--assuming no child of the same name
    if (pElement == 0) return XML_ERROR_PARSING_ELEMENT;
    int iOutInt;
    eResult = pElement->QueryIntText(&iOutInt); //query if text content is the correct type--
    XMLCheckResult(eResult);                    //--saves the text in the element to appropriate type

    pElement = pRoot->FirstChildElement("FloatValue");
    //if (pElement == nullptr) XML_ERROR_PARSING_ELEMENT;
    if (pElement == 0) return XML_ERROR_PARSING_ELEMENT;
    float fOutFloat;
    eResult = pElement->QueryFloatText(&fOutFloat);
    XMLCheckResult(eResult);

    pElement = pRoot->FirstChildElement("Date");
    //if (pElement == nullptr) XML_ERROR_PARSING_ELEMENT;
    if (pElement == 0) return XML_ERROR_PARSING_ELEMENT;
    int iOutDay, iOutYear;
    pElement->QueryIntAttribute("day" , &iOutDay);
    pElement->QueryIntAttribute("Year" , &iOutYear);

    //const char *szAttributeText = nullptr;          //ptr init as null
    const char *szAttributeText = 0;          //ptr init as null

    szAttributeText = pElement->Attribute("month");
    //if (szAttributeText == nullptr) XML_ERROR_PARSING_ATTRIBUTE;
    if (szAttributeText == 0) return XML_ERROR_PARSING_ATTRIBUTE;
    string strOutMonth = szAttributeText;                     //saving string to a string type

    szAttributeText = pElement->Attribute("dateFormat");
    if (szAttributeText == 0) return XML_ERROR_PARSING_ATTRIBUTE;
    string strOutFormat = szAttributeText;



    pElement = pRoot->FirstChildElement("List");
    if (pElement == 0) return XML_ERROR_PARSING_ELEMENT;

    XMLElement * pListElement = pElement->FirstChildElement("Item"); //ptr to the sub child

    vector<int> vecList;

    while(pListElement!=0){
        int iOutListValue;

        eResult = pListElement->QueryIntText(&iOutListValue);
        XMLCheckResult(eResult);

        vecList.push_back(iOutListValue);

        pListElement = pListElement->NextSiblingElement("Item"); //ptr now points to the sibling
    }


    //return XML_SUCCESS;

    cout<<iOutInt<<" hello "<<iOutDay<<" "<<strOutMonth<<" "<<iOutYear<<" "<<strOutFormat<<endl;

    int x[vecList.size()];
    copy(vecList.begin(), vecList.end(), x);

    for(int i=0; i<vecList.size(); i++)
    {
        cout<<x[i]<<" ";
    }

    return 0;
}
