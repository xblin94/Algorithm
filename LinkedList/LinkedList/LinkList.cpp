/* filename: LinkList.cpp
 *
 * Author:   xblin
 */

#include "LinkList.h"


/********** 逆向建立单链表 ***************/
void CreateList_L(LinkList &L, int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	
	for (int i = n; i > 0; i--){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
}

/********** 顺序建立单链表 ***************/
void CreateList_Forward(LinkList &L, int n){
	L = (LinkList)malloc(sizeof(LNode));
	LinkList tmp = L;
	
	for (int i = 0; i < n; i++){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = nullptr;
		tmp->next = p;
		tmp = p;
	}
	
}

/********** 单链表的查询i ***************/
Status GenElem_L(LinkList L, int i, ElemType &e){
	for (int j = i; j > 0; j--){
		L = L->next;
	}
	if (!L)
		return ERROR;

	e = L->data;
	return OK;
}


/********** 单链表的插入 ***************/
Status ListInsert_L(LinkList &L, int i, ElemType e){    //引用L，传址

	LinkList p = L;        //头结点L不能移动

	for (int j = i - 1; j > 0; j--)  //查找第i-1个结点
		p = p->next;
	if (!p)
		return ERROR;

	LinkList s = (LinkList)malloc(sizeof(LNode));  //s为要插入的结点
	s->data = e;
	s->next = p->next;         //先后顺序注意
	p->next = s;

	return OK;
}

/********** 单链表的删除 ***************/
Status ListDelete_L(LinkList &L, int i){
	LinkList p = L;

	for (int j = i-1; j > 0; j--)
		p = p->next;
	if (!p)
		return ERROR;

	LinkList q = p->next;  //q是被删除的结点
	p->next = p->next->next;
	free(q);    //释放删除的结点q

	return OK;
}


int main(int argv, char **argc){

	LinkList L;
	CreateList_Forward(L, 9);

	//ListInsert_L(L, 4, 16);
	ListDelete_L(L, 4);

	for (int i = 0; i < 8; i++){    //输出单链表
		L = L->next;
		cout << L->data << endl;
	}
	
//	int e=0;
//	GenElem_L(L, 6, e);   //查询第6个元素
//	cout << e << endl;
}


