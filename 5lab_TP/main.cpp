#include "Hash.h"
#include <iostream>
int main() {
Hash hash;
	char* file;
	char* name;
	char ch[1];
	while (true) {
		std::cout << "f - input file, k - keyboard, q - quit, p - print a table, d - delete element, s - search an element" << std::endl;
		std::cin >> ch;
		switch (ch[0])
		{
		case 'f':
			file = new char[30];
			std::cout << "Input name of file" << std::endl;
			std::cin >> file;
			hash.fileInput(file);
			break;
		case 'q':
			break;
		case 'k':
			hash.keyboardInput();
			std::cout << "Exit" << std::endl;
			break;
		case 'p':
			hash.printTable();
			break;
		case 'd':
			char que[50];
			std::cout << "Input an value:" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.getline(que, 50);
			hash.deleteElem(que);
			break;
		case 's':
			char quest[50];
			std::cout << "Input an value:" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.getline(quest, 50);
			hash.search(quest);
			break;
		default:
			std::cout << "Incorrect input. Try one more" << std::endl;
			std::cin.clear();
			break;
		}
	}
	return 0;
}