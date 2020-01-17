#include <iostream>
#include <vector>

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
	else if (key > node->key)
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

void postorderTrav(Node *root) {
	if (root != NULL)
	{
		postorderTrav(root->left);
		postorderTrav(root->right);

		cout << "Node: " << root->key;
		if (root->parent == NULL)
			cout << " (ROOT)";
		cout << endl;
	}
}

void preorderTrav(Node *root) {
	if (root == NULL)
		return;

	cout << "Node: " << root->key;
	if (root->parent == NULL)
		cout << " (ROOT)";
	cout << endl;

	preorderTrav(root->left);
	preorderTrav(root->right);

}

int treeHeight(Node *root) {
	if (root == NULL)
		return -1;

	return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

Node* treeSearch(Node* root, int key)
{
	if (root == NULL) {
		cout << "ERROR: " << key << " is not in the BST!";
		return root;
	}
	
	if (root->key == key) {
		cout << root->key;
	}

	if (root->key < key) {
		cout << root->key << endl;
		return treeSearch(root->right, key);
	}

	if (root->key > key) {
		cout << root->key << endl;
		return treeSearch(root->left, key);
	}

	return root; 
}

Node * minValueNode(Node* node)
{
	Node* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

Node* deleteNode(Node* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}

		Node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
	// Menu naviation variables
	int choice = -1;
	int keyValue = 0;

	// Create arrays for tree key values and empty Node array
	int treeValues[10] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};

	cout << "Building BST from given array..." << endl << endl;

	Node* root = NULL;
	root = insert(root, treeValues[0]);

	// Create binary search tree from Node array
	for (int i = 0; i < 10; i++)
	{
		insert(root, treeValues[i]);
	}

	// User menu
	cout << "--Binary Tree Action Menu--" << endl;
	cout << "0 to exit program" << endl;
	cout << "1 to display inorder traversal" << endl;
	cout << "2 to display postorder traversal" << endl;
	cout << "3 to display preorder traversal" << endl;
	cout << "4 to calculate tree height" << endl;
	cout << "5 to search for a value" << endl;
	cout << "6 to delete a value" << endl << endl;

	while (choice != 0) {

		cout << "Enter choice (1-6): ";
		cin >> choice;
		cout << endl << endl;

		switch (choice) {
			// Exit Program
			case 0:
				break;

			// Inorder Traversal 
			case 1:
				cout << "Inorder Traversal" << endl;
				inorderTrav(root);
				break;

			// Postorder Traversal
			case 2:
				cout << "Postorder Traversal" << endl;
				postorderTrav(root);
				break;

			// Preorder Traversal
			case 3:
				cout << "Preorder Traversal" << endl;
				preorderTrav(root);
				break;

			// Tree Height
			case 4:
				cout << "Tree Height: " << treeHeight(root);
				break;

			// Tree Search
			case 5:
				cout << "Enter value to search for: ";
				cin >> keyValue;
				cout << endl << "Path taken for search: " << endl;
				treeSearch(root, keyValue);
				break;

			// Delete Node
			case 6:
				cout << "Enter a value to delete: ";
				cin >> keyValue;
				deleteNode(root, keyValue);
				break;

			// Invalid Menu Choice
			default:
				cout << "Please enter a valid number.";
		}

		cout << endl << endl;
	}

	system("pause");
	return 0;
}