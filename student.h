#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
using namespace std;

    // Student class declaration
class Student {
	
	public:
	// Courses in the degree program
		const static int coursesInArray = 3;
		
	// Class variables
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysPerCourse[coursesInArray];
		DegreeProgram degreeProgram;

	// Class functions	
	public:	
	// Constructors, Destructor, & string qualifying functions
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeProgram);
		~Student();
		bool hasInvalidEmail();
		double averageDaysInCourse();
		
	// Mutators (Setters)
		void setStudentID(string ID);
		void setFirstName(string fName);
		void setLastName(string lName);
		void setEmail(string eMail);
		void setAge(int age);
		void setDaysPerCourse(int daysPerCourse[]);
		void setDegreeProgram(DegreeProgram degreeProgram);
		
	// Accessors (Getters)
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		int getAge() const;
		int* getDaysPerCourse();
		DegreeProgram getDegreeProgram();
		
	// Print function
		void print();
};
#endif
