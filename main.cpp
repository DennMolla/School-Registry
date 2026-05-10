#include <iostream>
#include "student.h"
#include "teacher.h"
#include "subject.h"

int main() {
	Student s1("Peter", "00001", 1, 0);
	Teacher t1("Alex", "gay123", 0, 1);
	Subject subject("adawd0","ada", 1 , 1);
	s1.AddCourse(subject);

    return 0;
}
