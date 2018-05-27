#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "polynom.h"
#include <fstream>
#include <list>
#include <string>

class Interface {
	std::list<Polynom> list_pol;
	std::string filename;
public:
	Interface();
	~Interface();
	void show_list();
	void show_info();
	void create_file();
	void open_file();
	void save_file();
	void create_polynom();
	void delete_polynom();
	void change_var();
	void change_name();
	void calculator();
	void menu();
	void menu_list();
};

#endif