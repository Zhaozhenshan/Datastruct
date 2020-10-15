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
  int flag;
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
    aArcNode->flag=0;
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
//Kruskal算法求单源最短路径
vector<pair<int ,int>> Kruskal(ALGraph &G)
{
  vector<pair<int,int>> T;
  vector<int> U(G.vernum);
  for(int i=0;i<G.vernum;i++)
   U[i]=0;
  for(int k=0;k<G.vernum-1;k++)
  {
    int minx,miny;
    int minweight=999;

    //找一个权值最小的边
    for(int i=0;i<G.vernum;i++)
     for(ArcNode *p=G.vertices[i].first;p!=NULL;p=p->next)
      if( (p->flag==0) && p->weight<minweight )
       {//它需要借助一些并查集的内容，触碰到了我的知识盲区，所以不太行
          minweight=p->weight;
          minx=i;
          miny=p->vexadj;
          p->flag=1;
          for(ArcNode *q=G.vertices[miny].first;q!=NULL;q=q->next)
          {
             if(q->vexadj==minx)
              q->flag=1;
          }
       }
    T.push_back(make_pair(minx,miny));
  }
  return T;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    //用一个元素为边的容器去代替最小生成树
    vector<pair<int,int>> T=Kruskal(G);

    //遍历的用法
    for(auto e:T) 
      cout<<G.vertices[e.first].data<<"-->"<<G.vertices[e.second].data<<endl;
    return 0;  
}