/* filename: AVLTree.cpp
 *
 * Author:   xblin
 */

#include <iostream>

using namespace std;

#define Error 1
#define OK 0

typedef int ElemType;
typedef char Status;

typedef struct{
	ElemType Key;
	ElemType Value;
}Data;

typedef struct AVLTreeNode{
	int height;
	Data data;
	struct AVLTreeNode *left;
	struct AVLTreeNode *right;
}AVLNode, *AVLTree;