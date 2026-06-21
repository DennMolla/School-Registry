#ifndef person_h
#define person_h

#include <string>
#include <vector>
#include "subject.h"

//class Subject;

class Person {
private:
	
	std::string name;
	bool gender;
	std::vector<Subject> courses;

public:
	void AddCourse(const Subject& course);
	void GetCourse();

	Person(const Person& other);
	Person(std::string nName, bool nGender);
	Person& operator=(const Person&);
	Person& operator-();
	virtual void print(std::ostream& ss)const = 0;

	void nameSetter(std::string nName);
	void genderSetter(bool nGender);


	std::string getGender() const;
	std::string getName() const;

	virtual ~Person() = default;

};

#endif
