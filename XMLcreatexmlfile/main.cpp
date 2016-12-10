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

int main()
{

XMLDocument xmlDoc;

XMLNode * pRoot = xmlDoc.NewElement("Root");
xmlDoc.InsertFirstChild(pRoot);

XMLElement *pElement = xmlDoc.NewElement("IntValue");
pElement->SetText(10);
pRoot->InsertEndChild(pElement);

pElement = xmlDoc.NewElement("FloatValue");
pElement->SetText(0.5f);
pRoot->InsertEndChild(pElement);

pElement = xmlDoc.NewElement("Date");
pElement->SetAttribute("day" , 26);
pElement->SetAttribute("month","april");
pElement->SetAttribute("Year", 2001);
pElement->SetAttribute("dateFormat", "26/04/2000");
pRoot->InsertEndChild(pElement);

pElement = xmlDoc.NewElement("List");
//vector<int> vecList;
for (int item =0; item<10 ; item++)
//for (const auto & item : vecList)
{
    XMLElement * pListElement = xmlDoc.NewElement("Item");
    pListElement->SetText(item);

    pElement->InsertEndChild(pListElement);
}
pRoot->InsertEndChild(pElement);

XMLError eResult = xmlDoc.SaveFile("SavedData.xml");
XMLCheckResult(eResult);

    return 0;
}
