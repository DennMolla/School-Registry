#include "person.h"

Person::Person(std::string nName, bool nGender): name(nName), gender(nGender){};

Person::Person(const Person& other){
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


void Person::nameSetter(std::string nName){
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
        return "Man";
    else
        return "Woman";
}
