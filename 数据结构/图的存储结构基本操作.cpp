#include<iostream>
using namespace std;
#include<queue>
#define MaxVertexNum 100 //最多有100个结点
typedef char Vertex;//顶点的数据类型
typedef int Edge;
typedef int info;
//图的邻接矩阵存储
struct MGraph
{
    Vertex Vex[MaxVertexNum];//一位结点数组
    Edge Edge[MaxVertexNum];//二维数组
    int vexnum,arcnum;
};

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
int InsertArc(ALGraph &G,int i,int j)
{
    ArcNode *aArcNode = new ArcNode;
    aArcNode->vexadj=j;
    aArcNode->next=G.vertices[i].first;
    G.vertices[i].first=aArcNode;
    return 0;
}

//图的深度优先遍历--遍历一个结点
int DFS(ALGraph &G,int v0,int visited[])
{
    cout<<G.vertices[v0].data<<",";//Visit V0
    visited[v0]=1;//深度优先遍历用了一个访问指针
    for(ArcNode *p=G.vertices[v0].first;p!=NULL;p=p->next)
    {//最上层是顺序的;下面的过程是递归的
      if(!visited[p->vexadj])
       DFS(G,p->vexadj,visited);
    }
    return 0;
}
//图的深度优先遍历--遍历所有的结点
int DFSTraverse(ALGraph &G)
{
  int *visited = new int[G.vernum];
  for(int i=0;i<G.vernum;i++) visited[i]=0;
  for(int i=0;i<G.vernum;i++)
  {
      if(!visited[i])
       DFS(G,i,visited);
  }
  delete [] visited;
  return 0;
}

//图的广度优先遍历--遍历一个结点
int BFS(ALGraph &G,int v0,int visited[])
{//先把一个结点访问了，其他结点入队；再从队列中弹出一个结点，再入队即可
    queue<int> q;
    q.push(v0);
    visited[v0]=1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout<<G.vertices[v].data<<",";//Visit
        for(ArcNode *p=G.vertices[v].first;p!=NULL;p=p->next)
        {
           if(!visited[p->vexadj])
           {
               q.push(p->vexadj);
               visited[p->vexadj]=1;
           }
        }
    }
    return 0;
}
//图的广度优先遍历，遍历所有的结点
int BFSTraverse(ALGraph &G)
{
    int *visited = new int[G.vernum];
    for(int i=0;i<G.vernum;i++) visited[i]=0;
    for(int i=0;i<G.vernum;i++)
    {
        if(!visited[i])
         BFS(G,i,visited);
    }
    delete visited;
    return 0;
}
int CreateDemoGraph(ALGraph &G)
{
    InitGraph(G,10);//初始化十个结点
    int arcs[][2] = 
    { {0, 1}, {0, 2}, 
      {1, 4}, {1, 7}, 
      {2, 1}, {2, 4}, 
      {3, 0}, {3, 8}, 
      {5, 2}, {5, 9}, 
      {6, 9}, {7, 4}, 
      {7, 5}, {8, 0}, 
      {9, 5}, {9, 7} };
      for(int i=0;i<sizeof(arcs)/sizeof(*arcs);i++)
      {
         InsertArc(G,arcs[i][0],arcs[i][1]);
      }
      return 0;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);

    cout<<"深度遍历:";
    DFSTraverse(G);
    cout<<endl;

    cout<<"广度遍历:";
    BFSTraverse(G);
    cout<<endl;

    return 0;
}