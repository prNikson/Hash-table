#pragma once
#include <iostream>
#include "Tree.h"
class Hash {
private:
	struct NodeStruct {
		char* value;
		const char* key;
		int val;
	};
	NodeStruct** arrNode;
	const char* Name = "Фамилия Имя Отчество";
	Tree** arr;
	int N = 5;
	int current;
    int currentCountNode;
    int* sumInitials(char*);
	void retNode(Tree*);
	int HashFunc(char*);
	int getIndex(int, int);
	int validString(char*, int);
	int numberLines(FILE*);
public:
	Hash();
	void insertTable(char*);
	void deleteElement(int, char*, int);
	void printTable();
	void reHashTable();
	void fileInput(char*);
	void keyboardInput();
};