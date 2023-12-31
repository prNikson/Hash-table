#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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
	if (index == 0)
		std::cout << value << std::endl;
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
void Hash::deleteElement(char* key, int val, int index) {
	if (arr[index] != nullptr) {
		if (arr[index]->delNode(key, val)) {
			if (arr[index]->getCountChilds() == 0) {
				arr[index] = nullptr;
			}
			std::cout << "Deleting is succseefully" << std::endl;
			return;
		}
	}
	std::cout << "Deleting is not succseefully. Check the correctness of input" << std::endl;
}
int Hash::numberLines(FILE* file) {
	int numOfLines = 0;
	char ch;
	while (EOF != (ch = getc(file))) {
		if (ch == '\n')
			++numOfLines;
	}
	rewind(file);
	return numOfLines + 1;
}
char* manipulation(char* str) {
	int size = strlen(str);
	if(str[size-1] == '\n')
		str[size - 1] = '\0';
	return str;
}
void Hash::fileInput(char* file) {
	char ch2;
	FILE* f = fopen(file, "r");
	if (f == NULL) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	int numberOfLines = numberLines(f);
	char** ar = new char* [numberOfLines];
	for (int i = 0; i < numberOfLines; i++) {
		int count = 0;
		ch2 = getc(f);
		while (ch2 != '\n' && ch2 != EOF)
		{
			if (!((ch2 >= 65 && ch2 <= 90) || (ch2 >= 97 && ch2 <= 122) || (ch2 == 32))) {
				std::cout << "Non-valid input from file " << std::endl;
				return;
			}
			count++;
			ch2 = getc(f);
		}
		ar[i] = new char[count + 1];
	}
	rewind(f);
	for (int i = 0; i < numberOfLines; i++) {
		int size = strlen(ar[i]);
		char* str = new char[size];
		fgets(str, size, f);
		str = manipulation(str);
		strcpy(ar[i], str);
		insertTable(ar[i]);
	}
	fclose(f);
	std::cout << "Data was copied from file" << file << std::endl;
}
int Hash::validString(char* name, int size) {
	for (int i = 0; i < size; i++) {
		if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || name[i] == 32 || name[i] == '\n')) {
			return 0;
		}
	}
	return 1;
}
void Hash::keyboardInput() {
	int num;
	char ch;
	char q[50];
	std::cout << "Input a count of words:" << std::endl;
	std::cin >> num;
	while (std::cin.fail()) {
		std::cout << "Not number. Try one more" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> num;
	}
	char** ar = new char* [num];
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; i++) {
		std::cout << "Input value" << std::endl;
		ar[i] = new char[50];
		std::cin.getline(ar[i], 50);
		if (!validString(ar[i], strlen(ar[i]))) {
			std::cout << "Non-valid input" << std::endl;
			return;
		}
		insertTable(ar[i]);
	}
}
void Hash::deleteElem(char* name) {
	int val = HashFunc(name);
	int index = getIndex(val, N);
	deleteElement(name, val, index);
}
void Hash::search(char* name) {
	int val = HashFunc(name);
	int index = getIndex(val, N);
	if (arr[index] != nullptr) {
		arr[index]->searchNode(name, val);
	}
}