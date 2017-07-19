#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <conio.h>
#include "c_pos.hpp"
#define CLR (system("cls"))

using namespace std;

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
		static void dispose(btnode* t){delete t;}		//a visit fn
		static void pre_Order(btnode*);
		static void in_Order(btnode*);
		static void post_Order(btnode*);
		static void level_Order(btnode*, bool);	
		
		//AVL methods
		static int height(btnode*);
		static int diff(btnode*);
		btnode* rr_rotation(btnode*);
		btnode* ll_rotation(btnode*);
		btnode* lr_rotation(btnode*);
		btnode* rl_rotation(btnode*);
		btnode* balance(btnode*);
		
		btnode* bal_insert(btnode*) {/*TODO: balance tree and return new root*/}
		btnode* bal_delete(btnode*) {/*TODO: balance tree and return new root*/}
		
		//special
		COORD showTree(btnode*,COORD cd);
		COORD treeEdges(btnode*,COORD cd);
		int level(btnode* t) {if(t==this->root) return 1; else return level(parent(t))+1;} //recursive level fn
		int leaves(btnode* t) {int h=height(t); return pow(2,h-1);}  //leaves for resp node e.g a leaf node will return 1, a height 2 tree returns 2;
		int fnodes(btnode* t) {int h=height(t); return pow(2,h)-1;}  //no. of nodes of full bin tree for resp height;
		int noofedge(btnode*t) {int h=height(t); if(h<=1) return 0; else if(h==3) return 2; else return 2*noofedge(h-1)+1;} //wrt node
		int noofedge(int h) {if(h<=1) return 0; else if(h==3) return 2; else return 2*noofedge(h-1)+1;}		//wrt height
		bool isLeftChild(btnode*t) {/*if (t->data==root->data) return false;*/ if(parent(t)->left == t) return true; else return false;}		
		btnode* parent(btnode* x) {
			if(x == root) return NULL;          //root's parent is obviously dead XD
			btnode* t,*q;                       
			search(x->data,t,q);                //a suspicious way to return parent as var t, but works only for uniq valued tree, for duplicates foll codes are considered
			if(t == NULL) return q;             //if root's data is duplicated, then above search method might return null, so better to return root itself as its duplicates parent
			if(t->left == x || t->right == x) return t;       //if subtree's data is duplicated(see else part) then we have to return correct duplicate's parent else return orignal parent
			else{for(;q->right!=x;q=q->right); return q;}
		}		
					
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
		
		void postOrder(void (*dvisit)(btnode*), btnode* t)        //overloaded for disposal of various nodes
		{BSTree::visit=dvisit; post_Order(t);}
		
		void levelOrder(void (*dvisit) (btnode*), bool lvl_on = false)	
		{BSTree::visit=dvisit; level_Order(root, lvl_on);}			
		
		//bst methods
		bool search(int n, btnode* &parent, btnode* &x) const;		
		void insert(int n);	
		void del(int num);
		
		//xtras
		static void showData(btnode* t) {cout<<t->data<<' ';}  //a visit fn
		static void bf(btnode* t) {cout<<t->data<<" : "<<diff(t)<<endl;}  //a visit fn
					
		void traverse() {inOrder(showData);}		
		void erase() { postOrder(dispose); root=NULL; treeSize=0;}
		int height() {return height(root);}
		int diff(){ return diff(root);}
		
		//special
		void showTree(){cout<<endl<<endl;showTree(root,wherexy());};						
};
//instantiate func ptr visit:
void (*BSTree::visit)(btnode*) = BSTree::showData;

//function defn:
void BSTree::insert(int n)
{
	bool found;
	btnode *t, *parentx, *x;
	
	found=search(n,parentx,x);
	if(found) {
		//cout<<endl<<"Such node already exist!!\n"; getch();
		t=new btnode;
		t->data=n;		
		t->right=x->right;		//code for duplicate values allowed in tree		
		x->right=t;		
		
		treeSize++;
	}
	else {
		t=new btnode;
		t->data=n;
		if(parentx==NULL) BSTree::root=t;
		else {
			n<parentx->data?parentx->left=t : parentx->right=t;
			//if(parent(parentx)!=NULL) balance(parent(parentx));
		}		
		
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

void BSTree::level_Order(btnode* t, bool lvl_on)
{
	//if(lvl_on) cout<<endl;	
	queue<btnode*> q;
	while(t!=NULL)
	{		
		BSTree::visit(t);
		
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);		
		if(q.size()==0){return;}
		
		//if(level(t) < level(q.front()) && lvl_on) cout<<endl;
				
		t=q.front();
		q.pop();		
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

COORD BSTree::showTree(btnode* t,COORD cd)
{		
	if(t!=NULL)
	{
		COORD parentPos=treeEdges(t,cd); --parentPos.X;		
		showTree(t->left,parentPos);
		showTree(t->right,parentPos);		
	}	
	return cd;
}

COORD BSTree::treeEdges(btnode* t,COORD cd)
{
	if(t==root) {
		int end = (leaves(t) + fnodes(t))/2;
		cout<<setcurs(cd.X+end,cd.Y)<<t->data;
		return wherexy();
	}
	else if(isLeftChild(t)) {
		cout<<setcurs(cd);
		int end = noofedge(parent(t));
		for(int i=1; i<=end; i++) {
			cout<<setcurs(cd.X-i,cd.Y+i)<<"/";             //<<setcurs(cX()+pow(2,i) + 1, cY())<<"\\";
		}
		cout<<setcurs(cX()-2,cY()+1)<<t->data;
		return wherexy();
	}
	else {
		cout<<setcurs(cd);
		int end = noofedge(parent(t));
		for(int i=1; i<=end; i++) {
			cout<<setcurs(cd.X+i,cd.Y+i)<<"\\";
		}
		cout<<setcurs(cX(),cY()+1)<<t->data;
		return wherexy();
	}		
	
}

//todo:
/*
 * Right - Right rotation
 */
btnode *BSTree::rr_rotation(btnode *parent)
{
    btnode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
btnode *BSTree::ll_rotation(btnode *parent)
{
    btnode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
/*
 * Left - Right Rotation
 */
btnode *BSTree::lr_rotation(btnode *parent)
{
    btnode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
/*
 * Right- Left Rotation
 */
btnode *BSTree::rl_rotation(btnode *parent)
{
    btnode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
//balfactor
int BSTree::diff(btnode *t)
{
    int l_height = height (t->left);
    int r_height = height (t->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
//balance it
btnode* BSTree::balance(btnode *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
	return temp;    
}

int main()
{
	BSTree tree;	
	int ch,x;
	do {
		CLR;
		cout<<"\nWelcome to Binary search tree Program....\n\n  MAIN MENU\n ___________\n\n1. Insert\n2. Delete\n3. Size\n4. Height\n5. PreOrder\n6. InOrder\n7. PostOrder\n8. BalanceFactor\n9. Search\n10. Exit";
		COORD choicePos=wherexy();
		cout<<"\n\n\n\n\n\n\nYour Tree: ";
		tree.showTree();
		cout<<setcurs(choicePos)<<"\nYour choice: ";
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
				cout<<"\nBalFactors:\n";
				tree.inOrder(BSTree::bf);
				getch();	
				break;
			}
			case 9:{
				btnode *p,*t;
				cout<<"\nEnter value to be searched: "; cin>>x;
				bool found=tree.search(x,p,t);
				if(found) cout<<"\nElement exist in the tree!!";
				else cout<<"\nElement don't exist in tree!!";
				getch();
				break;
			}
			case 10: break;	
			default: cerr<<"\nInvalid Choice!!!\n";getch();
		}
	}while(ch!=10);
	
	return 0;
}

/*
parenttrial
btnode* parent(btnode* x) {
			if(x == root) return NULL;          //root's parent is obviously dead XD
			btnode* t,*q;                       
			search(x->data,t,q);                //a suspicious way to return parent as var t, but works only for uniq valued tree, for duplicates foll codes are considered
			if(t == NULL) return q;             //if root's data is duplicated, then above search method might return null, so better to return root itself as its duplicates parent
			if(t->left == x || t->right == x) return t;       //if subtree's data is duplicated(see else part) then we have to return correct duplicate's parent else return orignal parent
			else{for(;q->right!=x;q=q->right); return q;}
		}
show tree trial
queue<btnode*> q;
	while(t!=NULL)
	{		
		treeEdges(t);
		
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);		
		if(q.size()==0){return;}
		
		if(level(t) < level(q.front())) cout<<endl;
				
		t=q.front();
		q.pop();		
	}
*/

/*
void BSTree::treeEdges(btnode* t)
{
	if(t==root) {
		int end = (leaves(height(t)) + fnodes(height(t)))/2;
		cout<<setcurs(wherexy().X,wherexy().Y+end);
	}
	else if(hasLeftSib(t)) {
		int end = leaves(height(t)) + fnodes(height(t)) + 1;
		for(int i=0; i<end; i++) cout<<' ';
	}
	else {
		int end = 3*height(t)+2;
		for(int i=0; i<end; i++) cout<<' ';
	}
	cout<<t->data;
}

void lbtree::showTree()
{
	lbtree::visit = lbtree::showData;
	btnode *p = root, *t = root;
	queue<btnode*> q;
	
	while(t!=NULL)
	{			
		lbtree::visit(t);
		if(height(t) < height(p)) cout<<endl;
		
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);
		
		try{t=q.front();}
		catch(exception queueEmpty) {return;}		
		q.pop();
		
		try{p=q.front();}
		catch(exception queueEmpty) { p=t;}
	}
}
*/
