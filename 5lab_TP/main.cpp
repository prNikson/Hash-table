#include "Hash.h"
#include <iostream>
#include <fstream>
void fileInput(char*, Hash&);
void keyboardInput(char*, Hash&);
int main() {
    while (true) {
        Hash hash;
        char* file;
        char* name;
        char ch;
        std::cout << "f - input file, k - keyboard, q - quit, p - print a table" << std::endl;
        std::cin >> ch;
        switch (ch)
        {
        case 'f':
            file = new char[30];
            std::cout << "Input name of file" << std::endl;
            std::cin >> file;
            fileInput(file, hash);
            break;
        case 'q':
            break;
        case 'k':
            std::cout << "Input a name to Hash-table. If you want to exit input q" << std::endl;
            name = new char[50];
            std::cin >> name;
            keyboardInput(name, hash);
            std::cout << "Exit" << std::endl;
            break;
        case 'p':
            hash.printTable();
        default:
            std::cout << "Incorrect input. Try one more" << std::endl;
            break;
        }
    }
    Hash hash;
    char ch[30] = "Nikonorov Sergey Andreevich";
    char ch2[30] = "Karaberov Ivan Vladimirovich";
    char ch3[30] = "Nekorkin Dmitry Sergeevich";
    hash.insertTable(ch);
    hash.insertTable(ch2);
    hash.insertTable(ch3);
    hash.printTable();
    return 0;
}
void fileInput(char* file, Hash& hash) {
    std::fstream f(file);
    char* ch = new char[50];
    if (f.is_open()) {
        while (f >> ch) {
            hash.insertTable(ch);
        }
    }
    std::cout << "Data was copied from file " << file << std::endl;
}
void keyboardInput(char* name, Hash& hash) {
    while (name[0] != 'q') {
        hash.insertTable(name);
        std::cout << "Input a name to Hash-table. If you want to exit input q" << std::endl;
        std::cin >> name;
    }
}