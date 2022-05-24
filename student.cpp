#include <iostream>
#include <string>
#include "student.h"
using namespace std; // per rubric

	// Default Constructor (no arguments)
Student::Student() {
	
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < coursesInArray; i++) this->daysPerCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

	// Constructor with arguments
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeProgram) {
	
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < coursesInArray; i++) this->daysPerCourse[i] = daysPerCourse[i];
	this->degreeProgram = degreeProgram;
}

	// Destructor
Student::~Student() {}

	// Mutators
void Student::setStudentID(string ID) {this->studentID = ID;}
void Student::setFirstName(string fName) {this->firstName = fName;}
void Student::setLastName(string lName) {this->lastName = lName;}
void Student::setEmail(string eMail) {this->emailAddress = eMail;}
void Student::setAge(int age) {this->age = age;}
void Student::setDaysPerCourse(int daysPerCourse[]) {
	for (int i = 0; i < coursesInArray; i++) this->daysPerCourse[i] = daysPerCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

	// Accessors
string Student::getStudentID() const {return this->studentID;}
string Student::getFirstName() const {return this->firstName;}
string Student::getLastName() const {return this->lastName;}
string Student::getEmail() const {return this->emailAddress;}
int Student::getAge() const {return this->age;}
int* Student::getDaysPerCourse() {return this->daysPerCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}
	
	// Print function
void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysPerCourse()[0] << ',';
	cout << this->getDaysPerCourse()[1] << ',';
	cout << this->getDaysPerCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << endl;				
}

bool Student::hasInvalidEmail() {
	if (Student::getEmail().find('@') == string::npos || 
		Student::getEmail().find(' ') != string::npos ||
		Student::getEmail().find('.') == string::npos) {
	     return true;
	}
	else return false;
}

double Student::averageDaysInCourse() {
	return (Student::getDaysPerCourse()[0] + 
			Student::getDaysPerCourse()[1] +
			Student::getDaysPerCourse()[2]) / 3.0;
}
