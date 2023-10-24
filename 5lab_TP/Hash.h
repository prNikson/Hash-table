#pragma once
#include "Tree.h"
class Hash {
private:
	struct Node {
		char* value;
		const char* key;
		Node* left, *right;
		int val;
	};
	const char* Name = "Фамилия Имя Отчество";
    Tree** arr;
	int N = 3;
	int current, size;
    int currentCountNode;
    int* sumInitials(char*);
public:
	Hash();
	int HashFunc(char*);
	int getIndex(int);
	void insertTable(char*);
	void deleteElement();
	void printTable();
	void reHashTable();
};