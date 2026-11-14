#include <iostream>
#include "student.h"

using namespace std;


Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    daysInCourse[0] = 0;
    daysInCourse[1] = 0;
    daysInCourse[2] = 0;
    degreeProgram = DegreeProgram::SECURITY;
}


Student::Student(string studentIDVal, string firstNameVal, string lastNameVal, string emailAddressVal, int ageVal, int daysInCourseVal[], DegreeProgram degreeProgramVal) {
    studentID = studentIDVal;
    firstName = firstNameVal;
    lastName = lastNameVal;
    emailAddress = emailAddressVal;
    age = ageVal;
    daysInCourse[0] = daysInCourseVal[0];
    daysInCourse[1] = daysInCourseVal[1];
    daysInCourse[2] = daysInCourseVal[2];
    degreeProgram = degreeProgramVal;
}

string Student::GetStudentID() const { return studentID; }
string Student::GetFirstName() const { return firstName; }
string Student::GetLastName() const { return lastName; }
string Student::GetEmailAddress() const { return emailAddress; }
int Student::GetAge() const { return age; }
const int* Student::GetDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::GetDegreeProgram() const { return degreeProgram; }


void Student::SetStudentID(string studentIDVal) { studentID = studentIDVal; }
void Student::SetFirstName(string firstNameVal) { firstName = firstNameVal; }
void Student::SetLastName(string lastNameVal) { lastName = lastNameVal; }
void Student::SetEmailAddress(string emailAddressVal) { emailAddress = emailAddressVal; }
void Student::SetAge(int ageVal) { age = ageVal; }
void Student::SetDaysInCourse(const int daysInCourseVal[]) {
    daysInCourse[0] = daysInCourseVal[0];
    daysInCourse[1] = daysInCourseVal[1];
    daysInCourse[2] = daysInCourseVal[2];
}
void Student::SetDegreeProgram(DegreeProgram degreeProgramVal) { degreeProgram = degreeProgramVal; }


void Student::print() const {
    string degreeString = "";
    if (degreeProgram == DegreeProgram::SECURITY) degreeString = "Security";
    else if (degreeProgram == DegreeProgram::NETWORK) degreeString = "Networking"; 
    else if (degreeProgram == DegreeProgram::SOFTWARE) degreeString = "Software";

    cout << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Age: " << age << "\t"
        << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} "
        << "Degree Program: " << degreeString << endl;
}