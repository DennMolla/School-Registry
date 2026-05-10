#include "subject.h"

Subject::Subject(const char *nPassword, std::string nDescription, unsigned int nSemester, unsigned int nCourse_leader){
	password = new char[strlen(nPassword)+1];
	strcpy(password, nPassword);
	description = nDescription;
	semester = nSemester;
	course_leader = nCourse_leader;
}

Subject::Subject(const char *nPassword, unsigned int nSemester){
	password = new char[strlen(nPassword)+1];
	strcpy(password, nPassword);
	semester = nSemester;
	description ="Καμία περιγραφή";
	course_leader = 0;
}

Subject::Subject(const Subject& other){
	delete[] password;
	password = new char[strlen(other.password)+1];
	strcpy(password, other.password);
	description = other.description;
	semester = other.semester;
	course_leader = other.course_leader;
}


Subject::~Subject(){
	delete[] password;
}

//setters

void Subject::password_setter(const char *nPassword){
	delete[] password;
	password = new char[strlen(nPassword)+1];
	strcpy(password, nPassword);
}
void Subject::description_setter(std::string nDescription){
	description = nDescription;
}
void Subject::semester_setter(unsigned int nSemester){
	semester = nSemester;
}
void Subject::course_leader_setter(unsigned int nCourse_leader){
	course_leader = nCourse_leader;
}

//getters
const char* Subject::password_getter()const{
	return password;
}
std::string Subject::description_getter()const{
	return description;
}
unsigned int Subject::semester_getter()const{
	return semester;
}
unsigned int Subject::course_leader_setter()const{
	return course_leader;
}
