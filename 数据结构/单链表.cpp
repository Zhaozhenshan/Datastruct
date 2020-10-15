/*
InitList(&L)          初始化
Length(L)             求长度
LocateElem(L,e)       按值查找，返回具有给定关键值的下标
ListInsert(&L,i,e)    在第i个位置上插入制定元素e
ListDelete(&L,i,&e)   删除第i个位置上的元素并返回给e
PrintList(L)          打印顺序表
Empty(L)              判空操作
DestoryList(&L)       删除操作 释放空间
采用SqList MAXSIZE DataType
*/
#include<iostream>
using namespace std;
typedef int DataType;
typedef struct LNode//单链表的结点
{
    DataType data;
    struct LNode *next;
}LNode,*LinkList;
void InitLinkList(LinkList &L)//初始化头指针
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
LinkList Rail(LinkList L)//获得链表的尾指针
{
    if(L->next==NULL ) return L;
    LinkList p=L;
    while(p->next!=NULL)
     p=p->next;
    return p;
}
LinkList GetElem(LinkList L,DataType e)//根据e返回结点，如果表为空或者表中没有则返回NULL
{
    if(L->next==NULL)  return NULL;
    LinkList p = L->next;
    while(p)
    {
        if(p->data==e) return p;
        p=p->next;
    }
    return NULL;
}
int GetLength(LinkList L)//获得链表的长度
{
    if(L->next==NULL) return 0;
    int i=0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p=p->next;
    } 
    return i;
}
LinkList GetItemAt(LinkList L,int pos)//根据索引返回结点下标从0开始
{
    int length=GetLength(L);
    if(pos>=length || pos<0 ) return NULL;
    LinkList p = L;
    for(int i=0;i<=pos;i++)
        p=p->next;
    return p;
}
void HeadInsert(LinkList &L,DataType e)//采用头插法插入新结点
{
     LNode *p=(LinkList)malloc(sizeof(LNode));
     p->data=e;
     p->next=L->next;
     L->next=p;
}
void RailInsert(LinkList &L,DataType e)//采用尾插法插入新结点
{
    LNode *p=(LinkList)malloc(sizeof(LNode));
    p->data=e;
    p->next=NULL;
    LNode *rail=Rail(L);
    rail->next=p;
}
void PrintList(LinkList list)//打印链表
{
    if(list->next==NULL) return ;
    LinkList p =list->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void RemoveList(LinkList &L)//清空表
{
    LinkList p = L->next;
    while(p)
    {
        LinkList q=p;
        p=p->next;
        q->next=NULL;
        free(q);
    }
    L->next=NULL;
}
int main()
{
    LinkList L;
    InitLinkList(L);
    for(int i = 0 ;i<10;i++)
     RailInsert(L,i*i);
    cout<<GetLength(L);
}