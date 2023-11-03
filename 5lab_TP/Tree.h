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
    int flagDel;
private:
    Node* create(Node*, const int&, char*, const char*);
    void printBinaryTree(Node*, int);
    //Node* retNode(Node*);
    void getNode(Node*, int);
    Node* deleteNode(Node*, char*, int);
    Node** allElem;
    void printRoot(Node*);
    Node* findMinValueNode(Node*);
    Node* search(Node*, char*, int);
public:
    Tree();
    char* getValue();
    void addRoot(const int&, char*, const char*);
    void print();
    void allElements();
    Node** getAllElements();
    int getCountChilds();
    int delNode(char*, int);
    void searchNode(char*, int);
};
