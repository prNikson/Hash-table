#include <iostream>
#include "Tree.h"
Tree::Tree() :root(nullptr), countChilds(0), allElem(nullptr), flagDel(0) {}
typename Tree::Node* Tree::create(Node* tmp, const int& val, char* value, const char* key) { // Функция создания узла дерева
	if (tmp == nullptr) {
		tmp = new Node;
		tmp->value = value;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->val = val;
		tmp->key = key;
	}
	else if (val < tmp->val) {
		tmp->left = create(tmp->left, val, value, key);
	}
	else if (val > tmp->val) {
		tmp->right = create(tmp->right, val, value, key);
	}
	return tmp;
}
char* Tree::getValue() {
	if (root)
		return root->value;
}
void Tree::addRoot(const int& val, char* value, const char* key) { // Функция добавления узла дерева в структуру
	root = create(root, val, value, key);
	countChilds++;
}
void Tree::printRoot(Node* root) {
	if (root == nullptr)
		return;
	printRoot(root->left);
	std::cout << root->value << std::endl;
	printRoot(root->right);
}
void Tree::print() {
	printBinaryTree(root, 0);
	/*printRoot(root);*/
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
void Tree::getNode(Node* root, int count) {
	if (root == nullptr) {
		return;
	}
	*(allElem + count++) = root;
	getNode(root->left, count);
	getNode(root->right, count);
}
int Tree::getCountChilds() {
	return countChilds;
}
void Tree::allElements() {
	allElem = new Node * [countChilds];
	getNode(root, 0);
}
Tree::Node** Tree::getAllElements() {
	allElements();
	return allElem;
}
int Tree::delNode(char* key, int val) {
	root = deleteNode(root, key, val);
	if (flagDel) {
		countChilds--;
		flagDel = 0;
	}
	return 1;
}
Tree::Node* Tree::deleteNode(Node* root, char* key, int val) {
	if (root == nullptr)
		return root;
	else if (val < root->val)
		root->left = deleteNode(root->left, key, val);
	else if (val > root->val)
		root->right = deleteNode(root->right, key, val);
	else {
		if (root->left == nullptr && root->right == nullptr) {
			flagDel = 1;
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) {
			flagDel = 1;
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			flagDel = 1;
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* minValueNode = findMinValueNode(root->right);
			root->value = minValueNode->value;
			root->right = deleteNode(root->right, minValueNode->value, minValueNode->val);
		}
	}
	return root;
}
Tree::Node* Tree::findMinValueNode(Node* root) {
	Node* current = root;
	while (current && current->left != nullptr) {
		current = current->left;
	}
	return current;
}
Tree::Node* Tree::search(Node* root, char* name, int val) {
	if (root == nullptr || !(strcmp(name, root->value)))
		return root;
	else if (val < root->val)
		return search(root->left, name, val);
	else
		return search(root->right, name, val);
}
void Tree::searchNode(char* name, int val) {
	root = search(root, name, val);
	if (root)
		std::cout << "Found:" << std::endl << root->value << std::endl;
	else
		std::cout << "Not found" << std::endl;
}