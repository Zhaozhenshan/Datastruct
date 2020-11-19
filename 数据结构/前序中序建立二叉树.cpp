#include <iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
BiTree CreateBiTree(char *pre, char *mid, int n)
{
    if (n <= 0)
        return NULL;
    //三个参数分别是前序序列  中序序列  中序序列向前走的位数
    BiTree T = new BiNode;
    T->data = *pre;
    //确定根在中序中的位置
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (mid[i] == *pre)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return NULL;

    T->lchild = CreateBiTree(pre + 1, mid, pos);
    T->rchild = CreateBiTree(pre + 1 + pos, mid + 1 + pos, n - 1 - pos);
    return T;
}
void Print(BiTree &T)
{
    if (T == NULL)
        return;
    Print(T->lchild);
    Print(T->rchild);
    cout << T->data << " ";
}
int main()
{
    char pre[5] = {'A', 'B', 'C', 'D', 'E'};
    char mid[5] = {'B', 'A', 'D', 'C', 'E'};
    BiTree T;
    T = CreateBiTree(pre, mid, 5);
    cout << "后序遍历序列是:" << endl;
    Print(T);
}