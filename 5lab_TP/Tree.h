#pragma once
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
    //Node* retNode(Node*);
    void getNode(Node*, int);
    Node* deleteNode(Node*, char*, int);
    Node** allElem;
    void printRoot(Node*);
public:
    char* getValue();
    int delNode(char*, int);
    Tree();
    void addRoot(const int&, char*, const char*);
    void print();
    void allElements();
    Node** getAllElements();
    int getCountChilds();
};
