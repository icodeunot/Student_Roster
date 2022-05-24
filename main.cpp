#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
	
	// Heading required by rubric
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
		 << "\n*                                                                     *"
		 << "\n*    Course Name: C867 - Scripting and Programming - Applications     *"
		 << "\n*    Programming Language Used: C++                                   *"
		 << "\n*    WGU Student ID: 000650269                                        *"
		 << "\n*    Student Name: John Salazar                                       *"
		 << "\n*                                                                     *"
		 << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
		 << endl;
	cout << endl;
		 
		 
	// Student data table & personal info (Rubric item A)
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,John,Salazar,jsala24@wgu.edu,36,21,170,11,SOFTWARE" // my information
	};
	
	const int rosterSize = 5; // Amount of initial students from data table
	Roster classRoster;       // Roster Instantiation
	
	// loop through and parse studentDataTable[] 
	for (int i = 0; i < rosterSize; i++) { 
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();   
	classRoster.printInvalidEmails();
	for (int i = 0; i < rosterSize; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	cout << endl;	

	return 0;
}
