#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


Roster::Roster() {
    lastIndex = -1;
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}


Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}


void Roster::printAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}


void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->GetEmailAddress();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email: " << email << endl;
            }
        }
    }
}


void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
            const int* days = classRosterArray[i]->GetDaysInCourse();
            double avg = (days[0] + days[1] + days[2]) / 3.0;
            cout << studentID << ": " << avg << endl;
            return;
        }
    }
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}



void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];

            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            
            break;
        }
    }
    if (!found) {
        cout << "Student with id " << studentID << " not found!" << endl;
    }
}