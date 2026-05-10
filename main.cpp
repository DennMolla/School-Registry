#include <iostream>
#include "student.h"
#include "teacher.h"
#include "subject.h"

int main() {
	//student constructor (name , id , semester , gender(bool)
	Student s1("George", "student_id_here001", 1, 0);
	
	Teacher t1("Acelot", "password123", 0, 1);

	//subject constructor (name, description, semester, course leader(WIP)
	Subject subject("adawd0","ada", 1 , 1);
	s1.AddCourse(subject);

    return 0;
}
