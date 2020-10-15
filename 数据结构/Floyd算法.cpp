#include<iostream>
using namespace std;
#define MaxNumber 100
//图的邻接矩阵
struct Graph
{
    int arcs[MaxNumber][MaxNumber];//矩阵
    int arcnum;//结点数
};
//创建一个初始的有向带权图
void CreateGraph(Graph &G)
{
    int arc[3][3]={
        {0,6,13},
        {10,0,4},
        {5,999,0},
    };
    for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
      G.arcs[i][j]=arc[i][j];
    G.arcnum=3;   
}
void Floyd(Graph &G)
{
    for(int k=0;k<G.arcnum;k++)
     for(int i=0;i<G.arcnum;i++)
      for(int j=0;j<G.arcnum;j++)
       if(G.arcs[i][j]>G.arcs[i][k]+G.arcs[k][j])
        G.arcs[i][j]=G.arcs[i][k]+G.arcs[k][j];
}
int main()
{
    Graph G;
    CreateGraph(G);
    Floyd(G);
    for(int i=0;i<G.arcnum;i++)
    {
       for(int j=0;j<G.arcnum;j++)
        cout<<G.arcs[i][j]<<"  ";
       cout<<endl;
    }
}