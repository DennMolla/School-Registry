#ifndef student_h
#define student_h



#include <string>
//#include <cstring>
#include <vector>
#include "person.h"

class Subject;

class Student:public Person{
private:
    char* AM;
    unsigned int semester;
	
	std::vector<Subject> courses;

public:
	void AddCourse(const Subject& course);
	
    // constructors & destructor
    Student(std::string nName, const char* nAM);
    Student(std::string nName, const char* nAM, unsigned int nSemester, bool nGender);
    Student(const Student& s);
    ~Student();

    // operator overloads
    Student& operator++();
    Student operator++(int);
    
    Student& operator+=(unsigned int);
    Student& operator-=(unsigned int);
    Student& operator=(const Student& s);

    void print(std::ostream& ss) const;

    // setters
    void amSetter(const char* nAM);
   // void nameSetter(std::string nName);
  //  void genderSetter(bool nGender);
    void semesterSetter(unsigned int nSem);

    // getters
  //  std::string getGender() const;
   // std::string getName() const;
    unsigned int getSemester() const;
    const char* amGetter() const;
};

#endif
