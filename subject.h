#ifndef subject_h
#define subject_h

#include <string>
#include <cstring>

class Subject{
	private:
		char *password;
		std::string description;
		unsigned int semester;
		unsigned int course_leader;

	public:
		//constructors & destructors
		Subject(const char *nPassword, std::string nDescription, unsigned int nSemester, unsigned int nCourse_leader);
		Subject(const char *npassword, unsigned int nsemester);
		Subject(const Subject& other);
		
		~Subject();

		void password_setter(const char *nPassword);
		void description_setter(std::string nDescription);
		void semester_setter(unsigned int nSemester);
		void course_leader_setter(unsigned int nCourse_leader);

		const char* password_getter()const;
		std::string description_getter()const;
		unsigned int semester_getter()const;
		unsigned int course_leader_setter()const;
		
	
};

#endif
