#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "polynom.h"
#include "interface.h"

const char *error = "Ошибка! Неверно введен номер меню. Пожалуйста, повторите ввод.";
const char *pname_input = "Введите имя многочлена: ";
const char *fname_input = "Введите имя файла: ";

Interface::Interface() {
	filename = "new_list.txt";
}

Interface::~Interface() {}

void Interface::show_list() {
	int j = 1;
	for (auto it = list_pol.begin(); it != list_pol.end(); ++it)
		std::cout << j++ << ". " << *it << std::endl;
}

void Interface::show_info() {
	using namespace std;
	cout << endl;
	menu();
}

void Interface::create_file() {
	using namespace std;
	cout << fname_input;
	cin >> filename;
	std::ifstream fin(filename, ios_base::trunc);
	fin.close();
	fin.clear();
	menu_list();
}

void Interface::open_file() {
	using namespace std;
	cout << fname_input;
	cin >> filename;
	string str;
	ifstream fin(filename, ios_base::in);
	while (getline(fin, str)) {
		Polynom p(str);
		list_pol.push_back(p);
	}
	fin.close();
	fin.clear();
	menu_list();
}

void Interface::save_file() {
	using namespace std;
	ofstream fout(filename, ios_base::in | ios_base::out);
	for (auto it = list_pol.begin(); it != list_pol.end(); ++it)
		fout << *it << "\n";
	fout.close();
	fout.clear();
	menu();
}

void Interface::create_polynom() {
	Polynom p;
	std::cin >> p;
	list_pol.push_back(p);
	menu_list();
}

void Interface::delete_polynom() {
	std::cout << pname_input;
	std::string name;
	std::cin >> name;
	for (auto it = list_pol.begin(); it != list_pol.end(); ++it)
		if (it->name == name)
			list_pol.erase(it);
	menu_list();
}

void Interface::change_var() {
	std::cout << pname_input;
	Polynom p;
	menu_list();
}

void Interface::change_name() {
	menu_list();
}

void Interface::calculator() {
	std::string expresion;
}

void Interface::menu() {
	using namespace std;
	cout << "1. Создать новый список\t\t";
	cout << "3. Сохранить список в файл\n";
	cout << "2. Открыть файл со списком\t\t";
	cout << "4. Справочная информация\n";
	cout << "0. Выход из программы";
	cout << endl;
	int command;
	cin >> command;
	switch(command) {
		case 0: exit(0); break;
		case 1: create_file(); break;
		case 2: open_file(); break;
		case 3: save_file(); break;
		case 4: show_info(); break;
		default:
			cout << error << endl;
				menu(); break;
	}
}

void Interface::menu_list() {
	using namespace std;
	cout << "1. Записать новый многочлен\t\t";
	cout << "3. Подставить один многочлен в другой многочлен\n";
	cout << "2. Удалить многочлен из списка\t\t";
	cout << "4. Изменить имя многочлена\n";
	cout << "5. Калькулятор многочленов\t\t";
	cout << "0. Назад в главное меню";
	cout << endl;
	int command;
	cin >> command;
	switch (command) {
		case 0: menu(); break;
		case 1: create_polynom(); break;
		case 2: delete_polynom(); break;
		case 3: change_var(); break;
		case 4: change_name(); break;
		case 5: calculator(); break;
		default: cout << error << endl; break;
	}
}