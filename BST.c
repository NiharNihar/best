#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{
	if (root == NULL)
		return true;
	if (l != NULL && root->data <= l->data)
		return false;
	if (r != NULL && root->data >= r->data)
		return false;
	return (isBST(root->left, l, root) && isBST(root->right, root, r));
} 

bool isBST3(Node *root) {
	static int data  = INT_MIN;
	if(root == NULL)
		return true;
	isBST3(root->left);
	if(root->data <= data)
		return false;
	data = root->data;
	isBST3(root->right);
	return true;
}

bool isBST2(Node* root)
{
	if(root == NULL)
		return true;
	static int prev = INT_MIN;
	if(root != NULL) {
		isBST2(root->left);
		if(root->data >= prev)
			return false;
		prev = root->data;
		isBST2(root->right);

	}
	return true;
	
}

struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

int main() 
{ 
	struct Node *root = newNode(3); 
	root->left	 = newNode(2); 
	root->right	 = newNode(5); 
	root->left->left = newNode(1); 
	//root->left->right = newNode(4); 

	if (isBST(root,NULL,NULL)) 
		cout << "Is BST" << endl; 
	else
		cout << "Not a BST" << endl; 

	if (isBST2(root)) 
		cout << "Is BST" << endl; 
	else
		cout << "Not a BST" << endl; 

	if (isBST3(root)) 
		cout << "Is BST" << endl; 
	else
		cout << "Not a BST" << endl; 
	return 0; 
} 

