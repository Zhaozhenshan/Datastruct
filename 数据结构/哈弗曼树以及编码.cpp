#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define max 128
typedef struct Binode
{//哈夫曼树的结点
    int weight;//权重
    struct Binode * lchild,*rchild,*parent;//左孩子右孩子和双亲结点,方便后面求哈夫曼编码
}Binode,*Bitree;
struct HuffMan
{//哈夫曼树
    Bitree nodes[max];//哈夫曼树结点
    int n;//哈夫曼树中的叶结点个数
    int t;//哈夫曼结点的个数
    int index[max];//辅助数组，方便求最小值结点
};
void InitHuffMan(HuffMan &H,int w[] , int n)
{//初始化哈夫曼树
   H.n=n;//叶子结点个数
   H.t=2*n-1;//哈夫曼结点个数
   for(int i=0;i<H.n;i++)
   {
       H.index[i]=1;//代表没有被访问过
       H.nodes[i]=new Binode;
       H.nodes[i]->lchild=H.nodes[i]->rchild=H.nodes[i]->parent=NULL;//初始化左孩子，右孩子，父亲结点
       H.nodes[i]->weight=w[i];//初始化权重
   }
   for(int i=H.n;i<H.t;i++)
   {
       H.index[i]=1;//代表没有被访问过
       H.nodes[i]=new Binode;
       H.nodes[i]->lchild=H.nodes[i]->rchild=H.nodes[i]->parent=NULL;//初始化左孩子，右孩子，父亲结点
       H.nodes[i]->weight=-1;
   } 
}
Bitree FindMin(HuffMan &T,int left,int right)
{   //1次选择排序
    int posmin=left;
    for(int i=left;i<right;i++)
     if(T.nodes[i]->weight < T.nodes[posmin]->weight)
        posmin=i;//找到第一个最小值点
    //交换
    Bitree p = T.nodes[left];
    T.nodes[left]=T.nodes[posmin];
    T.nodes[posmin]=p;
    return T.nodes[left];
}
Bitree CreateHuffman(HuffMan &T)
{//构造哈夫曼树
      int pos = T.n;
      for(int left=0;left<T.t-1;left++)
      {
          Bitree p1 = FindMin(T,left,pos);
          left++;
          Bitree p2 = FindMin(T,left,pos);
          T.nodes[pos]->lchild=p1;
          T.nodes[pos]->rchild=p2;
          p1->parent=T.nodes[pos];
          p2->parent=T.nodes[pos];
          T.nodes[pos]->weight=p1->weight+p2->weight;
          pos++;
      }
      return T.nodes[T.t-1];
}
void HuffmanCode(Bitree t)
{//先序遍历二叉树
   if(t!=NULL)
   {
       if(t->lchild==NULL && t->rchild==NULL){
           stack<int> s;

           Bitree p=t,parent;
           int weight = p->weight;
           while(p->parent!=NULL){
               parent=p->parent;
               if(parent->lchild==p) s.push(0);
               else                  s.push(1);
               p=parent;
           }
           cout<<"权重为:"<<weight<<" 的小可爱拥有的哈夫曼编码为:";
           while(!s.empty())
           {
               cout<<s.top();
               s.pop();
           }
           cout<<endl;
       }
       HuffmanCode(t->lchild);//遍历左子树
       HuffmanCode(t->rchild);//遍历右子树
   }
}
int main()
{
    int w[4]={5,2,4,7};
    HuffMan H;
    InitHuffMan(H,w,4);
    Bitree huffman = CreateHuffman(H);
    HuffmanCode(huffman);
}