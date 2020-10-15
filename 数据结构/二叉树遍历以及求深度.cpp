#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef int DataType;
typedef struct Binode
{//二叉树节点
    DataType data;
    struct Binode *lchild,*rchild;
}Binode,*Bitree;
void InitBitree(Bitree &T)
{//初始化二叉树
    T = (Bitree)malloc(sizeof(Binode));
    T->data=-1;
    T->lchild=NULL;
    T->rchild=NULL;
}
void CreateBitree(Bitree &T)
{//构建一颗简单的二叉树，方便检查下列函数是否正确
  T->data=1;
                                                          //              1
  Binode *p2 = new Binode;                                //         2         3	
  p2->data=2;                                             //      4     5 	
                                                          //          7   8
  Binode *p3 = new Binode;
  p3->data = 3;
  p3->lchild=NULL;
  p3->rchild=NULL;
  T->rchild=p3;

  Binode *p4 = new Binode;
  p4->data=4;
  p4->lchild=NULL;
  p4->rchild=NULL;
  
  Binode *p5 = new Binode;
  p5->data=5;
  
  p2->lchild=p4;
  p2->rchild=p5;
  T->lchild=p2;
  
  Binode *p7 = new Binode;
  p7->data=7;
  p7->lchild=NULL;
  p7->rchild=NULL;
  
  Binode *p8 = new Binode;
  p8->data=8;
  p8->lchild=NULL;
  p8->rchild=NULL;
  
  p5->lchild=p7;
  p5->rchild=p8;
}
void PreOrder1(Bitree t)
{//先序遍历二叉树
   if(t!=NULL)
   {
       cout<<t->data;
       PreOrder1(t->lchild);//遍历左子树
       PreOrder1(t->rchild);//遍历右子树
   }
}
void PreOrder2(Bitree t)
{//先序遍历的非递归操作
   if(t==NULL) return ;
   stack<Bitree> S;
   Bitree p = t;
   while(p || !S.empty())
   {
      if(p)
      {
          cout<<p->data;
          S.push(p);
          p=p->lchild;
      }
      else
      {
         p=S.top();
         S.pop();
         p=p->rchild;
      }
   }
}
void InOrder1(Bitree t)
{//中序遍历二叉树
   if(t!=NULL)
   {
       InOrder1(t->lchild);
       cout<<t->data;
       InOrder1(t->rchild);
   }
}
void InOrder2(Bitree t)
{//中序遍历的非递归操作
   if(t==NULL) return ;
   stack<Bitree> S;
   Bitree p = t;
   while(p || !S.empty())
   {
      if(p)
      {
          //cout<<p->data;
          S.push(p);
          p=p->lchild;
      }
      else
      {
         p=S.top();
         cout<<p->data;
         S.pop();
         p=p->rchild;
      }
   }
}
void PostOrder1(Bitree t)
{//后序遍历二叉树
    if(t!=NULL)
    {
        PostOrder1(t->lchild);
        PostOrder1(t->rchild);
        cout<<t->data;
    }
}
void PostOrder2(Bitree t)
{//非递归后序遍历二叉树
    if(t!=NULL)
    {
        stack<Bitree> S;
        Bitree p=t,r=NULL;
        while(p || !S.empty())
        {
            if(p)
            {
                S.push(p);
                p=p->lchild;
            }
            else
            {
                p=S.top();
                if(p->rchild!=NULL && p->rchild!=r)
                {//右子树不空而且右子树没被遍历过
                   p=p->rchild;
                   S.push(p);
                   p=p->lchild;
                }
                else
                {
                    cout<<p->data;
                    S.pop();
                    r=p;
                    p=NULL;
                }
                
            }
            
        }
    }

}
int LevelOrder(Bitree t)
{ //层次遍历二叉树 给他来一个返回值返回树的高度
   if(t==NULL) return 0;

   int front=-1,rear=-1,level=0,last=0;

   queue<Bitree> q;
   q.push(t);rear++;
   while(!q.empty())
   {//当队列不为空的时候
      Bitree p=q.front();   front++;
      cout<<p->data;
      if(p->lchild!=NULL) 
      {
         q.push(p->lchild);
         rear++;
      }
      if(p->rchild!=NULL) 
      {
          q.push(p->rchild);
          rear++;      
      }
      q.pop();
      if(front==last)
      {
          last=rear;
          level++;
      }
   }
   return level;
}
int GetHeight(Bitree t)
{//递归求树的高度
    if(t==NULL) return 0;
    else if(t->lchild==NULL && t->rchild==NULL) return 1;
    else
    {
        int left=GetHeight(t->lchild)+1;
        int right=GetHeight(t->rchild)+1;
        return left > right ? left : right;
    }
}
int main()
{
    Bitree t;
    InitBitree(t);
    CreateBitree(t);
    cout<<"先序遍历的结果是:";
    PreOrder1(t);cout<<endl;
    cout<<"中序遍历的结果是:";
    InOrder1(t);cout<<endl;
    cout<<"后序遍历的结果是:";
    PostOrder1(t);cout<<endl;
    cout<<"层次遍历的结果是:";
    int level=LevelOrder(t);cout<<endl;
    cout<<"二叉树的高度是:"<<GetHeight(t)<<endl;
    cout<<"二叉树的高度是:"<<level<<endl;
    cout<<"先序遍历的结果是:";
    PreOrder2(t);cout<<endl;
    cout<<"中序遍历的结果是:";
    InOrder2(t);cout<<endl;
    cout<<"后序遍历的结果是:";
    PostOrder2(t);cout<<endl;
}