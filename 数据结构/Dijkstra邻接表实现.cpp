#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<stack>
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
int OutPutPath(vector<int> path,int v0,int end)
{//栈还能这么用呀~~
  if(end==v0)
    cout<<v0;
  else
  {
    OutPutPath(path,v0,path[end]);
    cout<<" -> "<<end;
  }
  return 0;
}
//Dijkstra单源最短路径算法
vector<int> Dijkstra(ALGraph &G,int v0)
{
    vector<int> U(G.vernum);//U集合 用于判定结点是否被访问
    vector<int> path(G.vernum);//path[i]代表从v0到vi的最短路径中i的上一个结点
    vector<int> mindistance(G.vernum);//用于记录各个结点到v0的最短距离

    for(int i=0;i<G.vernum;i++)
    {
        mindistance[i]=INT_MAX;//代表距离的最大值
        U[i]=0;//代表都没访问过
        path[i]=-1;//初始化path为-1
    }

    U[v0]=1;
    mindistance[v0]=0;
    for(ArcNode *p=G.vertices[v0].first;p!=NULL;p=p->next)
    {//遍历所有v0的邻接点
      mindistance[p->vexadj]=p->weight;
      path[p->vexadj]=v0;
    }

    //进行n-1次挑选，每次挑选都会有一个顶点加入U集合
    for(int count=0;count<G.vernum-1;count++)
    {
        int k=-1;
        //选出一个到v0距离最近的顶点
        for(int i=0;i<G.vernum;i++)
          if(!U[i] && (k<0 || mindistance[i]<mindistance[k])) k=i;
        
        //将k结点加入U并修改相关信息
        U[k]=1;
        for(ArcNode *p=G.vertices[k].first;p!=NULL;p=p->next)
        {
            if(!U[p->vexadj] && (mindistance[k]+p->weight)<mindistance[p->vexadj])
            {
                mindistance[p->vexadj]=mindistance[k]+p->weight;
                path[p->vexadj]=k;
            }
        }
    }
    for(int i=0;i<G.vernum;i++)
    cout<<path[i]<<" ";
    cout<<endl;
    return path;
} 
int CreateDemoGraph(ALGraph &G)
{
	InitGraph(G, 6);
	int arcs[][3] = { { 0, 1, 17 },{ 0, 2, 21 },{ 0, 3, 12 },{ 0, 4, 5 },{ 1, 0, 6 },{ 1, 5, 4 },{ 2, 0, 10 },{ 2, 3, 14 },{ 3, 1, 11 },{ 3, 5, 4 },{ 4, 1, 4 },{ 4, 2, 13 },{ 5, 0, 9 },{ 5, 4, 20 }, };
	for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
	{
		InsertArc(G, arcs[i][0], arcs[i][1], arcs[i][2]);
	}
	return 0;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    vector<int> path = Dijkstra(G,0);
    for(int i=0;i<G.vernum;i++)
    {
      if(path[i]<0) continue;
      OutPutPath(path,0,i);
      cout<<endl;
    }
}