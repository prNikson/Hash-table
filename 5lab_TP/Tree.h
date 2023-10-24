#pragma once
#pragma once
#include <iostream>
class Tree { // Класс Tree бинарного дерева
private:
    struct Node {
        char* value;
        const char* key;
        Node* left, *right;
        int val;
    };
    Node* root;
    int countChilds;
    Node* create(Node*, const int&, char*, const char*);
    void printBinaryTree(Node*, int);
public:
    Tree();
    void addRoot(const int&, char*, const char*);
    void print();
    void swap();
    int getCountChilds();
};
Tree::Tree() :root(nullptr), countChilds(0) {}
typename Tree::Node* Tree::create(Node* tmp, const int& val, char* value, const char* key) { // Функция создания узла дерева
    if (tmp == nullptr) {
        tmp = new Node;
        tmp->value = value;
        tmp->left = nullptr;
        tmp->right = nullptr;
        tmp->val = val;
        tmp->key = key;
    }
    else if (val <= tmp->val) {
        tmp->left = create(tmp->left, val, value, key);
    }
    else if (val > tmp->val) {
        tmp->right = create(tmp->right, val, value, key);
    }
    return tmp;
}
void Tree::addRoot(const int& val, char* value, const char* key) { // Функция добавления узла дерева в структуру
    root = create(root, val, value, key);
    countChilds++;
}
/*template <typename int>
void Tree<int>::printRoot(Node* root) {
    if (root == nullptr)
        return;
    printRoot(root->left);
    for (int i = 0; i < root->amount; i++)
        std::cout << root->value << std::endl;
    printRoot(root->right);
}*/
void Tree::print() {
    printBinaryTree(root, 0);
}
void Tree::printBinaryTree(Node* root, int depth) { // Функция вывода дерева на экран
    std::cout << std::endl;
    if (root == nullptr)
        return;

    // Выводим правое поддерево
    printBinaryTree(root->right, depth + 1);

    // Выводим отступы в зависимости от глубины узла
    for (int i = 0; i < depth; i++)
        std::cout << "    ";

    // Выводим значение текущего узла
    std::cout << root->value << std::endl;

    // Выводим левое поддерево
    printBinaryTree(root->left, depth + 1);
}
int Tree::getCountChilds() {
    return countChilds;
}