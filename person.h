#ifndef person_h
#define person_h

#include <string>

class Person{
	private:
		std::string name;
		bool gender;
	public:
		Person(const Person& other);
		Person(std::string nName, bool nGender);
		Person& operator=(const Person&);
		Person& operator-();
	
		void nameSetter(std::string nName);
		void genderSetter(bool nGender);

		std::string getGender() const;
		std::string getName() const;

		virtual ~Person() = default;
		
};

#endif
