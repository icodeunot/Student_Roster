#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

	// Roster class declaration
class Roster {

	public:
		Roster();
		~Roster(); // Destructor		
		void parse(string studentData); // Create Student object from studentDataTable
		void add(string studentID, 
				 string firstName, 
				 string lastName, 
				 string emailAddress, 
				 int age, 
				 int daysInCourse1, 
				 int daysInCourse2, 
				 int daysInCourse3, 
				 DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		
	public:
		int lastIndex = -1;
		const static int rosterSize = 5; // Unique students from the Student Data Table
		Student* classRosterArray[rosterSize] {nullptr, nullptr, nullptr, nullptr, nullptr};
};

#endif
