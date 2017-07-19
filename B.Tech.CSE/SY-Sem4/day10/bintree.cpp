#include<iostream>
#include<algorithm>
#define CLR (system("clear"))

using namespace std;

void getch(){cin.ignore().ignore();}

//basic element of a binary tree.. u can say its root

struct btnode
{
	int data;
	btnode *left,*right;
	
	btnode(const int& element=0, btnode* leftChild=NULL, btnode* rightChild=NULL)
	{
		data=element;
		left=leftChild;
		right=rightChild;
	}
};

//This is a class defn of binary search tree

class BSTree 
{
	private:
		btnode* root;
		int treeSize;
		
		static void (*visit)(btnode*);  // a function ptr, basically a task to do while traversing a tree		
		static void pre_Order(btnode* t);
		static void in_Order(btnode* t);
		static void post_Order(btnode* t);		
		static void dispose(btnode* t){delete t;}				
		int height(btnode* t);
			
	public:
		BSTree() {root=NULL; treeSize=0;}
		~BSTree() {erase();}
		
		//ADT methods
		bool empty() const {return treeSize==0;}
		int size() const {return treeSize;}		
		
		void preOrder(void (*dvisit)(btnode*))
		{BSTree::visit=dvisit; pre_Order(root);}
		
		void inOrder(void (*dvisit)(btnode*))
		{BSTree::visit=dvisit; in_Order(root);}
		
		void postOrder(void (*dvisit)(btnode*))
		{BSTree::visit=dvisit; post_Order(root);}		
		
		//xtras
		static void showData(btnode* t) {cout<<t->data<<' ';}		
		void traverse() {inOrder(showData);}		
		void erase() { postOrder(dispose); root=NULL; treeSize=0;}
		int height() {return height(root);}
		
		//bst methods
		bool search(int n, btnode* &parent, btnode* &x) const;		
		void insert(int n);	
		void del(int num);				
};
//instantiate func ptr visit:
void (*BSTree::visit)(btnode*) = BSTree::showData;

//function defn:
void BSTree::insert(int n)
{
	bool found;
	btnode *t, *parent, *x;
	
	found=search(n,parent,x);
	if(found) {
		cout<<endl<<"Such node already exist!!\n"; getch();     //code for only uniq elements i.e an ordered set, as defined
		/*t=new btnode;
		t->data=n;		
		t->right=x->right;		//code for duplicate values allowed in tree
		x->right=t;		
		
		treeSize++;*/
	}
	else {
		t=new btnode;
		t->data=n;
		if(parent==NULL) BSTree::root=t;
		else n<parent->data?parent->left=t : parent->right=t;
		
		treeSize++;
	}
}


void BSTree::del(int num)
{
	bool found;
	btnode *xsucc, *parent=NULL, *x=NULL;
	
	if(BSTree::root==NULL)
	{
		cout<<"\nTree is empty!!\n"; return;
	}			
	found=search(num,parent,x);
	
	if(!found) {
		cout<<"\nNode to be deleted is not found!!\n"; getch(); return;
	}
	
	if(x->left!=NULL && x->right!=NULL)
	{
		//cout<<"*case1*\n";
		parent=x;
		xsucc=x->right;
	
		while(xsucc->left!=NULL) {parent=xsucc; xsucc=xsucc->left;}
		x->data=xsucc->data;
		x=xsucc;				
	}
	
	if(x->left==NULL && x->right==NULL)
	{
		//cout<<"*case2*\n";
		if(parent!=NULL) {
			if(parent->right==x) parent->right=NULL;
			else parent->left=NULL;			
		}
		else root = NULL;
		
		delete x;
		treeSize--;
		return;
	}
	
	if(x->left==NULL && x->right!=NULL)
	{
		//cout<<"*case3*\n";
		if(parent!=NULL) {
			if(parent->left==x) parent->left=x->right;
			else parent->right=x->right;	
		}
		else root = root->right;
		
		delete x; treeSize--;
		return;
	}
	if(x->left!=NULL && x->right==NULL)
	{
		//cout<<"*case4*\n";
		if(parent!=NULL) {
			if(parent->left==x) parent->left=x->left;
			else parent->right=x->left;
		}		
		else root = root->left;
		
		delete x; treeSize--;
		return;
	}
}


bool BSTree::search(int n, btnode* &parent, btnode* &x) const
{
	btnode* q;			
	parent = NULL;			
	if(BSTree::root==NULL) return false;
			
	q=BSTree::root;
	while(q!=NULL)
	{
		if(q->data==n)
		{					
			x=q;
			return true;
		}
		if(n<q->data)
		{
			parent=q;
			q=q->left;
		}
		else{
			parent=q;
			q=q->right;
		}
	}			
	return false;
}


void BSTree::pre_Order(btnode* t)
{
	if(t!=NULL)
	{
		BSTree::visit(t);
		pre_Order(t->left);
		pre_Order(t->right);
	}
}

void BSTree::in_Order(btnode* t)
{
	if(t!=NULL)
	{
		in_Order(t->left);
		BSTree::visit(t);		
		in_Order(t->right);
	}
}

void BSTree::post_Order(btnode* t)
{
	if(t!=NULL)
	{		
		post_Order(t->left);
		post_Order(t->right);
		BSTree::visit(t);
	}
}

int BSTree::height(btnode* t)
{
	if(t==NULL) return 0;
	int hl=height(t->left);
	int hr=height(t->right);
	if(hl>hr) return ++hl;
	else return ++hr;
}

int main()
{
	BSTree tree;	
	int ch,x;
	do {
		CLR;
		cout<<"\nWelcome to Binary search tree Program....\n\n  MAIN MENU\n ___________\n\n1. Insert\n2. Delete\n3. Size\n4. Height\n5. PreOrder\n6. InOrder\n7. PostOrder\n8. isEmpty\n9. Exit\n\nYour Tree: ";
		tree.traverse();
		cout<<"\n\nYour choice: ";
		cin>>ch;
		switch(ch) {
			case 1:{
				cout<<"\nInsert value: ";cin>>x;
				tree.insert(x);
				break;
			}			
			case 2:{				
				if(tree.empty()) cout<<"\nTree is Empty!!";
				else {					
					cout<<"\nEnter value to delete: "; cin>>x;
					tree.del(x);
				}								
				break;
			}
			case 3:{
				cout<<"\nSize of your BST is: "<<tree.size();
				getch();
				break;
			}
			case 4:{
				cout<<"\nHeight of your BST is: "<<tree.height(); 									
				getch();
				break;
			}
			case 5:{
				cout<<"\nPreOrder Traversal: ";
				tree.preOrder(BSTree::showData);				
				getch();
				break;
			}				
			case 6:{
				cout<<"\nInOrder Traversal: ";
				tree.inOrder(BSTree::showData);				
				getch();
				break;
			}
			case 7:{
				cout<<"\nPostOrder Traversal: ";
				tree.postOrder(BSTree::showData);				
				getch();
				break;
			}
			case 8:{
				if(tree.empty()) cout<<"\nTree is Empty!!";	
				else cout<<"\nTree is NOT Empty!!";
				getch();	
				break;
			}			
			case 9: break;	
			default: cerr<<"\nInvalid Choice!!!\n";getch();
		}
	}while(ch!=9);
	
	return 0;
}

