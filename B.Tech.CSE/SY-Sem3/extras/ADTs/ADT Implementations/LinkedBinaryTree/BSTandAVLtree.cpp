#include <iostream>
#include <queue>

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

//This is a class defn of linked binary tree

class lbtree 
{
	private:
		btnode* root;
		int treeSize;
		
		static void (*visit)(btnode*);  // a function ptr, basically a task to do while traversing a tree		
		static void pre_Order(btnode* t);
		static void in_Order(btnode* t);
		static void post_Order(btnode* t);
		static void level_Order(btnode* t);
		static void dispose(btnode* t){delete t;}				
		int height(btnode* t);
			
	public:
		lbtree() {root=NULL; treeSize=0;}
		~lbtree() {erase();}
		
		//ADT methods
		bool empty() const {return treeSize==0;}
		int size() const {return treeSize;}		
		
		void preOrder(void (*dvisit)(btnode*))
		{lbtree::visit=dvisit; pre_Order(root);}
		
		void inOrder(void (*dvisit)(btnode*))
		{lbtree::visit=dvisit; in_Order(root);}
		
		void postOrder(void (*dvisit)(btnode*))
		{lbtree::visit=dvisit; post_Order(root);}
		
		void levelOrder(void (*dvisit) (btnode*))	
		{lbtree::visit=dvisit; level_Order(root);}
		
		//xtras
		static void showData(btnode* t) {cout<<t->data<<' ';}		
		void traverse() {inOrder(showData);}		
		void erase() { postOrder(dispose); root=NULL; treeSize=0;}
		int height() {return height(root);}
		
		//bst methods
		bool search(int n, btnode* &parent, btnode* &x) const;		
		void insert(int n);	
		void del(int num);		
		
		//TODO: Unimplemented class functions
		
		void showTree();
		bool compare(lbtree& bst) const;
		lbtree& copy(lbtree& bst);			
};
//instantiate func ptr visit:
void (*lbtree::visit)(btnode*) = lbtree::showData;

//function defn:
void lbtree::insert(int n)
{
	bool found;
	btnode *t, *parent, *x;
	
	found=search(n,parent,x);
	if(found) cout<<endl<<"Such node already exist!!\n";
	else {
		t=new btnode;
		t->data=n;
		if(parent==NULL) lbtree::root=t;
		else n<parent->data?parent->left=t : parent->right=t;
		
		treeSize++;
	}
}


void lbtree::del(int num)
{
	bool found;
	btnode *xsucc, *parent=NULL, *x=NULL;
	
	if(lbtree::root==NULL)
	{
		cout<<"\nTree is empty!!\n"; return;
	}			
	found=search(num,parent,x);
	
	if(!found) {
		cout<<"\nNode to be deleted is not found!!\n"; return;
	}
	
	if(x->left!=NULL && x->right!=NULL)
	{
		cout<<"*case1*\n";
		parent=x;
		xsucc=x->right;
	
		while(xsucc->left!=NULL) {parent=xsucc; xsucc=xsucc->left;}
		x->data=xsucc->data;
		x=xsucc;				
	}
	
	if(x->left==NULL && x->right==NULL)
	{
		cout<<"*case2*\n";
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
		cout<<"*case3*\n";
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
		cout<<"*case4*\n";
		if(parent!=NULL) {
			if(parent->left==x) parent->left=x->left;
			else parent->right=x->left;
		}		
		else root = root->left;
		
		delete x; treeSize--;
		return;
	}
}


bool lbtree::search(int n, btnode* &parent, btnode* &x) const
{
	btnode* q;			
	parent = NULL;			
	if(lbtree::root==NULL) return false;
			
	q=lbtree::root;
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


void lbtree::pre_Order(btnode* t)
{
	if(t!=NULL)
	{
		lbtree::visit(t);
		pre_Order(t->left);
		pre_Order(t->right);
	}
}

void lbtree::in_Order(btnode* t)
{
	if(t!=NULL)
	{
		in_Order(t->left);
		lbtree::visit(t);		
		in_Order(t->right);
	}
}

void lbtree::post_Order(btnode* t)
{
	if(t!=NULL)
	{		
		post_Order(t->left);
		post_Order(t->right);
		lbtree::visit(t);
	}
}

void lbtree::level_Order(btnode* t)
{
	queue<btnode*> q;
	while(t!=NULL)
	{
		lbtree::visit(t);
		
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);
		
		try{t=q.front();}
		catch(exception queueEmpty) {t=NULL;return;}
		q.pop();
	}
}		

int lbtree::height(btnode* t)
{
	if(t==NULL) return 0;
	int hl=height(t->left);
	int hr=height(t->right);
	if(hl>hr) return ++hl;
	else return ++hr;
}

/*void lbtree::showTree()
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

int main()
{
	lbtree tt;
	int i,num;
	
	for(i=0;i<=6;i++) {
		cout<<"\nEnter data: "; cin>>num;
		tt.insert(num);
	}
	
	tt.traverse();
	cout<<"\nSize: "<<tt.size(); 	
	while(tt.size()>0){
		cout<<"\n\nNow enter value of node to delete: "; cin>>num;	
		tt.del(num);
		cout<<endl;
		tt.traverse();
		cout<<"\nSize: "<<tt.size();
	}
	
	return 0;
}
