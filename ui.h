#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <vector>
#include "registry.h"
#include "student.h"
#include "teacher.h"
#include "person.h"

class GUI{
	private:
		Registry& registry;
		WINDOW* win;
		WINDOW* show;
		std::vector<std::string> mlist = {
			"1.Μαθητές",
			"2.Καθηγητές",
			"3.Πρόγραμμα Σπουδών",
			"4.Αποθήκευση",
			"5.Φόρτωση",
			"6.Έξοδος"
		};
	//	std::vector<std::string> desc;
	public:
		GUI(Registry& reg);
		~GUI();

		void InitNC();
		void RunMenu();
		void RunShow();

		int ControlMenu(std::string arr[], int arr_size );

		void StudentMenuUI();
		void AddStudentUI();
		void ShowStudentsUI();
		void DeleteStudentsUI();
		
		void TeacherMenuUI();
		void AddTeacherUI();
		void ShowTeachersUI();
		void DeleteTeachersUI();

		void SubjectCatalogUI();
		void ShowSubjectsUI();
		void AddSubjectUI();

		void SaveCSVUI();
		void LoadCSVUI();
};

#endif
