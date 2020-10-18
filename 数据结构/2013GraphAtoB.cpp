#include<iostream>
#include<stack>
using namespace std;
#define MaxNum 100
int cost[100];
int path[100];
int visited[100];
struct ArcNode
{
    int adj;
    struct ArcNode *next;
};
typedef struct VNode
{
    //int data
    struct ArcNode *first;
}VNode,VNodeList[MaxNum];
struct Graph
{
    VNodeList vextices;
    int vernum;
};
int Prim(Graph &G,int v0,int v1)
{
   //初始化visited cost path
   for(int i=0;i<G.vernum;i++)
   {
        visited[i]=0;
        cost[i]=INT_MAX;
        path[i]=0;
   }
   //处理v0
   visited[v0]=1;
   for(ArcNode *p = G.vextices[v0].first;p!=NULL;p=p->next)
    if(!visited[p->adj])
      cost[p->adj]=0;
   
   //循环一共进行n-1次，挑选出n-1个顶点 n-1条边
   for(int k=0;k<G.vernum-1;k++)
   {
       //第一步：去找cost[j]=0的任意一个顶点
       int j;
       for(j=0;j<G.vernum;j++)
        if(!visited[j] && cost[j]==0) break;
       visited[j]=1; 
       
       //第二步：修改visited[j]=1并且修改与j相邻的所有顶点
       for(ArcNode *p=G.vextices[j].first;p!=NULL;p=p->next)
        if(!visited[p->adj])
        {
            path[p->adj]=j;
            cost[p->adj]=0;
        } 
   }
   cout<<"从"<<v0<<"到"<<v1<<"的路径为:"<<endl;
   stack<int> s;
   s.push(v1);
   while(path[v1]!=0)
   {
       s.push(path[v1]);
       v1=path[v1];
   }
   s.push(v0);
   while(!s.empty())
   {
       int x=s.top();
       s.pop();
       cout<<x;
       if(!s.empty())
           cout<<"->";
   }
   return 0;
}
void Print(Graph G)
{
    for(int i=0;i<G.vernum;i++)
    {
        for(ArcNode *p=G.vextices[i].first;p!=NULL;p=p->next)
         cout<<i<<"->"<<p->adj<<"  ";
        cout<<endl;
    } 
}
void addArcNode(Graph &G,int x,int y)
{
    ArcNode *newnode = new ArcNode;
    newnode->adj=y;
    newnode->next=G.vextices[x].first;
    G.vextices[x].first=newnode;
}
void InitGraph(Graph &G,int vernums)
{
    for(int i=0;i<vernums;i++)
      G.vextices[i].first=NULL;
    G.vernum=vernums;
}
void CreateGraph(Graph &G)
{
    int arcs[][2]={
        {0  ,1},
        {0  ,2},
        {0  ,5},
        {2  ,3},
        {3  ,4}
    };
    InitGraph(G,6);
    for(int i=0;i<sizeof(arcs)/sizeof(*arcs);i++)
    {
      addArcNode(G,arcs[i][0],arcs[i][1]);
      addArcNode(G,arcs[i][1],arcs[i][0]);
    }
}
int main()
{
    Graph G;
    CreateGraph(G);
    Prim(G,0,4);
}
