#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

Roster::Roster() {}

void Roster::parse(string studentData) { // Parse out the student's data from the given table of strings
		
		int rhs = studentData.find(",");
		string studentID = studentData.substr(0, rhs); 
		
		int lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string firstName = studentData.substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lastName = studentData.substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string emailAddress = studentData.substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int age = stoi(studentData.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string degreeProgramString = studentData.substr(lhs, rhs - lhs);
		
		DegreeProgram degreeProgram;
		if (degreeProgramString == "SECURITY") {degreeProgram = SECURITY;}
		if (degreeProgramString == "NETWORK") {degreeProgram = NETWORK;}
		if (degreeProgramString == "SOFTWARE") {degreeProgram = SOFTWARE;}
		
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID,
				 string firstName,
				 string lastName,
				 string emailAddress,
				 int age,
				 int daysInCourse1,
				 int daysInCourse2,
				 int daysInCourse3,
				 DegreeProgram degreeProgram) {
					 int daysInCourseArray[] = {daysInCourse1, daysInCourse2, daysInCourse3};
					 classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
}
	
void Roster::printAll() {
	cout << "Displaying all students: " << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: " << degreeProgram << endl << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl;
	cout << endl;
	
	bool hasInvalidEmail = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
		if (classRosterArray[i]->hasInvalidEmail() == true){
			cout << classRosterArray[i]->getEmail() << " - ";
			cout << "is invalid." << endl;
			hasInvalidEmail = true;
		}
	}
	if (!hasInvalidEmail) {
		cout << "No Invalid Emails"
			 << endl;
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << ", "
				 << "average days in course is: " << classRosterArray[i]->averageDaysInCourse()
				 << endl;
		}
	}
	cout << endl;
}

void Roster::remove(string studentID) {
	cout << "Removing " << studentID << ":... ";
	bool studentFound = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			studentFound = true;
			if (studentFound == true) {
				if (i < rosterSize - 1) {
					for (i; i < rosterSize - 1; ++i) {
						classRosterArray[i] = classRosterArray[i + 1];
					}
					classRosterArray[rosterSize - 1] = nullptr;
				}
			}
			Roster::lastIndex--;
		}
	}
	if (studentFound == false) {
		cout << "The student with the ID: " << studentID << " was not found." << endl << endl;
	}
	else if (studentFound == true) {
		cout << studentID << " successfully removed from roster." << endl << endl;
	}
}

Roster::~Roster() {
	for (int i = 0; i < rosterSize; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "DONE." << endl;
}
