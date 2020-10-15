#include<iostream>
#include<stack>
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
    int arc[5][5]={
        {0  ,10 ,999 , 999 ,5},
        {999,0  ,1   , 999 ,2},
        {999,999,0   , 4   ,999},
        {7  ,999,6   , 0   ,999},
        {999,3,  9   , 2   ,0}
    };
    for(int i=0;i<5;i++)
     for(int j=0;j<5;j++)
      G.arcs[i][j]=arc[i][j];
    G.arcnum=5;   
}

//Dijkstra求单元最短路径的算法
void Dijkstra(Graph &G)
{   
    int n=G.arcnum;
    int dist[n]; //dist[i]表示V0到i的最短路径长度
    int path[n]; //path[i]表示v0到i的最短路径长度的前一个结点序号
    int S[n]={0};//S[i]=1;表示该点已经加入最短路径
    S[0]=1;

    //第一步：把dist[i]初始化为G.arcs[0][i],path[i]初始化为0
    for(int i=0;i<n;i++)
    {
     dist[i]=G.arcs[0][i];
     path[i]=0;
    }
    //循环执行n-1次，每次加入一个结点，一条边
    for(int count=0;count<n-1;count++)
    {
       //第二步：去找dist[j]为dist[i]的最小值
       int j=0;
       while(S[j]) j++;

       for(int i=0;i<n;i++)
        if(!S[i] && dist[i]<dist[j]) j=i;


       //第三步，把j加入集合S,并且修改Vo到其他结点的最短路径dist[i]
       S[j]=1;
       for(int k=0;k<n;k++)
       {
           if(!S[k] && (dist[k]> ( dist[j] + G.arcs[j][k]) ) )
           {
               dist[k]=dist[j]+G.arcs[j][k];
               //第四步：修改path[k]
               path[k]=j;
           }
       }
    }

    //根据path来输出v0到其他结点的最短路径
    for(int i=0;i<n;i++)
    {
       int length=0;
       stack<int> s;
       s.push(i);
       int p=path[i];
       while(true)
       {
          if(p==0)
          {
              s.push(p);
              break;
          }
          s.push(p);
          p=path[p];
       }
       while(!s.empty())
       {
           int x=s.top();
           cout<<s.top()<<" ";
           s.pop();
           if(!s.empty())
           {
            int y=s.top();
            length+=G.arcs[x][y];
           }
       }
       cout<<"该条路径的长度是:"<<length<<endl;
    }
}
int main()
{
    Graph G;
    CreateGraph(G);
    Dijkstra(G);
}