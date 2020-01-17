#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

Node* createNode(int value)
{
	Node* newNode = new Node;
	newNode->key = value;
	newNode->left = newNode->right = newNode->parent = NULL;
	return newNode;
}

Node* insert(Node* node, int key)
{
	if (node == NULL) return createNode(key);

	if (key < node->key)
	{
		Node *lchild = insert(node->left, key);
		node->left = lchild;

		lchild->parent = node;
	}
	else if (key >= node->key)
	{
		Node *rchild = insert(node->right, key);
		node->right = rchild;
		rchild->parent = node;
	}

	return node;
}

void inorderTrav(Node *root)
{
	if (root != NULL)
	{
		inorderTrav(root->left);
		cout << "Node: " << root->key;
		if (root->parent == NULL)
			cout << " (ROOT)";
		cout << endl;
		inorderTrav(root->right);
	}
}

int treeHeight(Node *root) {
	if (root == NULL)
		return -1;

	return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

void deleteTree(Node* root)
{
	if (root == NULL) return;

	deleteTree(root->left);
	deleteTree(root->right);

	free(root);
}

int main()
{
	srand(time(NULL));
	int heightSum = 0;

	// N = 100, t = 5
	for (int i = 0; i < 5; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 99; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 100 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 5 << endl << endl;

	heightSum = 0;

	// N = 500, t = 5
	for (int i = 0; i < 5; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 499; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 500 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 5 << endl << endl;
	heightSum = 0;

	// N = 1000, t = 5
	for (int i = 0; i < 5; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 999; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 1000 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 5 << endl << endl;
	heightSum = 0;
	cout << endl << endl << endl;

// ------------------------------------------------------------------------ //

	// N = 100, t = 10
	for (int i = 0; i < 10; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 99; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 100 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 10 << endl << endl;

	heightSum = 0;

	// N = 500, t = 10
	for (int i = 0; i < 10; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 499; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 500 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 10 << endl << endl;
	heightSum = 0;

	// N = 1000, t = 10
	for (int i = 0; i < 10; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 999; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 1000 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 10 << endl << endl;
	heightSum = 0;
	cout << endl << endl << endl;

// ------------------------------------------------------------------------//

	// N = 100, t = 15
	for (int i = 0; i < 15; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 99; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 100 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 15 << endl << endl;

	heightSum = 0;

	// N = 500, t = 15
	for (int i = 0; i < 15; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 499; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 500 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 15 << endl << endl;
	heightSum = 0;

	// N = 1000, t = 15
	for (int i = 0; i < 15; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 999; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		cout << "N = 1000 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 15 << endl << endl;
	heightSum = 0;

//----------------------------------------------------------------------------------//

	// Example output for program proof

	// N = 100, t = 5
	for (int i = 0; i < 5; i++) {
		Node* root = NULL;
		root = insert(root, (rand() % 10000) + 1);

		for (int j = 0; j < 99; j++) {
			insert(root, (rand() % 10000) + 1);
		}

		if (i == 0) {
			cout << "Example inorder traversal of N = 100 random-value BST:" << endl << endl;
			inorderTrav(root);
			cout << endl << endl;
		}

		cout << "N = 100 Height " << i + 1 << ": " << treeHeight(root) << endl;
		heightSum = heightSum + treeHeight(root);
		deleteTree(root);
	}

	cout << "Average Height: " << heightSum / 5 << endl << endl;

	system("pause");
	return 0;
}