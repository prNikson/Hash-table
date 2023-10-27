#pragma once
class Tree { // Класс Tree бинарного дерева
private:
    struct Node {
        char* value;
        const char* key;
        Node* left, *right;
        int val;
    };
    Node** allElem;
    Node* root;
    int countChilds;
    Node* create(Node*, const int&, char*, const char*);
    void printBinaryTree(Node*, int);
    //Node* retNode(Node*);
    Node* getNode(Node*);
    Node* deleteNode(Node*, char*, int);
public:
    int delNode(char*, int);
    Node* getRoot();
    Tree();
    void addRoot(const int&, char*, const char*);
    void print();
    void allElements();
    Node** getAllElements();
    int getCountChilds();
};
