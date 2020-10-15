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
#define MAXSIZE 64
typedef struct Node
{//定义顺序表
     DataType elem[MAXSIZE];
     int length;
}SqList;

void InitList(SqList &L)
{//初始化顺序表
    L.length=0;
}

bool ListInsert(SqList &L,int pos,DataType e)
{//在第pos个位置上插入一个元素下表从0开始
     if(L.length==MAXSIZE) return false;
     for(int i=L.length;i>pos;i++)
      L.elem[i]=L.elem[i-1];

     L.elem[pos]=e;
     L.length++; 
     return true;
}
int LocateElem(SqList L,DataType e)
{//根据其值定位下标
    if(L.length==0 ) return -1;
    for(int i =0;i<L.length;i++)
    {
        if(e==L.elem[i])
        {
            return i;
        }
    }
    return -1;
}
bool ListDelete(SqList &L,int pos,DataType &e)
{//删除pos位置上的数据并且把数据返回给e
      if(pos>=L.length) return false;
      e=L.elem[pos];
      for(int i=pos;i<L.length-1;i++)
       L.elem[i]=L.elem[i+1];
      L.length--;
      return true;
}
bool PrintList(SqList L)
{//打印顺序表
    if(L.length==0) return false;
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
    return true;
}
int main()
{
    SqList list;
    InitList(list);
    for(int i = 0;i<10;i++)
     ListInsert(list,i,i*i);
    cout<<LocateElem(list,36);
}
