#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <conio.h>
#define CLR (system("cls"))
#define sstream stringstream

using namespace std;

//basic element of a binary tree.. u can say its root

struct btnode
{
	char data;
	btnode *left,*right;
	
	btnode(const char& element=0, btnode* leftChild=NULL, btnode* rightChild=NULL)
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
		
		static void dispose(btnode* t){delete t;}
		static void (*visit)(btnode*);  // a function ptr, basically a task to do while traversing a tree		
		static void pre_Order(btnode*);
		static void in_Order(btnode*);
		static void post_Order(btnode*);						
		int height(btnode*);
		int op(char);
		string intopostfix(string);		
		void constructTree(string);	
			
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
		void insert(string);					
};
//instantiate func ptr visit:
void (*BSTree::visit)(btnode*) = BSTree::showData;

//function defn:
int BSTree::op(char a)
{
	switch(a) {
		case'+':{
			return 1;
			break;
		}
		case'-':{
			return 1;
			break;
		}
		case'*':{
			return 2;
			break;
		}
		case'/':{
			return 2;
			break;
		}
		default: return 0;
	}
}
string BSTree::intopostfix(string q)
{
	string sp;
	sstream ss;			
	stack<char> p; //char				
	
	for(int i=0;i<q.size();i++) {
		if(isalnum(q[i])) ss<<q[i];
		else {
			switch(q[i]) {
				case '(':{
					p.push(q[i]);
					break;
				}
				case ')':{					
					while(p.top()!='(') {						
						ss<<p.top();
						p.pop();
					}
					p.pop();
					break;
				}				
				default:{
					if( p.empty() || p.top()=='(' || op(p.top()) < op(q[i]) ) p.push(q[i]);						
						else {
							ss<<p.top();
							p.pop();
							p.push(q[i]);
						}
					
				}				
			}
		}
	}
	while(!p.empty())
	{												
		ss<<p.top();
		p.pop();
	}
	
	
	getline(ss,sp);
	return sp;
}

void BSTree::constructTree(string postfix)
{
    stack<btnode *> st;
    btnode *t, *t1, *t2;
   
    // Traverse through every character of
    // input expression
    for (int i=0; i<postfix.size(); i++,treeSize++)
    {
	       // If operand, simply push into stack
	       if (isalnum(postfix[i]))
	       {
	           t = new btnode(postfix[i]);
	           st.push(t);
	       }
	       else // operator
	       {
	           // Pop two top nodes
	           t1 = st.top(); // Store top
	           st.pop();      // Remove top
	           t2 = st.top();
	           st.pop();
	
	           //  make them children
	            t = new btnode(postfix[i],t2,t1);
	
	           // Add this subexpression to stack
	           st.push(t);
	       }
	}
		 
	//  only element will be root of expression
	// tree
	t = st.top();
	st.pop();
			 
	root = t;
}
	
void BSTree::insert(string q)
{
	constructTree(intopostfix(q));
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
	int ch;
	char x;
	do {
		CLR;
		cout<<"\nWelcome to BST Expressions Program....\n\n  MAIN MENU\n ___________\n\n1. Insert\n2. isEmpty\n3. Size\n4. Height\n5. PreOrder\n6. InOrder\n7. PostOrder\n8. Exit\n\nYour Tree: ";
		tree.traverse();
		cout<<"\n\nYour choice: ";
		cin>>ch;
		switch(ch) {
			case 1:{
				string q;
				cout<<"\nEnter Expression: ";cin>>q;
				tree.insert(q);				
				break;
			}			
			case 2:{				
				if(tree.empty()) cout<<"\nTree is Empty!!";	
				else cout<<"\nTree is NOT Empty!!";
				getch();	
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
			case 8: break;	
			default: cerr<<"\nInvalid Choice!!!\n";getch();
		}
	}while(ch!=8);
	
	return 0;
}

/*queue<char> oprn;
	stackarr p(100);
	
	for(int i=0;i<q.size();i++) {
		if(isalnum(q[i])) {
			oprn.push(q[i]);
		}
		else {			
			if( p.empty() ) p.push(q[i]);
			else if( op(p.topelem()) < op(q[i]) ) p.push(q[i]);
			else {
				
				if(root==NULL) {
					root = new btnode;
					root->data=p.topelem();
					root->left=new btnode; root->left->data=oprn.front(); oprn.pop();
					root->right=new btnode; root->right->data=oprn.front(); oprn.pop();
				}
				else {
					btnode* tmp = new btnode;
					tmp->data = p.topelem();
					tmp->left = root;
					root->right=new btnode; root->right->data=oprn.front(); oprn.pop();
				}
				
				p.pop();
				p.push(q[i]);
			}
						
		}
	}
	while(!p.empty())
	{												
		if(root==NULL) {
			root = new btnode;
			root->data=p.topelem();
			root->left=new btnode; root->left->data=oprn.front(); oprn.pop();
			root->right=new btnode; root->right->data=oprn.front(); oprn.pop();
		}
		else {
			btnode* tmp = new btnode;
			tmp->data = p.topelem();
			tmp->left = root;
			root->right=new btnode; root->right->data=oprn.front(); oprn.pop();
		}
		p.pop();
	}
	
	/*for(int i=0;i<q.size();i++) {
		if(isalnum(q[i])) {
			oprn.push(q[i]);
		}
		else {
			switch(q[i]) {
				case '(':{
					p.push(q[i]);
					break;
				}
				case ')':{					
					while(p.topelem()!='(') {
											
						if(root!=NULL) {
							btnode* tmp = new btnode;
							tmp->data=p.topelem();
							tmp->left=root;
							root=tmp;
						}
						else {							
							
						}
						
						p.pop();
					}
					p.pop();
					break;
				}				
				default:{
					if( p.empty() || p.topelem()=='(' ) p.push(q[i]);
					else if(p.topelem()!='('){
						if( op(p.topelem()) < op(q[i]) ) p.push(q[i]);
						else {
							cout<<p.topelem();
							p.pop();
							p.push(q[i]);
						}
					}
				}				
			}
		}
	}
	while(!p.empty())
	{												
		cout<<p.topelem();
		p.pop();
	}*/
