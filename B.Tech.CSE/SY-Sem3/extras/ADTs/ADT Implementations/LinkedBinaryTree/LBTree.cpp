#include <iostream>
#include <queue>
#include "binaryTree.hpp"

using namespace std;

//basic element of a binary tree.. u can say its root
template<class T>
struct btnode
{
	T data;
	btnode<T> *left,*right;
	
	btnode(const T& element=NULL, btnode* leftChild=NULL, btnode* rightChild=NULL)
	{
		data=element;
		left=leftChild;
		right=rightChild;
	}
};

//This is a class defn of linked binary tree
template<class E>
class lbtree : public BinaryTree< btnode<E> >
{
	protected:
		btnode<E>* root;
		int treeSize;
		
		static void (*visit)(btnode<E>*);  // a function ptr, basically a task to do while traversing a tree
		static void preOrder(btnode<E>* t);
		static void inOrder(btnode<E>* t);
		static void postOrder(btnode<E>* t);
		static void levelOrder(btnode<E>* t);
		static void dispose(btnode<E>* t){delete t;}				
		int height(btnode<E>* t);
			
	public:
		lbtree() {root=NULL; treeSize=0;}
		~lbtree() {erase();}
		
		//ADT methods
		bool empty() const {return treeSize==0;}
		int size() const {return treeSize;}		
		
		void preOrder(void (*visit)(btnode<E>*))
		{this->visit=visit; preOrder(root);}
		
		void inOrder(void (*visit)(btnode<E>*))
		{this->visit=visit; inOrder(root);}
		
		void postOrder(void (*visit)(btnode<E>*))
		{this->visit=visit; postOrder(root);}
		
		void levelOrder(void (*visit) (btnode<E>*))	
		{this->visit=visit; levelOrder(root);}
		
		//xtras
		void show(btnode<E>* t) const {cout<<t->data;}
		void erase() { postOrder(dispose); root=NULL; treeSize=0;}
		int height() const {return height(root);}			
};

template<class E>
void lbtree<E>::preOrder(btnode<E>* t)
{
	if(t!=NULL)
	{
		visit(t);
		preOrder(t->left);
		preOrder(t->right);
	}
}
template<class E>
void lbtree<E>::inOrder(btnode<E>* t)
{
	if(t!=NULL)
	{
		inOrder(t->left);
		visit(t);		
		inOrder(t->right);
	}
}
template<class E>
void lbtree<E>::postOrder(btnode<E>* t)
{
	if(t!=NULL)
	{		
		postOrder(t->left);
		postOrder(t->right);
		visit(t);
	}
}
template<class E>
void lbtree<E>::levelOrder(btnode<E>* t)
{
	queue<btnode<E>*> q;
	while(t!=NULL)
	{
		visit(t);
		
		if(t->left != NULL) q.push(t->left);
		if(t->right != NULL) q.push(t->right);
		
		try{t=q.front();}
		catch(exception queueEmpty) {return;}
		q.pop();
	}
}		
template<class E>
int lbtree<E>::height(btnode<E>* t)
{
	if(t==NULL) return 0;
	int hl=height(t->left);
	int hr=height(t->right);
	if(hl>hr) return ++hl;
	else return ++hr;
}


int main()
{
	return 0;
}
