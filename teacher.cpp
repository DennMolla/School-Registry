#include <iostream>
#include <stdexcept>
#include "teacher.h"
//#include "subject.h"

Teacher& Teacher::operator=(const Teacher& s) {
	if (this == &s) return *this;

	delete[] password;
	password = nullptr;
	Person::operator=(s);
	if (s.password != nullptr && strlen(s.password) > 0) {

		password = new char[strlen(s.password) + 1];
		strcpy(password, s.password);
	}
	else {
		std::cerr << "ERROR: Αποτυχία αντιγραφής password!\n";
	}

	profession = s.profession;


	return *this;
}
Teacher::Teacher(const Teacher& other) :Person(other), profession(other.profession) {
	password = nullptr;
		
	if (other.password != nullptr && strlen(other.password) > 0) {
		password = new char[strlen(other.password) + 1];
		strcpy(password, other.password);
	}

}

Teacher::Teacher(std::string nName, const char* nPassword) : Person(nName, 0) {
	password = nullptr;
	if (nPassword != nullptr && strlen(nPassword) > 0) {
		password = new char[strlen(nPassword) + 1];
		strcpy(password, nPassword);
	}
	profession = 0;
}

Teacher::Teacher(std::string nName, const char* nPassword, bool nGender, int nProfession) : Person(nName, nGender) {
	password = nullptr;
	if (nPassword != nullptr && strlen(nPassword) > 0) {
		password = new char[strlen(nPassword) + 1];
		strcpy(password, nPassword);
	}

	if (nProfession < 0 || nProfession >3) {
	//	throw std::invalid_argument("Λάθος ειδικότητα");
	}
	profession = nProfession;

}

Teacher::~Teacher() {
	delete[] password;
}

void Teacher::password_setter(const char* nPass) {
	delete[] password;
	password = nullptr;
	if (nPass != nullptr && strlen(nPass)>0) {
		
		password = new char[strlen(nPass) + 1];
		strcpy(password, nPass);
	}
}


void Teacher::profession_setter(int nProf) {
	profession = nProf;
}

const char* Teacher::password_getter()const {
		return password ? password : "";
}


std::string Teacher::profession_getter()const {
	switch (profession) {
	case 0: return "Unspecified";
	case 1: return "Πληροφορικός";
	case 2: return "Μαθηματικός";
	case 3: return "Φυσικός";
	default: return "Άγνωστο";
	}
	
}
int Teacher::profession_id()const {
	return profession;
}

void Teacher::print(std::ostream& ss) const {
		ss << getName() << "(" << getName().length() + 1 << ")"
			<< "," << getGender()
			<< "," << profession_getter()
			<< "," << (password ? password: "")
			<< std::endl;
}
