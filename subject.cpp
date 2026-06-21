#include "subject.h"
#include "teacher.h"


Subject::Subject(const char* nPassword, std::string nDescription, unsigned int nSemester, Teacher* nCourse_leader) {
	password = nullptr;
	if (nPassword != nullptr && strlen(nPassword) > 0) {
		password = new char[strlen(nPassword) + 1];
		strcpy(password, nPassword);
	}

	description = nDescription;
	semester = nSemester;
	course_leader = nCourse_leader;
}

Subject::Subject(const char* nPassword, unsigned int nSemester) {
	password = nullptr;
	if (nPassword != nullptr && strlen(nPassword) > 0) {
		password = new char[strlen(nPassword) + 1];
		strcpy(password, nPassword);
	}

	semester = nSemester;
	description = "Καμία περιγραφή";
	course_leader = nullptr;
}

Subject::Subject(const Subject& other) {
	password = nullptr;
	if (other.password != nullptr && strlen(other.password) > 0) {
		password = new char[strlen(other.password) + 1];
		strcpy(password, other.password);
	}

	description = other.description;
	semester = other.semester;
	course_leader = other.course_leader;
}


Subject::~Subject() {
	delete[] password;
}

//setters

void Subject::password_setter(const char* nPassword) {
	delete[] password;
	password = nullptr;
	if (nPassword != nullptr && strlen(nPassword) > 0) {
		
		password = new char[strlen(nPassword) + 1];
		strcpy(password, nPassword);
	}
}
void Subject::description_setter(std::string nDescription) {
	description = nDescription;
}
void Subject::semester_setter(unsigned int nSemester) {
	semester = nSemester;
}
void Subject::course_leader_setter(Teacher* k) {
	course_leader = k;
}

//getters
const char* Subject::password_getter()const {
	return password ? password : "";
}
std::string Subject::description_getter()const {
	return description;
}
unsigned int Subject::semester_getter()const {
	return semester;
}
Teacher* Subject::course_leader_getter()const {
	return course_leader;
}

Subject& Subject::operator=(const Subject& other) {
	delete[] password;
	password = nullptr;
	if (this == &other) return *this;

	if (other.password != nullptr && strlen(other.password) > 0) {

		password = new char[strlen(other.password) + 1];
		strcpy(password, other.password);
	}
	description = other.description;
	semester = other.semester;
	course_leader = other.course_leader;

	return *this;
}

void Subject::PrintCourse() const{
	Teacher* leader = course_leader_getter();
	if(leader){
	std::cout << "Περιγραφή: " << description_getter() << ", Επικεφαλής Μαθήματος:" << leader->getName()
		<< ", Εξάμηνο:" << semester_getter() << std::endl;;
	}
	else{
		std::cout<<"Δεν βρέθηκε υπεύθυνος μαθήματος\n";
	}
}
