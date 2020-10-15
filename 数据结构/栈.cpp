#include<iostream>
using namespace std;
typedef int DataType;
typedef struct SNode
{
  DataType data;
  SNode *next;
}SNode,*Stack;
void InitStack(Stack S)
{//栈的初始化
    S->data=0;
    S->next=NULL;
}
bool IsEmpty(Stack S)
{//栈的判空
  if(S->next==NULL) return true;
  else return false;
}
void Push(Stack &S,DataType e)
{//入栈
  SNode *p = (Stack)malloc(sizeof(SNode));
  p->data=e;
  p->next=S->next;
  S->next=p;
}
bool Pop(Stack &S,DataType &e)
{//出栈
    if(IsEmpty(S)) return false;
    SNode *p=S->next;
    e=p->data;
    S->next=p->next;
    return true;
}
DataType Top(Stack S)
{//返回栈顶元素
   if(S->next==NULL) return -1;
   return S->next->data;
}
int main()
{
    //这里是使用链表来存储的栈，栈可以使用链表，也可以使用数组模拟，一般在算法中直接使用数组即可。
    // Stack S;
    // InitStack(S);
    // for(int i=0;i<10;i++)
    // Push(S,i);
    // while(!IsEmpty(S))
    // {
    //     cout<<Top(S)<<" ";
    //     int e;
    //     Pop(S,e); 
    // }
    //这里是使用数组来模拟的栈，一般来说直接使用数组即可，更加方便，不过他有一个最大的容量
    int a[100];
    int top=-1;
    for(int i=0;i<10;i++) 
     a[++top]=i;
    while(top!=-1)
    {
        cout<<a[top--]<<" ";
    }
}