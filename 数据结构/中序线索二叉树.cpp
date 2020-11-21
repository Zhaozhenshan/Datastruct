#include <iostream>
using namespace std;
typedef enum
{
    Link,
    Thread
} PointerThr;
typedef struct BiThrNode
{ //线索二叉树的结点
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerThr LTag, RTag;
} BiThrNode, *BiThrTree;
int count = 0;
void InThreading(BiThrTree &p, BiThrTree &pre)
{ //以p为根的非空二叉树的中序线索化
    if (p)
    {
        InThreading(p->lchild, pre);

        if (p->lchild == NULL)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }

        if (pre != NULL && pre->rchild == NULL)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }

        pre = p;
        InThreading(p->rchild, pre);
    } //if
} //InThreading
void CreateBiThrTree(BiThrTree &T)
{ //中序遍历构造二叉线索树
    BiThrTree pre = NULL;
    if (T != NULL)
    {
        InThreading(T, pre);
        pre->rchild = NULL;
        pre->RTag = Thread;
    }
}
void Traverse(BiThrTree &T)
{//中序遍历二叉线索树
    BiThrTree p = T; //p是树的根节点
    while (p != NULL)
    {
        while (p->LTag == Link)
            p = p->lchild;
        cout << p->data << " ";
        while (p->RTag == Thread && p->rchild != NULL)
        {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;
    }
}
BiThrTree Create(BiThrTree &T, char c[])
{//根据先序序列创建二叉树
    if (c[count] == '0' || count >= 11)
    {
        T = NULL;
        count++;
    }
    else
    {
        T = (BiThrTree)malloc(sizeof(BiThrNode));
        T->data = c[count];
        count++;
        T->lchild = Create(T->lchild, c);
        T->rchild = Create(T->rchild, c);
    }
    return T;
}
void InOrder(BiThrTree &T)
{//中序遍历二叉树
    if (T != NULL)
    {
        InOrder(T->lchild);
        cout << T->data << " ";
        InOrder(T->rchild);
    }
    return;
}
int main()
{
    char c[11] = {'a', 'b', 'd', '0', '0', 'e', '0', '0', 'c', '0', '0'};
    BiThrTree T;
    T = Create(T, c);
    InOrder(T);
    CreateBiThrTree(T);
    cout << endl;
    Traverse(T);
}