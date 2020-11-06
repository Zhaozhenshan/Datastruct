#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<stack>
#define MaxVertexNum 100 //最多有100个结点
typedef char Vertex;//顶点的数据类型
typedef int Edge;
typedef int info;
int path[1024][1024];
int a[1024][1024];
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
  for(int i=0;i<G.vernum;i++)
   for(int j=0;j<G.vernum;j++)
   {
       if(i==j) 
         a[i][j]=0;
       else     
         a[i][j]=INT_MAX;
       path[i][j]=-1;
  }
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
	InitGraph(G, 6);
	int arcs[][3] = { { 0, 1, 17 },{ 0, 2, 21 },{ 0, 3, 12 },{ 0, 4, 5 },{ 1, 0, 6 },{ 1, 5, 4 },{ 2, 0, 10 },{ 2, 3, 14 },{ 3, 1, 11 },{ 3, 5, 4 },{ 4, 1, 4 },{ 4, 2, 13 },{ 5, 0, 9 },{ 5, 4, 20 }, };
	for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
	{
		InsertArc(G, arcs[i][0], arcs[i][1], arcs[i][2]);
	}
	return 0;
}
void Floyd(ALGraph &G)
{
    for(int i=0;i<G.vernum;i++)
     for(ArcNode *p=G.vertices[i].first;p!=NULL;p=p->next)
     {
       a[i][p->vexadj]=p->weight;
       path[i][p->vexadj]=i;
     }
    for(int k=0;k<G.vernum;k++)
     for(int i=0;i<G.vernum;i++)
      for(int j=0;j<G.vernum;j++)
       if(a[i][k]<INT_MAX && a[k][j]<INT_MAX && a[i][k]+a[k][j]<a[i][j])
       {
           a[i][j]=a[i][k]+a[k][j];
           path[i][j]=path[k][j];
       }
}
void Output(int start,int end)
{
    if(end==start)
     cout<<start;
    else
    {
      Output(start,path[start][end]);
      cout<<" -> " <<end;
    }
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    Floyd(G);
    for(int i=0;i<G.vernum;i++)
     for(int j=0;j<G.vernum;j++)
      {
          if(i==j) continue;
          else Output(i,j);
          cout<<"最短路径的长度是:"<<a[i][j];
          cout<<endl;
      }
}