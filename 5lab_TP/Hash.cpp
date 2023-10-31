#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hash.h"
Hash::Hash() {
	current = 0;
	currentCountNode = 0;
	arr = new Tree * [N];
	for (int i = 0; i < N; i++) {
		arr[i] = nullptr;
	}
	arrNode = nullptr;
}
int* Hash::sumInitials(char* name) {
	int len = strlen(name);
	int ascii;
	int sum = 0;
	int* arr_str = new int[3] {};
	int count = 0;
	for (int i = 0; i < len; i++) {
		ascii = (int)name[i];
		if (name[i] == ' ' || i == len - 1) {
			if (i == len - 1) {
				sum += ascii % 13;
			}
			*(arr_str + count) += sum;
			sum = 0;
			count++;
			continue;
		}
		sum += ascii % 13;
	}
	return arr_str;
}
int Hash::HashFunc(char* value) {
	int sum = 0;
	int* arr = sumInitials(value);
	int rev_num = 0;
	for (int i = 0; i < 3; i++) {
		int n = arr[i];
		while (n > 0) {
			rev_num = rev_num * 10 + n % 10;
			n = n / 10;
		}
		sum += rev_num;
		rev_num = 0;
	}
	return sum;
}
int Hash::getIndex(int sum, int n) {
	return sum % n;
}
void Hash::insertTable(char* value) {
	if (current >= 0.75 * N || currentCountNode > current)
		reHashTable();
	int val = HashFunc(value);
	int index = getIndex(val, N);
	if (arr[index] == nullptr)
		arr[index] = new Tree;
	arr[index]->addRoot(val, value, Name);
	currentCountNode++;
	current++;
}
void Hash::printTable() {
	for (int i = 0; i < N; i++) {
		if (arr[i] != nullptr) {
			arr[i]->print();
			std::cout << "__________" << std::endl;
		}
		else {
			std::cout << "Empty field" << std::endl;
			std::cout << "__________" << std::endl;
		}
	}
}
void Hash::retNode(Tree* tree) {
	int count = tree->getCountChilds();
	arrNode = new NodeStruct * [count];
	for (int i = 0; i < count; i++)
		arrNode[i] = new NodeStruct;
	for (int i = 0; i < count; i++) {
		arrNode[i]->value = tree->getAllElements()[i]->value;
		arrNode[i]->key = Name;
		arrNode[i]->val = HashFunc(arrNode[i]->value);
	}
}
void Hash::reHashTable() {
	int ter = N + 1;
	Tree** temp = new Tree * [ter];
	for (int i = 0; i < ter; i++)
		temp[i] = new Tree;
	for (int i = 0; i < N; i++) {
		if (arr[i] != nullptr) {
			retNode(arr[i]);
			int count = arr[i]->getCountChilds();
			for (int j = 0; j < count; j++) {
				int index = getIndex(arrNode[j]->val, ter);
				temp[index]->addRoot(arrNode[j]->val, arrNode[j]->value, Name);
			}
			for (int k = 0; k < count; k++) {
				delete arrNode[k];
			}
		}
	}
	arr = temp;
	arrNode = nullptr;
	N = ter;
}
void Hash::deleteElement(int index, char* key, int val) {
	for (int i = 0; i < N; i++) {
		if (arr[i]->delNode(key, val))
			std::cout << "Deleting is succseefully" << std::endl;
		else
			std::cout << "Deleting is not successfully" << std::endl;
		break;
	}
}
char* manipulation(char* str) {
	int size = strlen(str);
	str[size - 1] = '\0';
	return str;
}
void Hash::fileInput(char* file) {
	int numberOfLines = 0;
	FILE* f = fopen(file, "r");
	int ch;
	char* str = new char[50];
	while (EOF != (ch = getc(f))) {
		if (ch == '\n')
			++numberOfLines;
	}
	rewind(f);
	char** ar = new char* [numberOfLines];
	for (int i = 0; i < numberOfLines; i++) {
		ar[i] = new char[50];
	}
	int count = 0;
	for (int i = 0; i < numberOfLines; i++) {
		fgets(str, 50, f);
		str = manipulation(str);
		strcpy(ar[i], str);
		insertTable(ar[i]);
	}
	std::cout << "Data was copied from file" << file << std::endl;

}