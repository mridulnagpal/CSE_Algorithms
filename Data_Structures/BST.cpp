#include<iostream>
#include<cstdlib>

using namespace std;

/* Binary Search Tree (BST):
 *
 * A binary search tree is a node-based binary tree with the following properties:
 * 1. The left subtree of a node contains only nodes with keys less than the node's key.
 * 2. The right subtree of a node contains only nodes with keys greater than the node's key.
 * 3. The left and right subtrees must themselves be binary search trees.
 *
 * These properties provide us an ordering among the keys.
 * Operations:
 *
 * 1. Insert(n): Inserts a node in the BST and gives it the value n.
 * 2. Delete(n): Deletes the node with the value n.
 * 3. Search(n): Searches for node with key n.
 * 4. Minimum(): Gives the key of the left-most node.
 * 5. Maximum(): Gives the key of the right-most node.
 * 6. Inorder(): Gives an inorder line-representation of the BST.
 * 
 * Following is the implementation of the BST as a class.
 */

typedef struct node{
	int key;
	sturct node* left;
	struct node* right;
} Node;

Node* root;
class BST
{
	public:
		void find(int, Node **, Node **);
		void insert(Node *, Node*);
		void del(int);
		void case_a(Node *, Node *);
		void case_b(Node *, Node *);
		void case_c(Node *, Node *);
		void preorder(Node *);
		void inorder(Node *);
		void postorder(Node *);
		void display(Node *, int);
		BST(){ root=NULL; }
};

int main()
{
	int choice, num;
	BST bst;
	Node *temp;
	while(1)
	{
		cout << "--------------------------" << endl;
		cout << "BST Data Structure Service" << endl;
		cout << "--------------------------" << endl;
		cout << "1. Insert Element" << endl;
		cout << "2. Delete Element" << endl;
		cout << "3. Inorder Traversal" << endl;
		cout << "4. Preorder Traversal" << endl;
		cout << "5. Post-Order Traversal" << endl;
		cout << "6. Display" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				temp = new Node;
				cout << "Enter the number to be inserted : ";
				cin >> temp->key;
				bst.insert(root,temp);
				break;
			case 2:
				if(root == NULL){ cout << "Tree is empty. Nothing to delete." << endl; continue; }
				cout << "Enter the number to be deleted : ";
				cin >> num;
				bst.del(num);
				break;
			case 3:
				cout << "Inorder traversal of BST:" << endl;
				bst.inorder(root);
				cout << endl;
				break;
			case 4:
				cout << "Preorder traversal of BST:" << endl;
				bst.preorder(root);
				cout << endl;
				break;
			case 5:
				cout << "Postorder traversal of BST:" << endl;
				bst.postorder(root);
				cout << endl;
				break;
			case 6:
				cout << "Display BST:" << endl;
				bst.display(root,1);
				cout << endl;
				break;
			case 7:
				exit(1);
			default:
				cout << "Wrong choice" << endl;
		}
	}
}

void BST::find(int item, Node **par, Node **loc){
	Node *ptr, *ptrsave;
	if(root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if(item < root->key)
		ptr = root->left;
	else
		ptr = root->right;
	ptrsave = root;
	while(ptr!=NULL){
		if(item == ptr->key){
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(item < ptr->key)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}

void BST::insert(Node *tree, Node *newnode)
{
    if (root == NULL)
    {
        root = new Node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
		}
		else
		{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
}

void BST::del(int item)
{
    Node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}

void BST::case_a(Node *par, Node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}

void BST::case_b(Node *par, Node *loc)
{
    Node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}

void BST::case_c(Node *par, Node *loc)
{
    Node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

void BST::preorder(Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BST::inorder(Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}
 
void BST::postorder(Node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}

void BST::display(Node *ptr, int level)
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
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}
