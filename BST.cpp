#include <iostream>

using namespace std;

class BSTNode
{
public:	
	int value;
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;

	BSTNode(int value)
	{
		this->value = value;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

int min(BSTNode* root);
int max(BSTNode* root);
BSTNode* searchNode(BSTNode* root, int value);
BSTNode* insertNode(BSTNode* root, int value);
BSTNode* successor(BSTNode* node);
void delete1or0children(BSTNode* node);
void delete2children(BSTNode* node);
void deleteNode(BSTNode* root, int value);
void display(BSTNode* root);

int main()
{
	BSTNode* root = new BSTNode(4);
	display(root);
	cout << "\n";
	insertNode(root, 2);
	insertNode(root, 6);
	insertNode(root, 1);
	insertNode(root, 7);
	insertNode(root, 3);
	insertNode(root, 5);
	display(root);	

	BSTNode* temp = searchNode(root, 7);
	cout << "the value is " << temp->value << "\n";

	cout << "The max value is "  << max(root) << "\n";

	deleteNode(root, 6);
	deleteNode(root, 2);

	display(root);

	return 0;
}

// return the min of the binary search tree
int min(BSTNode* root)
{
	if (root == NULL)
		return -1;

	BSTNode* node = root;

	while (node->left != NULL)
	{
		node = node->left;
	}

	return node->value;
}


int max(BSTNode* root)
{
	if (root == NULL)
		return -1;

	BSTNode* node = root;

	while (node->right != NULL)
	{
		node = node->right;
	}

	return node->value;
}

// return NULL if not found
BSTNode* searchNode(BSTNode* root, int value)
{
	while (root != NULL)
	{
		if (root->value == value)
			return root;
		if (value >= root->value)
			root = root->right;
		else
			root = root->left;
			
	}

	return root;

}



// insert a node with specific value and return the root of the tree
BSTNode* insertNode(BSTNode* root, int value)
{
	//cout << root << "\n";
	BSTNode* new_node = new BSTNode(value);

	if (root == NULL)
	{
		return new_node;
	}

	//find the insert position
	BSTNode* parent = root;
	BSTNode* n = root;

	while (n != NULL)
	{
		parent = n;
		if (value > n->value)
			n = n->right;
		else
			n = n->left;
	}

	new_node->parent = parent;
	if (value > parent->value)
		parent->right = new_node;
	else
		parent->left = new_node;

	return root;
}

// find the next node that will be printed out in inorder traversal
BSTNode* successor(BSTNode* node)
{
	if (node->right != NULL)
		return node->right;

	BSTNode* p = node->parent;
	while (p != NULL && p->left != node)
	{
		node = p;
		p = p->parent;
	}

	return p;
}

void delete1or0children(BSTNode* node)
{
	if (node->left == NULL || node->right == NULL)
	{
		if (node->parent->left == node)
			node->parent->left = node->left;
		else
			node->parent->right = node->right;

		if (node->left != NULL)
			node->left->parent = node->parent;
		if (node->right != NULL)
			node->right->parent = node->parent;

		delete node;
	}
}


void delete2children(BSTNode* node)
{
	BSTNode* s_node = successor(node);
	delete1or0children(s_node);
	node->value = s_node->value;
}


void deleteNode(BSTNode* root, int value)
{
	BSTNode* node = searchNode(root, value);

	if (node->left != NULL && node->right != NULL)
		delete2children(node);
	else
		delete1or0children(node);

}

// in order traversal
void display(BSTNode* root)
{
	if (root != NULL)
	{
		display(root->left);
		cout << root->value << " ";
		display(root->right);
	}
}


