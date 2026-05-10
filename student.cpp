#include "student.h"
#include "subject.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Student& Student::operator=(const Student& s) {
    if (this == &s) return *this;

    delete[] AM;

	Person::operator=(s);
    AM = new char[strlen(s.AM) + 1];
    strcpy(AM, s.AM);
    semester = s.semester;


    return *this;
}


Student& Student::operator++() {
    semester++;
    return *this;
}

Student Student::operator++(int) {
    Student temp(*this);
    semester++;
    return temp;
}


Student& Student::operator+=(unsigned int n) {
    semester += n;
    return *this;
}

Student& Student::operator-=(unsigned int n) {
    semester -= n;
    return *this;
}


void Student::print(std::ostream& ss) const {
    ss << getName() << "(" << getName().length() + 1 << ")"
        << "," << getGender()
        << "," << amGetter()
        << "," << getSemester()
        << std::endl;
}

// copy constructor
Student::Student(const Student& s):Person(s), semester(s.semester){
    AM = new char[strlen(s.AM) + 1];
    strcpy(AM, s.AM);
    
}

// constructor 1
Student::Student(std::string nName, const char* nAM): Person(nName, 0) {
    AM = new char[strlen(nAM) + 1];
    strcpy(AM, nAM);
    semester = 1;
}

// constructor 2
Student::Student(std::string nName, const char* nAM, unsigned int nSemester, bool nGender): Person(nName, nGender) {
	if(nSemester == 0){
		throw std::invalid_argument("Το εξάμηνο δεν μπορεί να είναι μικρότερο ή ίσο με το 0!");
	}
    AM = new char[strlen(nAM) + 1];
    strcpy(AM, nAM);
    semester = nSemester;
}

Student::~Student() {
    delete[] AM;
}

// setters

void Student::semesterSetter(unsigned int nSem) {
	if(nSem == 0){
		throw std::invalid_argument("Το εξάμηνο δεν μπορεί να είναι μικρότερο ή ίσο με το 0!");
	}
    semester = nSem;
}

void Student::amSetter(const char* nAM) {
    delete[] AM;
    AM = new char[strlen(nAM) + 1];
    strcpy(AM, nAM);
}

// getters
const char* Student::amGetter() const {
    return AM;
}

unsigned int Student::getSemester() const {
    return semester;
}


void Student::AddCourse(const Subject& course){
	this->courses.push_back(course);
	std::cout<<"Successfully added course"<<std::endl;
}
