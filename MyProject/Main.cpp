#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

    cout << "C867: Scripting and Programming, C++" << endl;
    cout << "Belkin Balcarcel" << endl;
    cout << "Student ID: 012447019" << endl << endl;

    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Belkin,Balcarcel,bbalcar@wgu.edu,20,25,30,35,SOFTWARE"
    };

    Roster classRoster;

    
    for (int i = 0; i < 5; ++i) {
        string str = studentData[i];

        size_t rhs = str.find(",");
        string sID = str.substr(0, rhs);

        size_t lhs = rhs + 1;
        rhs = str.find(",", lhs);
        string fName = str.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        string lName = str.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        string email = str.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        int age = stoi(str.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        int d1 = stoi(str.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        int d2 = stoi(str.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = str.find(",", lhs);
        int d3 = stoi(str.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        string dProgStr = str.substr(lhs);

        DegreeProgram dProg = DegreeProgram::SECURITY;
        if (dProgStr == "NETWORK") dProg = DegreeProgram::NETWORK;
        else if (dProgStr == "SOFTWARE") dProg = DegreeProgram::SOFTWARE;

        classRoster.add(sID, fName, lName, email, age, d1, d2, d3, dProg);
    }

    
    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Average Days in Course" << endl;
    for (int i = 0; i <= classRoster.lastIndex; ++i) {
        if (classRoster.classRosterArray[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
        }
    }
    cout << endl;

    cout << "Degree Program" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

   
   
    cout << "Removing A3" << endl;
    classRoster.remove("A3");
    cout << endl;

    
    classRoster.printAll();
    cout << endl;

  
    cout << "Removing A3" << endl;
    classRoster.remove("A3");
    cout << endl;
}
