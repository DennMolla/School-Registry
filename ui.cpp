#include "ui.h"


void GUI::InitNC(){
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	curs_set(0);
}
GUI::GUI(Registry& reg): registry(reg){
	InitNC();
	win = newwin(20,30, 0,0);
	show = newwin(20,30, 0,30);
	keypad(show,TRUE);
	keypad(win, TRUE);
	
}
GUI::~GUI(){
	delwin(win);
	delwin(show);
	endwin();
}
void GUI::LoadCSVUI(){

	werase(show);
	box(show,0,0);
	registry.LoadCSV("data.csv");
	registry.Subject_LoadCSV("subject.csv");
	mvwprintw(show,1,1,"Φόρτωση από CSV επιτυχές");
	wrefresh(show);
}
void GUI::ShowSubjectsUI(){
	werase(show);
	box(show,0,0);
	mvwprintw(show,0,0,"Πρόγραμμα:");
	int row = 1;
	auto subj = registry.PrintSubjectCatalog();
	int index=0;
	for(auto t : subj){

		mvwprintw(show, row,2,"%s", t.password_getter());
		mvwprintw(show, row,15, "%s", registry.desc[index].c_str());
		row++;
		index++;
		
	}
	wrefresh(show);
}
void GUI::SaveCSVUI(){
	werase(show);
	box(show,0,0);
	registry.SaveCSV("data.csv");
	registry.Subject_SaveCSV("subject.csv");
	mvwprintw(show,1,1,"Αποθήκευση σε CSV επιτυχές");
	wrefresh(show);
}

void GUI::AddSubjectUI(){
	echo();
	curs_set(1);
	char password[20];
	char description[20];
	char semester[20];
	char semester_str[20];
	

	werase(show);
	box(show,0,0);
	mvwprintw(show, 1, 1, "Περιγραφή (Όνομα): ");   wrefresh(show); wgetnstr(show, description, 19);
	if(std::string(description).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτή Περιγραφή (όνομα)!");
		wrefresh(show);
		return;
	}
	registry.desc.push_back(description);
	mvwprintw(show, 2, 1, "Κωδικός: ");    wrefresh(show); wgetnstr(show, password, 19);
	if(std::string(password).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτός κωδικός!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 3, 1, "Εξάμηνο: "); wrefresh(show); wgetnstr(show, semester_str, 19);
	if(std::string(semester_str).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτό εξάμηνο!");
		wrefresh(show);
		return;
	}


	wrefresh(show);
	unsigned int nSemester = 1;
	try {
		nSemester = std::stoi(semester_str);
	} catch (...) {
		nSemester = 1;
	}
	Subject sb(password, nSemester);
	registry.AddSubject(sb);

	werase(show);
	box(show,0,0);

	mvwprintw(show,1,1,"Το μάθημα προστέθηκε!");
	wrefresh(show);

	noecho();
	curs_set(0);
}

void GUI::SubjectCatalogUI(){
	std::vector<std::string> menuSelect = {
		"1.Προβολή Π.Σ.",
		"2.Προσθήκη στο Π.Σ.",
		"3.Πίσω"
	};
	int arr_size = menuSelect.size();

	curs_set(1);
	werase(win);
	box(win,0,0);

	wrefresh(win);
	int highlight=0;
	int select;
	while(true)
	{
		for(int i=0;i<arr_size;i++)
		{
			if(i==highlight){
				wattron(win,A_REVERSE);
			}
			mvwprintw(win,i+1,1,"%s",menuSelect[i].c_str());
			if(i==highlight){

			wattroff(win,A_REVERSE);
			}
		}
		wrefresh(win);
		select = wgetch(win);
		switch(select)
		{
			case KEY_UP:
				highlight--;
				if(highlight==-1){
					highlight=0;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight>=arr_size){
					highlight=arr_size-1;
				}
				break;

			default:
				break;
		}
		if(select =='\n' || select == KEY_ENTER)
		{
			switch(highlight)
			{
				case 0:
					ShowSubjectsUI();
					break;
				case 1:
				AddSubjectUI();
					break;
				case 2:
					return;
				default:
					break;
		}
		}
	}
}

void GUI::AddTeacherUI(){
	echo();
	curs_set(1);
	char name[20];
	char password[20];
	char profession_str[20];
	char gender_str[20];

	werase(show);
	box(show,0,0);
	mvwprintw(show, 1, 1, "Όνομα: ");   wrefresh(show); wgetnstr(show, name, 19);
	if(std::string(name).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτό όνομα!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 2, 1, "Κωδικός: ");    wrefresh(show); wgetnstr(show, password, 19);
	if(std::string(password).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτός κωδικός!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 3, 1, "Ειδικότητα: "); wrefresh(show); wgetnstr(show, profession_str, 19);
	if(std::string(profession_str).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτή ειδικότητα!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 4, 1, "Φύλο (0/1): "); wrefresh(show); wgetnstr(show, gender_str, 19);
	wrefresh(show);



	int nProf = 1;
	try {
		nProf = std::stoi(profession_str);
	} catch (...) {
		nProf = 1;
	}

	bool nGender = false;
	if (std::string(gender_str) == "1") {
		nGender = true;
	}


	Teacher *t = new Teacher(name, password, nGender, nProf);
	registry.AddMember(t);

	werase(show);
	box(show,0,0);

	mvwprintw(show,1,1,"Ο καθηγητής προστέθηκε!");
	wrefresh(show);

	noecho();
	curs_set(0);
}

void GUI::AddStudentUI(){
	echo();
	curs_set(1);
	char name[20];
	char password[20];
	char semester_str[20];
	char gender_str[20];

	werase(show);
	box(show,0,0);
	mvwprintw(show, 1, 1, "Όνομα: ");   wrefresh(show); wgetnstr(show, name, 19);
	if(std::string(name).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτό όνομα!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 2, 1, "Α.Μ.: ");    wrefresh(show); wgetnstr(show, password, 19);
	if(std::string(password).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτό Α.Μ.!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 3, 1, "Εξάμηνο: "); wrefresh(show); wgetnstr(show, semester_str, 19);
	if(std::string(semester_str).empty()){
		werase(show);
		mvwprintw(show,1,1, "Μη επιτρεπτό εξάμηνο!");
		wrefresh(show);
		return;
	}
	mvwprintw(show, 4, 1, "Φύλο (0/1): "); wrefresh(show); wgetnstr(show, gender_str, 19);
	wrefresh(show);



	unsigned int nSemester = 1;
	try {
		nSemester = std::stoi(semester_str);
	} catch (...) {
		nSemester = 1;
	}

	bool nGender = false;
	if (std::string(gender_str) == "1") {
		nGender = true;
	}


	Student *s = new Student(name, password, nSemester, nGender);
	registry.AddMember(s);

	werase(show);
	box(show,0,0);

	mvwprintw(show,1,1,"Ο μαθητής προστέθηκε!");
	wrefresh(show);

	noecho();
	curs_set(0);
}

void GUI::TeacherMenuUI(){
	std::vector<std::string> menuSelect = {
		"1.Προβολή Καθηγητών",
		"2.Προσθήκη Καθηγητή",
		"3.Διαγραφη Καθηγητή",
		"4.Πίσω"
	};

	int arr_size = menuSelect.size();
	curs_set(0);
	werase(win);
	box(win,0,0);
	wrefresh(win);
	int highlight=0;
	int select;
	while(true)
	{
		for(int i=0;i<arr_size;i++)
		{
			if(i==highlight)
			{
				wattron(win,A_REVERSE);
			}
			mvwprintw(win,i+1,1,"%s",menuSelect[i].c_str());
			if(i==highlight)
			{
				wattroff(win,A_REVERSE);
			}
		}
		wrefresh(win);
		select = wgetch(win);
		switch(select)
		{
			case KEY_UP:
				highlight--;
				if(highlight==-1){
					highlight=0;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight>=arr_size){
					highlight=arr_size-1;
				}
				break;
			default:
				break;
		}
		if(select =='\n' || select == KEY_ENTER)
		{
			switch(highlight)
			{
				case 0:
					ShowTeachersUI();
					break;
				case 1:
					AddTeacherUI();

					break;
				case 2:
					DeleteTeachersUI();
					break;
				case 3:
					return;
				default:
					break;

			}
		}
	}
}


void GUI::StudentMenuUI(){
	std::vector<std::string> menuSelect = {
		"1.Προβολή Μαθητών",
		"2.Προσθήκη Μαθητή",
		"3.Διαγραφη Μαθητή",
		"4.Πίσω"
	};
	int arr_size = menuSelect.size();

	curs_set(0);
	werase(win);

	box(win,0,0);
	wrefresh(win);
	int highlight=0;
	int select;

	while(true)
	{
		for(int i=0;i<arr_size;i++)
		{
			if(i==highlight)
			{
				wattron(win,A_REVERSE);
			}
			mvwprintw(win,i+1,1,"%s",menuSelect[i].c_str());
			if(i==highlight)
			{
				wattroff(win,A_REVERSE);
			}
		}
		wrefresh(win);
		select = wgetch(win);
		switch(select)
		{
			case KEY_UP:
				highlight--;
				if(highlight==-1){
					highlight=0;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight>=arr_size){
					highlight=arr_size-1;
				}
				break;
			default:
				break;
		}
		if(select =='\n' || select == KEY_ENTER)
		{
			switch(highlight)
			{
				case 0:
					ShowStudentsUI();
					break;
				case 1:
					AddStudentUI();
					break;
				case 2:
					DeleteStudentsUI();
					break;
				case 3:
					return;
				default:
					break;
					
			}
		}
	}
}

void GUI::DeleteTeachersUI(){
	echo();
	curs_set(1);
	char pass[20];

	werase(show);
	box(show,0,0);
	mvwprintw(show,1,1,"Δώσε κωδικό καθηγητή: ");
	    wrefresh(show);
	
	    wgetnstr(show, pass, 19);
	
	    bool ok = registry.DeleteTeacher(pass);
	
	    werase(show);
	    box(show,0,0);
	
	    if(ok)
	        mvwprintw(show,1,1,"Ο καθηγητής διαγράφηκε!");
	    else
	        mvwprintw(show,1,1,"Δεν βρέθηκε καθηγητής!");
	
	    wrefresh(show);
	
	    noecho();
	    curs_set(0);
}

void GUI::DeleteStudentsUI(){
	echo();
	curs_set(1);
	char pass[20];

	werase(show);
	box(show,0,0);
	mvwprintw(show,1,1,"Δώσε Α.Μ. μαθητή: ");
	    wrefresh(show);
	
	    wgetnstr(show, pass, 19);
	
	    bool ok = registry.DeleteStudent(pass);
	
	    werase(show);
	    box(show,0,0);
	
	    if(ok)
	        mvwprintw(show,1,1,"Ο μαθητής διαγράφηκε!");
	    else
	        mvwprintw(show,1,1,"Δεν βρέθηκε μαθητής!");
	
	    wrefresh(show);
	
	    noecho();
	    curs_set(0);
}





void GUI::ShowStudentsUI(){
	werase(show);
	box(show,0,0);
	mvwprintw(show,0,0,"Students:");
	int row =1;
	auto students = registry.PrintStudents();

	for(auto s:students){
	
		mvwprintw(show,row,2,"%s",s->getName().c_str());
		mvwprintw(show,row,15,"%d",s->getSemester());
		row++;
	}
	wrefresh(show);
}

void GUI::ShowTeachersUI(){
	werase(show);
	box(show,0,0);
	mvwprintw(show,0,0,"Teachers:");
	int row = 1;
	auto teachers = registry.PrintTeachers();

	for(auto t : teachers){

		mvwprintw(show, row,2,"%s", t->getName().c_str());
		mvwprintw(show, row,13,"%s", t->profession_getter().c_str());
		row++;
	}
	wrefresh(show);
}


void GUI::RunMenu()
{	int arr_size= mlist.size();
    int highlight = 0;
    int select;


    while(true)
    {
        werase(win);
		mvprintw(0,80,"--ΦΟΙΤΗΤΟΛΟΓΙΟ--");
        box(win, 0, 0);
		refresh();

        for(int i = 0; i < arr_size; i++)
        {
            if(i == highlight)
                wattron(win, A_REVERSE);

            mvwprintw(win, i + 1, 1, "%s", mlist[i].c_str());

            if(i == highlight)
                wattroff(win, A_REVERSE);
        }

        wrefresh(win);

        select = wgetch(win);

        if(select == KEY_UP)
        {
            highlight--;
            if(highlight < 0)
                highlight = 0;
        }
        else if(select == KEY_DOWN)
        {
            highlight++;
            if(highlight >= arr_size)
                highlight = arr_size-1;
        }
        else if(select == '\n' || select == KEY_ENTER)
        {
            switch(highlight)
            {
                case 0:
                   // ShowStudents();
					StudentMenuUI();
                    break;

                case 1:
                    TeacherMenuUI();
                    break;

                case 2:
					SubjectCatalogUI();
                    break;

                case 3:
					SaveCSVUI();
                  	break;
                case 4:
                	LoadCSVUI();
                	break;
                case 5:
					return; //exit
				default:
					break;
            }

        }
    }
}
void GUI::RunShow(){

	box(show,0,0);
	wrefresh(show);
}


