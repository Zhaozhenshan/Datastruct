#include<iostream>
using namespace std;
typedef int DataType;
typedef struct Node
{//队列结点
    DataType data;
    struct Node *next;
}Node;
//由于队列的入队出队的操作比较浪费顺序表的空间，所以这里采用单链表来模拟队列
typedef struct 
{//队列，有两个指针，分别是队头和队尾，队尾入队，队头出队
     Node *front;
     Node *rear;
}Queue;
void InitQueue(Queue &Q)
{//队列的初始化
  Q.front=Q.rear=(Node*)malloc(sizeof(Node));
  Q.front->next=NULL;   
}
bool IsEmpty(Queue T)
{
  if(T.front==T.rear) return true;
  else return false;
}
void EnQueue(Queue &Q,DataType e)
{//入队操作
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

void DeQueue(Queue &Q,DataType &e)
{//需要头结点，不然头结点都删除了没办法判空
  if(Q.rear==Q.front) return ;
  Node *p=Q.front->next;
  e=p->data;
  Q.front->next=p->next;
  if(Q.rear==p) Q.rear=Q.front;//这一步很重要，当只有一个结点时尾指针指向头指针
}
int main()
{
  Queue Q;
  InitQueue(Q);
  int e;
  for(int i=0;i<10;i++) EnQueue(Q,i+1);
  while(!IsEmpty(Q))
  {
    DeQueue(Q,e);
    cout<<e<<" ";
  }
}