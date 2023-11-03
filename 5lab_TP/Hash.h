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
	void deleteElement(char*, int, int);
public:
	Hash();
	void insertTable(char*);
	void printTable();
	void reHashTable();
	void fileInput(char*);
	void keyboardInput();
	void deleteElem(char*);
	void search(char*);
};