#ifndef teacher_h
#define teacher_h


#include <string>
#include <cstring>
#include <vector>
#include "person.h"


class Subject;

class Teacher :public Person {
private:
	char* password;
	unsigned int profession;
//	std::vector<Subject*> courses;

public:
	//constructors
	Teacher(const Teacher& other);
	Teacher(std::string name, const char* password);
	Teacher(std::string name, const char* password, bool gender,int profession);
	Teacher& operator=(const Teacher& s);
	~Teacher();

	void print(std::ostream& ss)const override;

	//getters & setters
	void password_setter(const char* nPass);
	void profession_setter(int nProf);

	const char* password_getter() const;
	std::string profession_getter()const;
	int profession_id()const;


};

#endif
