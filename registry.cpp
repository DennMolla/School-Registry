#include "registry.h"


void Registry::AddMember(Person* other) {
	this->members.push_back(other);
//	std::cout << "Η προσθήκη μέλους στο φοιτητολόγιο ολοκληρώθηκε με επιτυχία!\n";
}
void Registry::AddSubject(const Subject& course) {
	this->courses.push_back(course);
//	std::cout << "Προστέθηκε με επιτυχία το μάθημα στο φοιτητολόγιο!\n";
}

std::vector<Student*> Registry::PrintStudents() const {
//	std::cout << "--Μαθητές--\n";
	std::vector<Student*> result;

	for (Person* p : members) {
		Student* s = dynamic_cast<Student*>(p);
		
		if (s != nullptr) {
			result.push_back(s);
		}
		
	}
	return result;

}

std::vector<Teacher*> Registry::PrintTeachers() const {
//	std::cout << "--Καθηγητές--\n";
	std::vector<Teacher*> result;
	for (Person* r : members) {
		Teacher* t = dynamic_cast<Teacher*>(r);

		if (t != nullptr) {
			result.push_back(t);
		}

	}
	return result;

}

std::vector<Subject> Registry::PrintSubjectCatalog()const {
	std::vector<Subject> result;
	for (const Subject& sb : courses) {
			result.push_back(sb);
		}
		return result;
}

bool Registry::DeleteStudent(const char* otherAM)
{
    if(otherAM == nullptr || std::strlen(otherAM) == 0)
        return false;

    for(size_t i = 0; i < members.size(); i++)
    {
        Student* s = dynamic_cast<Student*>(members[i]);

        if(s && std::strcmp(s->amGetter(), otherAM) == 0)
        {
            delete members[i];
            members.erase(members.begin() + i);
            return true;
        }
    }

    return false;
}

bool Registry::DeleteTeacher(const char* otherPass)
{
    if(otherPass == nullptr || std::strlen(otherPass) == 0)
        return false;

    for(size_t i = 0; i < members.size(); i++)
    {
        Teacher* t = dynamic_cast<Teacher*>(members[i]);

        if(t && std::strcmp(t->password_getter(), otherPass) == 0)
        {
            delete members[i];
            members.erase(members.begin() + i);
            return true;
        }
    }

    return false;
}
void Registry::Subject_SaveCSV(const std::string& filename){
	std::ofstream sfile(filename);
	if(!sfile.is_open()){
		return;
	}
	int index=0;
	for (Subject sb : courses){
		sfile<<sb.password_getter() << "," << desc[index] << "," << sb.semester_getter() << "\n";
		index++;
	}
	sfile.close();
}
void Registry::Subject_LoadCSV(const std::string& filename){
	std::ifstream sfile(filename);
	if(!sfile.is_open()){
		return;
	}
	std::string sline;
	while(std::getline(sfile, sline)){
		std::stringstream ss(sline);

		std::string npass, ndesc,nsem;

		std::getline(ss, npass,',');
		std::getline(ss, ndesc, ',');
		std::getline(ss, nsem, ',');
		const char* password = npass.c_str();
		int semester = std::stoi(nsem);

		Subject sb(password, semester);
		courses.push_back(sb);
		desc.push_back(ndesc);
	}
	sfile.close();
}

void Registry::SaveCSV(const std::string& filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		//std::cerr << "Δεν ήταν δυνατό το άνοιγμα του αρχείου για εγγραφή!" << std::endl;
		return;
	}
	for (Person* p : members) {

		Student* s = dynamic_cast<Student*>(p);
		if (s != nullptr) {
			file << "STUDENT," << s->getName() << "," << s->amGetter() << "," << s->getSemester()<<","
				<< s->getGender()<<"\n";
		}
		else {
			Teacher* t = dynamic_cast<Teacher*>(p);
			if (t != nullptr) {
				file << "TEACHER,"<< t->getName()<< "," << t->password_getter() << "," << t->profession_id() << ","
					<< t->getGender() <<"\n";
			}
		}
	}
	file.close();
	//std::cout << "Τα δεδομένα αποθηκεύτηκαν με επιτυχία στο " << filename << std::endl;
}

void Registry::LoadCSV(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		//std::cerr << "Δεν βρέθηκε το αρχείο." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		
		std::stringstream ss(line);
		std::string type, id, name, num, gender;

		std::getline(ss, type, ',');
		std::getline(ss, name, ',');
		std::getline(ss, id, ',');
		std::getline(ss, num, ','); 
		std::getline(ss, gender, ','); 

		if (type == "STUDENT") {
			unsigned int nSem = std::stoi(num);
			bool nGender;
			if (gender == "Άνδρας" || gender == "0") {
				nGender = false;
			}
			else if (gender == "Γυναίκα" || gender == "1") {
				nGender = true;
			}
			else {
				nGender = false;
			}

			const char* nAm = id.c_str();

			Student* s = new Student(name, nAm, nSem, nGender);
			members.push_back(s);
		}
		else if (type == "TEACHER") { 
			const char* nPass = id.c_str();
			int nProfession = std::stoi(num); 
			bool nGender;
			if (gender == "Άνδρας" || gender == "0") {
				nGender = false;
			}
			else if (gender == "Γυναίκα" || gender == "1") {
				nGender = true;
			}
			else {
				nGender = false;
			}

			Teacher* t = new Teacher(name, nPass, nGender, nProfession);
			members.push_back(t); 
		}
	}
	file.close();
}

void Registry::SendEmailToStudents(const std::string& subject, const std::string& body) {
	std::cout << "--ΑΠΟΣΤΟΛΗ EMAIL ΣΕ ΟΛΟΥΣ ΤΟΥΣ ΜΑΘΗΤΕΣ--\n";
	
	for (Person* p : members) {
		Student* s = dynamic_cast<Student*>(p);
		
		if (s != nullptr) {
			std::cout << "Email στάλθηκε στον/στην: " << s->getName() << ", Email: " << s->amGetter()<< "@uniwa.gr" << ", Εξάμηνο: " << s->getSemester() << std::endl;
			std::cout << "Θέμα: " << subject << std::endl;
			std::cout << "Κείμενο: " << body << std::endl;
			std::cout << "------------------------------------\n";
		}
	}

}
void Registry::SendEmailToTeachers(const std::string& subject, const std::string& body) {
	std::cout << "--ΑΠΟΣΤΟΛΗ EMAIL ΣΕ ΟΛΟΥΣ ΤΟΥΣ ΕΚΠΑΙΔΕΥΤΙΚΟΥΣ--\n";
	for (Person* p : members) {
		Teacher* t = dynamic_cast<Teacher*>(p);
		if (t != nullptr) {
			std::cout << "Email στάλθηκε στον/στην: " << t->getName() << ", Email: " << t->password_getter()<<"@uniwa.gr"<< std::endl;
			std::cout << "Θέμα: " << subject << std::endl;
			std::cout << "Κείμενο: " << body << std::endl;
			std::cout << "------------------------------------\n";
		}
	}

}
Registry::~Registry() {
	for (Person* p : members) {
		delete p;
	}
}
