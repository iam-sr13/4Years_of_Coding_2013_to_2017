#ifndef _BINARY_TREE_
#define _BINARY_TREE_

template<class Type>
class BinaryTree
{
	public:
		virtual ~BinaryTree() {}
		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual void preOrder(void (*) (Type*)) = 0;
		virtual void inOrder(void (*) (Type*)) = 0;
		virtual void postOrder(void (*) (Type*)) = 0;
		virtual void levelOrder(void (*) (Type*)) = 0;
};

#endif
