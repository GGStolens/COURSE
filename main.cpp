#include <iostream>
#include <vector>
#include "polynom.h"
#include "interface.h"

int main() {
	std::vector<Polynom> polynoms;
	int command = -1;
	while (command) {
		menu();
		cin >> command;
		switch(command) {
			case 0: break;
			case 1:
				std::cin >> ;
				break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			default: std::cout << "ERROR" << std::endl; break;
		}
	}
	return 0;
}