/* filename: BSTree.cpp
 *
 * Author:   xblin
 */

#include "BSTree.h"

/* 二叉树递归查找key, 返回BSNode */
BSTree SearchBST(BSTree Tree, int e){
	if (Tree == NULL || Tree->data.key == e)
		return Tree;

	if (e < Tree->data.key)
		return SearchBST(Tree->left, e);
	
	else
		return SearchBST(Tree->right, e);
}

/* 中序遍历输出二叉搜索树 */
void InorderBST(BSTree Tree){
	if (Tree != NULL){
		InorderBST(Tree->left);
		cout << Tree->data.key << endl;
		InorderBST(Tree->right);
	}
}

/* 二叉搜索树插入 */
Status InsertBST(BSTree &Tree, ElemType Key){
	BSTree pNode = Tree;
	BSTree tmpNode = NULL;  //存放Insert的父结点 

	BSTree sNode = (BSTree)malloc(sizeof(BSNode));
	//BSTree sNode = NULL;   //malloc和NULL的区别
	sNode->data.key = Key;
	sNode->left = NULL;    //需初始化NULL
	sNode->right = NULL;
	sNode->parent = NULL;

	if (Tree == NULL){
		Tree = sNode;
		return OK;
	} 

	while (pNode != NULL){   
		tmpNode = pNode;   //记录pNode=NULL 的父结点
		if (Key < pNode->data.key)
			pNode = pNode->left;    
			
		else
			pNode = pNode->right;
	}
	
	sNode->parent = tmpNode;
	if (sNode->data.key < tmpNode->data.key)
		tmpNode->left = sNode;
	else
		tmpNode->right = sNode;

	return OK;
}

/* 二叉搜索树删除 三种情况 */
Status DeleteBST(BSTree &Tree, ElemType key){

	//BSTree sNode = (BSTree)malloc(sizeof(BSNode));
	//sNode->data.key = key;
 	BSTree sNode = SearchBST(Tree, key); //查找结点
	
	if (sNode->left == NULL){
		if (sNode->parent == NULL)
			Tree = sNode->right;
		else if (sNode == sNode->parent->left){

			cout << "dfa" << endl;
			sNode->parent->left = sNode->right;
		}
		else
			sNode->parent->right = sNode->right;
		
		if (sNode->right != NULL)  //防止内存泄漏
			sNode->right->parent = sNode->parent; 
	} 
	if (sNode->right == NULL){
		if (sNode->parent == NULL)
			Tree = sNode->left;
		else if (sNode == sNode->parent->left)
			sNode->parent->left = sNode->left;
		else
			sNode->parent->right = sNode->left;

		if (sNode->left != NULL)   //防止内存泄漏
			sNode->left->parent = sNode->parent;
	} 

	else{   //左右孩子都不为空

		BSTree pNode = sNode->right;

		while (pNode->left != NULL){
			pNode = pNode->left;   //找sNode的后继元素
		}
		if (pNode->right == NULL){
			pNode->parent->left = NULL; //先断左子树
			pNode->parent = sNode->parent;
			pNode->right = sNode->right;
		}
		else {
			if (pNode->parent != sNode){
				pNode->right->parent = pNode->parent;
				pNode->parent->left = pNode->right;
			}
			
			if (sNode == sNode->parent->left)
				sNode->parent->left = pNode;
			else
				sNode->parent->right = pNode;
			pNode->left = sNode->left;
			pNode->right = sNode->right;
		}
		
	}
	free(sNode);  //释放内存

	return OK;
}
/*
int main(int argv, char **argc){
	BSTree Tree = NULL;
	InsertBST(Tree, 6);
	InsertBST(Tree, 2);
	InsertBST(Tree, 1);
	InsertBST(Tree, 5);
	InsertBST(Tree, 3);
	InsertBST(Tree, 4);
	InorderBST(Tree);
	cout << "endl" << endl;
	DeleteBST(Tree, 2);  //有问题
	InorderBST(Tree);
//	BSTree aa = SearchBST(Tree, 6);
}
*/