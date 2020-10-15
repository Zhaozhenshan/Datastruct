#include<iostream>
using namespace std;
#define Maxsize 10
typedef int DataType;
typedef struct
{//初始化队列
   DataType data[Maxsize];
   int rear=0;//把这个数组想象成一个环
   int front=0;//这里这样定义是为了保留一个空位置
}Queue;
bool IsEmpty(Queue Q)
{//判空
    if(Q.rear==Q.front) return true;
    else return false;
}
bool EnQueue(Queue &Q,DataType e)
{   //入队
    if((Q.rear+1+Maxsize)%Maxsize==Q.front) return false;
    Q.data[Q.rear++]=e;
    return true;
}
bool DeQueue(Queue &Q,DataType &e)
{//出队
    if(IsEmpty(Q)) return false;
    e=Q.data[Q.front++];
    return true;
}
int getNumber(Queue Q)
{//获得链表中元素的个数
    return (Q.rear-Q.front+Maxsize)%Maxsize;
}
int main()
{
    Queue Q;
    for(int i=0;i<10;i++) EnQueue(Q,i+1);
    cout<<getNumber(Q);
    cout<<endl;
    while(!IsEmpty(Q))
    {
        int e;
        DeQueue(Q,e);
        cout<<e<<" ";
    }
}