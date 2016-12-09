#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

using namespace std;

/*
 * AVLTree.cpp
 *
 * AVL Tree (Balanced BST):
 * An AVL tree is a self-balancing BST with the property that at every node, the difference between the heights of its 
 * left and right subtrees is atmost 1.
 * If it were to be kept balanced and were to maintain this property then it becomes important to know which of the two is deeper 
 * and take a one-way difference, which is referred to as the balance factor.
 * The program here is a class-object implementation of the AVL tree.
 * 
 */

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} avl_node;

avl_node* root;

class AVLTree
{
	public:
		int height(avl_node *);
		int diff(avl_node *);
		avl_node *rr_rotation(avl_node *);
		avl_node *ll_rotation(avl_node *);
		avl_node *lr_rotation(avl_node *);
		avl_node *rl_rotation(avl_node *);
		avl_node *balance(avl_node *);
		avl_node *insert(avl_node *, int);
		void display(avl_node *, int);
		void inorder(avl_node *);
		void preorder(avl_node *);
		void postorder(avl_node *);
		AVLTree(){ root = NULL; }
}

main(){
	int choice, item;
	AVLTree avl;
	while(1){
		cout << "\n---------------------" << endl;
		cout << "AVL Tree Implementation" << endl;
		cout << "\n---------------------" << endl;
		cout << "1. Insert element into the tree" << endl;
		cout << "2. Display balanced AVL tree" << endl;
		cout << "3. Inorder Traversal" << endl;
		cout << "4. Preorder Traversal" << endl;
		cout << "5. Postorder Traversal" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter value to be inserted: ";
				cin >> item;
				root = avl.insert(root,item);
				break;
			case 2:
				if(root == NULL){ 
					cout << "Tree is Empty" << endl;
					continue;
				}
				cout << "Balanced AVL Tree: " << endl;
				avl.display(root,1);
				break;
			case 3:
				cout << "Inorder Traversal: " << endl;
				avl.inorder(root);
				cout << endl;
				break;
			case 4:
				cout << "Preorder Traversal: " << endl;
				avl.preorder(root);
				cout << endl;
				break;
			case 5:
				cout << "Postorder Traversal: " << endl;
				avl.postorder(root);
				cout << endl;
				break;
			case 6:
				exit(1);
				break;
			default:
				cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}

int AVLTree::height(avl_node *temp){
	int h=0;
	if(temp != NULL){
		int l_h = height(temp->left);
		int r_h = height(temp->right);
		int max_h = max(l_h, r_h);
		h = max_h + 1;
	}
	return h;
}

int AVLTree::diff(avl_node *temp){
	int l_h = height(temp->left);
	int r_h = height(temp->right);
	return l_h - r_h;
}

avl_node* AVLTree::rr_rotation(avl_node *parent){
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

avl_node* AVLTree::ll_rotation(avl_node *parent){
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

avl_node* AVLTree::lr_rotation(avl_node *parent){
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

avl_node* AVLTree::lr_rotation(avl_node *parent){
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

avl_node* AVLTree::balance(avl_node *temp){
	int bal_factor = diff(temp);
	if(bal_factor > 1)
	{
		if(diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if(bal_factor < -1){
		if(diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

avl_node* AVLTree::insert(avl_node *root, int value){
	if(root == NULL){
		root = new avl_node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if(value < root->data){
		root->left = insert(root->left,value);
		root = balance(root);
	}
	else if(value >= root->data){
		root->right = insert(root->right,value);
		root = balance(root);
	}
	return root;
}

void AVLTree::display(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level+1);
		cout<<endl;
		if (ptr == root)
			cout<<"Root->:  ";
		else
		{
			for (i = 0;i < level;i++)
				cout<<"       ";
		}
		cout << ptr->data;
		display(ptr->left, level+1);
	}
}

void AVLTree::preorder(avl_node *tree)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (tree != NULL)
	{
		cout<<ptr->data<<"  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void AVLTree::inorder(avl_node *tree)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (tree != NULL)
	{
		inorder(ptr->left);
		cout<<ptr->data<<"  ";
		inorder(ptr->right);
	}
}

void AVLTree::postorder(avl_node *tree)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (tree != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<"  ";
	}
}

