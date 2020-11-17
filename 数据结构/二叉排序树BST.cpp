#include<iostream>
using namespace std;
typedef struct BiNode
{
    int key;
    struct BiNode *lchild,*rchild;
    //构造函数
    BiNode(int akey)
    {
        key=akey;
        lchild=rchild=NULL;
    }
}BiNode,*BiTree;
int AddNode(BiTree &T,int akey)
{//插入结点
    if(T == NULL)
    {
        T = new BiNode(akey);
        return 0;
    }
    BiTree p=T;
    while(p!=NULL && p->key != akey)
    {
        if(akey <p->key)
        {
            if(p->lchild==NULL)
            {
                p->lchild=new BiNode(akey);
                return 0;
            }
            else
            {
                p=p->lchild;
            }
        }
        else
        {
            if(p->rchild==NULL)
            {
                p->rchild=new BiNode(akey);
                return 0;
            }
            else 
            {
                p=p->rchild;
            }
        }
    }
    return 1;
}
int Print(BiTree &T)
{//中序遍历BST
    if(T==NULL) return 0;
    Print(T->lchild);
    cout<<" "<<T->key<<" ";
    Print(T->rchild);
    return 0;
}
int main()
{
    BiTree T;
    T=NULL;
    int a[10]={5,8,2,1,3,10,9,4,6,7};
    for(int i=0;i<10;i++)
     AddNode(T,a[i]);
    Print(T);
}