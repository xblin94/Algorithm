/* filename: BSTree.h
 *
 * Author:   xblin
 */

#include <iostream>

using namespace std;

#define Error 1
#define OK 0
typedef int ElemType;
typedef char Status;

/* 存放键值对 */
typedef struct{
	ElemType key;
	ElemType Value;
}Data;


/* 二叉搜索树数据结构 */
typedef struct BSTreeNode{

	Data data;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	struct BSTreeNode *parent;

}BSNode, *BSTree;

BSTree SearchBST(BSTree Tree, ElemType e);
void InorderBST(BSTree Tree);
Status InsertBST(BSTree &Tree, ElemType Key);