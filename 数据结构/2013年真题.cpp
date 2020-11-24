#include <iostream>
using namespace std;
#define MaxNum 100
int path[100];
int visited[100]={0};
bool found = false;
int length=0;
struct ArcNode
{
    int adj;
    struct ArcNode *next;
};
typedef struct VNode
{
    //int data
    struct ArcNode *first;
} VNode, VNodeList[MaxNum];
struct Graph
{
    VNodeList vextices;
    int vernum;
};
void Print(Graph G)
{
    for (int i = 0; i < G.vernum; i++)
    {
        for (ArcNode *p = G.vextices[i].first; p != NULL; p = p->next)
            cout << i << "->" << p->adj << "  ";
        cout << endl;
    }
}
void addArcNode(Graph &G, int x, int y)
{
    ArcNode *newnode = new ArcNode;
    newnode->adj = y;
    newnode->next = G.vextices[x].first;
    G.vextices[x].first = newnode;
}
void InitGraph(Graph &G, int vernums)
{
    for (int i = 0; i < vernums; i++)
        G.vextices[i].first = NULL;
    G.vernum = vernums;
}
void CreateGraph(Graph &G)
{
    int arcs[][2] = {
        {0, 1},
        {0, 2},
        {0, 5},
        {2, 3},
        {3, 4}};
    InitGraph(G, 6);
    for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
    {
        addArcNode(G, arcs[i][0], arcs[i][1]);
        addArcNode(G, arcs[i][1], arcs[i][0]);
    }
}
//基于深度优先遍历的找从s到t的算法
void DFSTravers(Graph &G, int s, int t)
{
   visited[s]=1;
   path[length++]=s;
   for(ArcNode *p=G.vextices[s].first;p!=NULL && !found;p=p->next)
   {
       if(p->adj==t){
           found=true;
           path[length++]=p->adj;

           cout<<"从0到4的简单路径为:"<<endl;
           for(int i=0;i<length;i++)
            cout<<path[i]<<" ";
           return ;
           }
       else if(!visited[p->adj])
        DFSTravers(G,p->adj,t);
   }
   if(!found) length--;
}
int main()
{
    Graph G;
    CreateGraph(G);
    cout<<endl;
    DFSTravers(G,0,4);
}
