
About
Developers
Updates
searchcode server

Search Expression
 search
× Search your own private repositories? Check out the latest downloadable searchcode server release published under fair source. Download Now
  2-3-tree /twoThreeTree.h

Like searchcode? Run searchcode server locally and index your own code
 Language	C/C++ Header	 Lines	50
 MD5 Hash	f7d29148238e21f29fd09d47b1f8a760	 Estimated Cost	$800 (why?)
 Repository	https://github.com/StoneBird/2-3-tree.git	 View Raw File	
 View File Tree
 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
/*
 File name:     twoThreeTree.h
 Name:          Tongbo Sui
 Description:   Class definition of the 2-3 tree structure and its methods.
*/

#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H
#include<iostream>
#include<assert.h>

using namespace std;

// 2-3 tree node (complete)
template <class elemType>
struct nodeType {
   elemType dataLeft;             // data item on "left" side of node
   elemType dataRight;            // data item on "right" side of node
   short numData;                 // number of data items (1 or 2)
   nodeType<elemType> *left;      // pointer to left subtree
   nodeType<elemType> *middle;    // pointer to middle subtree
   nodeType<elemType> *right;     // pointer to right subtree
   nodeType<elemType> *parent;    // pointer to parent (may not need)
};

// 2-3 tree class (start)
template <class elemType>
class twoThreeTree {
   nodeType<elemType> *root;
   void doInorder (nodeType<elemType> *) const;

   // add in other methods here, if needed
   void auxilary(nodeType<elemType> *, const elemType);  //recursive helper for insertion
   elemType* promote(const elemType, const elemType, const elemType);   //sort the three elements passed in
   nodeType<elemType>* splitNode(nodeType<elemType>*, nodeType<elemType>*, const int); //split node
   void insertSecondItem(nodeType<elemType>*, const elemType); //insert a new item to a 2-node
   bool isLeaf(nodeType<elemType>*) const;   //check if the node is leaf
   int posChild(const nodeType<elemType>*, const nodeType<elemType>*) const;  //check if a node is parent's left, middle, or right child
   void printNode(nodeType<elemType>*) const;   //print a node's value(s)
   nodeType<elemType>* instantiate(const elemType); //create a new node, initialize all crucial values

public:
   twoThreeTree () {root = NULL;};              // constructor
   void insert (const elemType);                // insert an item
   void inorder () const {doInorder (root);     // inorder traversal
                          cout << endl;};
   void display () const;                       // display the tree
};
#endif
Back to Top
About Developers Updates SPDX Search searchcode server
Subscribe to the searchcode newsletter


Your email...
  Subscribe

searchcode is proudly Made in Sydney | © searchcode 2016
