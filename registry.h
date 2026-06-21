#ifndef registry_h
#define registry_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"
#include "teacher.h"
#include "person.h"


class Registry {
private:
	std::vector<const char*>AM_total;
	std::vector<Person*> members;
	std::vector<Subject> courses;
	


public:
	~Registry();

	void AddMember(Person* other);
	bool DeleteStudent(const char* otherAM);
	bool DeleteTeacher(const char* otherPass);
	void AddSubject(const Subject& course);


	void SendEmailToStudents(const std::string& subject, const std::string& body);
	void SendEmailToTeachers(const std::string& subject, const std::string& body);
	std::vector<Student*> PrintStudents() const;
	std::vector<Teacher*> PrintTeachers() const;
	std::vector<Subject> PrintSubjectCatalog() const;

	std::vector<std::string> desc;

	void SaveCSV(const std::string& filename);
	void LoadCSV(const std::string& filename);

	void Subject_SaveCSV(const std::string& filename);
	void Subject_LoadCSV(const std::string& filename);
};

#endif
