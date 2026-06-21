#include "person.h"
#include "teacher.h"

#include <iostream>
#include <vector>

Person::Person(std::string nName, bool nGender) : name(nName), gender(nGender) {};

void Person::print(std::ostream& ss)const {};

Person::Person(const Person& other) {
    name = other.name;
    gender = other.gender;
}

Person& Person::operator=(const Person& p) {
    if (this == &p) return *this;

    name = p.name;
    gender = p.gender;
    return *this;
}

Person& Person::operator-() {
    gender = !gender;
    return *this;
}


void Person::nameSetter(std::string nName) {
    name = nName;
}

void Person::genderSetter(bool nGender) {
    gender = nGender;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getGender() const {
    if (!gender)
        return "Άνδρας";
    else
        return "Γυναίκα";
}

void Person::AddCourse(const Subject& course) {
    this->courses.push_back(course);
 //   std::cout << "Το μάθημα προστέθηκε με επιτυχία!" << std::endl;
}

void Person::GetCourse() {
    for (Subject& n : courses) {
        std::cout << "Μάθημα: " << n.description_getter() << ", Επικεφαλής Μαθήματος: " << n.course_leader_getter()->getName()
            << ", Εξάμηνο: " << n.semester_getter() << std::endl;
    }
}
