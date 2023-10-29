#include "Hash.h"
#include <iostream>
#include <fstream>
char* manipulation(char*);
void fileInput(char*, Hash&);
void keyboardInput(char*, Hash&);
int main() {
Hash hash;
	char* file;
	char* name;
	char ch;
	while (true) {
		std::cout << "f - input file, k - keyboard, q - quit, p - print a table" << std::endl;
		std::cin >> ch;
		switch (ch)
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
			std::cout << "Input a value to Hash-table. If you want to exit input q" << std::endl;
			name = new char[50];
			std::cin >> name;
			keyboardInput(name, hash);
			std::cout << "Exit" << std::endl;
			break;
		case 'p':
			hash.printTable();
			break;
		default:
			std::cout << "Incorrect input. Try one more" << std::endl;
			std::cin.clear();
			break;
		}
	}
	return 0;
}
//void fileInput(char* file, Hash& hash) {
//	int numberOfLines = 0;
//	FILE* f = fopen(file, "r");
//	char* str = new char[50];
//	int ch;
//	while (EOF != (ch = getc(f))) {
//		if (ch == '\n')
//			++numberOfLines;
//	}
//	rewind(f);
//	for (int i = 0; i < numberOfLines; i++) {
//		fgets(str, 50, f);
//		std::cout << str;
//		str = manipulation(str);
//		hash.insertTable(str);
//	}
//	std::cout << "Data was copied from file" << file << std::endl;
//}
void keyboardInput(char* name, Hash& hash) {
	while (name[0] != 'q') {
		hash.insertTable(name);
		std::cout << "Input a name to Hash-table. If you want to exit input q" << std::endl;
		std::cin >> name;
	}
}
//char* manipulation(char* str) {
//	int size = strlen(str);
//	str[size-1] = '\0';
//	return str;
//}