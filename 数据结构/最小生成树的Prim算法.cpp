#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#define MaxVertexNum 100 //最多有100个结点
typedef char Vertex;//顶点的数据类型
typedef int Edge;
typedef int info;

//弧结点的定义
struct ArcNode
{
  int vexadj;//该边指向顶点的位置
  struct ArcNode *next;//下一个边的指针
  info weight;//边的权值
};
//顶点结点的定义
typedef struct VNode
{//顶点结点
   Vertex data;//顶点存储的信息比如可以是字符串字符等等
   ArcNode *first;//指向的第一个指针
}AdjList[MaxVertexNum];

//邻接表结构的图的定义
struct ALGraph
{
  AdjList vertices;//顶点数组
  int vernum;//结点个数
};

//邻接表图的初始化
void InitGraph(ALGraph &G,int vexnumber)
{
  for(int i=0;i<vexnumber;i++)
  {
      G.vertices[i].data='a'+i;
      G.vertices[i].first=NULL;
  }
  G.vernum=vexnumber;
}

//向图中插入一个边 单向操作
int InsertArc(ALGraph &G,int i,int j,int weight)
{
    ArcNode *aArcNode = new ArcNode;
    aArcNode->vexadj=j;
    aArcNode->weight=weight;
    aArcNode->next=G.vertices[i].first;
    G.vertices[i].first=aArcNode;
    return 0;
}

int CreateDemoGraph(ALGraph &G)
{
    // 初始化图存储结构
    InitGraph(G, 7);
    // 初始化弧信息
    int arcs[][3] = {
        {0, 1, 10},
        {0, 2, 9},
        {0, 3, 13},
        {1, 3, 15},
        {1, 4, 7},
        {1, 6, 12},
        {2, 3, 4},
        {2, 5, 3},
        {3, 5, 22},
        {3, 6, 23},
        {4, 6, 20},
        {5, 6, 32},
    };
    for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
    {
        // 无向图的边由两条对称的弧组成
        InsertArc(G, arcs[i][0], arcs[i][1], arcs[i][2]);
        InsertArc(G, arcs[i][1], arcs[i][0], arcs[i][2]);
    }
    return 0;
}
vector<pair<int ,int>> Prim(ALGraph &G)
{  
    //T表示一个容器 pair=(adj,Minweight)
    vector<pair<int,int>> T;

    //初始化U向量 U[i]为1表示i结点在U中，为0表示结点不在U中
    vector<int> U(G.vernum);
    U[0]=1;
    for(int i=1;i<G.vernum;i++)
     U[i]=0;

    //cost[i]表示Vi到U集合的最小权值的边
    vector<int> cost(G.vernum); 
    for(int i=0;i<G.vernum;i++)
     cost[i]=INT_MAX;
    for(ArcNode* p=G.vertices[0].first;p!=NULL;p=p->next)
     cost[p->vexadj]=p->weight;

    //adj[i]表示Vi到U集合中最小权值的边所对应的顶点的序号
    //初始时，U中只有一个结点，所以所有值的初始化都是0
    vector<int> adj(G.vernum);
    for(int i=0;i<G.vernum;i++)
    adj[i]=0; 

    //按照MST性质挑选n-1条边,每次挑选一条边
    for(int i=0;i<G.vernum-1;i++)
    {
      //第一步：检索cost中最小的顶点k
      int k=-1;
      for(int j=0;j<G.vernum;j++)
      {
          if(!U[j] && (k==-1 || cost[j]<cost[k] ))
           k=j;
      }
      //第二步：把k顶点以及adj[k]存入T adj[k]
      U[k]=1;
      T.push_back(make_pair(k,adj[k]));

      //第三步：修改U-V中剩余顶点的cost和adj(只有顶点k需要修改)
      for(ArcNode *p=G.vertices[k].first;p!=NULL;p=p->next)
      {
          int j=p->vexadj;
          if(!U[j] && p->weight < cost[j])
          {//cost[j]和adj[j]一定是同时改变的
               cost[j]=p->weight;
               adj[j]=k;
          }
      }
      
    }
    return T;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    //用一个元素为边的容器去代替最小生成树
    vector<pair<int,int>> T=Prim(G);

    //遍历的用法
    for(auto e:T)
      cout<<G.vertices[e.second].data<<"-->"<<G.vertices[e.first].data<<endl;
    return 0;  
}