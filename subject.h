#ifndef subject_h
#define subject_h

#include <string>
#include <cstring>
#include <iostream>
//#include "teacher.h"
class Teacher;

class Subject {
private:
	char* password;
	std::string description;
	unsigned int semester;
	Teacher* course_leader;

public:
	void PrintCourse() const;

	//constructors & destructors
	Subject(const char* nPassword, std::string nDescription, unsigned int nSemester, Teacher* nCourse_leader);
	Subject(const char* npassword, unsigned int nsemester);
	Subject(const Subject& other);

	~Subject();

	void password_setter(const char* nPassword);
	void description_setter(std::string nDescription);
	void semester_setter(unsigned int nSemester);
	void course_leader_setter(Teacher* k);

	const char* password_getter()const;
	std::string description_getter()const;
	unsigned int semester_getter()const;
	Teacher* course_leader_getter()const;

	Subject& operator=(const Subject& other);


};

#endif
