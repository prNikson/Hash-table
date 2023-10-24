#include "Hash.h"
#include <iostream>
Hash::Hash() {
    current = 0;
    currentCountNode = 0;
    size = N;
    arr = new Tree * [N];
    for (int i = 0; i < N; i++)
        arr[i] = new Tree();
}
int* Hash::sumInitials(char* name) {
    int len = strlen(name);
    int ascii;
    int sum = 0;
    int* arr = new int[N] {};
    int count = 0;
    for (int i = 0; i < len; i++) {
        ascii = (int)name[i];
        if (name[i] == '\0') {
            arr[count] += sum;
            sum = 0;
            count++;
        }
        sum += ascii;
    }
    return arr;
}
int Hash::HashFunc(char* value) {
    int sum = 0;
    int* arr = sumInitials(value);
    int rev_num = 0;
    for (int i = 0; i < N; i++) {
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
int Hash::getIndex(int sum) {
    return sum % N;
}
void Hash::insertTable(char* value) {
    if (current >= 0.75 * size || currentCountNode > current)
        reHashTable();
    int index = getIndex(HashFunc(value));
    int val = HashFunc(value);
    arr[index]->addRoot(val, value, Name);
    currentCountNode++;
    current++;
}
void Hash::printTable() {
    for (int i = 0; i < N; i++) {
        arr[N]->print();
        std::cout << "__________" << std::endl;
    }
}
void Hash::reHashTable() {
    Tree** temp = new Tree * [2 * N];
    for (int i = 0; i < N; i++) {
        temp[i]->addRoot()
    }
}