#include <iostream>
#include "Tree.h"
Tree::Tree() :root(nullptr), countChilds(0), allElem(nullptr) {}
typename Tree::Node* Tree::create(Node* tmp, const int& val, char* value, const char* key) { // ������� �������� ���� ������
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
//Tree::Node* Tree::retNode(Node* root) {
//    if (root == nullptr)
//        return;
//    else
//        return root;
//    retNode(root->left);
//    retNode(root->right);
//}
void Tree::addRoot(const int& val, char* value, const char* key) { // ������� ���������� ���� ������ � ���������
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
void Tree::printBinaryTree(Node* root, int depth) { // ������� ������ ������ �� �����
    std::cout << std::endl;
    if (root == nullptr)
        return;

    // ������� ������ ���������
    printBinaryTree(root->right, depth + 1);

    // ������� ������� � ����������� �� ������� ����
    for (int i = 0; i < depth; i++)
        std::cout << "    ";

    // ������� �������� �������� ����
    std::cout << root->value << std::endl;

    // ������� ����� ���������
    printBinaryTree(root->left, depth + 1);
}
Tree::Node* Tree::getRoot() {
    return root;
}
Tree::Node* Tree::getNode(Node* root) {
    int static count = 0;
    if (root != nullptr)
        return root;
    getNode(root->left);
    *(allElem + count) = root;
    count++;
    getNode(root->right);
}
int Tree::getCountChilds() {
    return countChilds;
}
void Tree::allElements() {
    allElem = new Node * [countChilds];
    getNode(root);

}
Tree::Node** Tree::getAllElements() {
    allElements();
    return allElem;
}
int Tree::delNode(char* key, int val) {
    Node* temp = deleteNode(root, key, val);
    return (temp == nullptr) ? 0 : 1;
}
Tree::Node* Tree::deleteNode(Node* root, char* key, int val) {
    Node* p, * v;
    if (root == nullptr)
        return root;
    else if (val <= root->val)
        root = deleteNode(root->left, key, val);
    else if (val > root->val)
        root = deleteNode(root->right, key, val);
    else if (!(strcmp(root->value, key))) {
        p = root;
        if (root->right == nullptr)
            root = root->left;
        else if (root->left == nullptr)
            root = root->right;
        else {
            v = root->left;
            if (v->right) {
                while (v->right->right)
                    v = v->right;
                root->val = v->right->val;
                root->key = v->right->key;
                root->value = v->right->value;
                p = v->right;
                v->right = v->right->left;
            }
            else {
                root->val = v->val;
                root->key = v->key;
                root->value = v->value;
                p = v;
                root->left = root->left->left;
            }
        }
        delete p;
    }
    return root;
}