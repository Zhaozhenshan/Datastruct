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
int CreateDemoGraph(ALGraph &G)
{
	InitGraph(G, 12);
	int arcs[][3] = { { 0, 1, 5 },{ 0, 2, 3 },{ 1, 3, 10 },{ 1, 6, 12 },{ 2, 3, 4 },{ 2, 4, 18 },{ 3, 5, 9 },{ 3, 6, 3 },{ 4, 10, 20 },{ 5, 7, 17 },{ 6, 8, 10 },{ 7, 9, 9 },{ 7, 11, 19 },{ 8, 9, 21 },{ 8, 10, 5 },{ 9, 11, 12 },{ 10, 11, 15 }, };
	for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
	{
		InsertArc(G, arcs[i][0], arcs[i][1], arcs[i][2]);
	}
	return 0;
}
vector<int> Topo(ALGraph &G)
{
    //返回的结果数组
    vector<int> topo(G.vernum);
    int k=0;
    //把入度为0的结点放入栈中
    stack<int> s;
    //初始化每个结点的入度
    int *degree= new int[G.vernum];
    for(int i=0;i<G.vernum;i++)
     degree[i]=0;
    
    for(int i=0;i<G.vernum;i++)
     for(ArcNode *p=G.vertices[i].first;p!=NULL;p=p->next)
     degree[p->vexadj]++;
    
    for(int i=0;i<G.vernum;i++)
     if(degree[i]==0) s.push(i);
    
    while(!s.empty())
    {
        topo[k++]=s.top();
        ArcNode *p=G.vertices[s.top()].first;
        s.pop();
        while(p!=NULL)
        {
           degree[p->vexadj]--;
           if(degree[p->vexadj]==0) s.push(p->vexadj);
           p=p->next;
        }
    }

    for(int i=0;i<G.vernum;i++)
    cout<<topo[i]<<"  ";
    return topo;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    Topo(G);
}
