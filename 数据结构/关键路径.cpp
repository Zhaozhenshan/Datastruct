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
	InitGraph(G, 6);
	int arcs[][3] = { { 0, 1, 3 },{ 0, 2, 2 },{ 1, 3, 2},{ 1, 4, 3},{ 2, 3, 4},{ 2, 5, 3},{ 3, 5, 2},{ 4, 5, 1}};//8条边
	for (int i = 0; i < sizeof(arcs) / sizeof(*arcs); i++)
	{
		InsertArc(G, arcs[i][0], arcs[i][1], arcs[i][2]);
	}
	return 0;
}
//关键路径
void CriticalPath(ALGraph &G)
{
      //计算各个结点的入度
      int *dep=new int[G.vernum];
      for(int i=0;i<G.vernum;i++) dep[i]=0;

      for(int i=0;i<G.vernum;i++)
       for(ArcNode *p=G.vertices[i].first;p!=NULL;p=p->next)
        dep[p->vexadj]++;
      
      stack<int> s;//栈s：保存入度为零的结点
      for(int i=0;i<G.vernum;i++) 
       if(dep[i]==0) s.push(i);

      stack<int> s2;//保存拓扑逆序列

      //初始化vl数组为0
      int *vl=new int[G.vernum];
      for(int i=0;i<G.vernum;i++) vl[i]=0;

      while(!s.empty())
      {//遍历入度为0的各个结点
        int j=s.top();
        s.pop();
        s2.push(j);
        for(ArcNode *p=G.vertices[j].first;p!=NULL;p=p->next)
        {   //更新各个邻接结点的信息
            if( (vl[j]+p->weight) >vl[p->vexadj] )
             vl[p->vexadj]=vl[j]+p->weight;
            
            //将度为0的结点入栈
            dep[p->vexadj]--;
            if(dep[p->vexadj]==0) s.push(p->vexadj);
        }
      }

      //初始化ve数组为最大值
      int maxv=vl[G.vernum-1];
      int *ve = new int[G.vernum];
      for(int i=0;i<G.vernum;i++)
       ve[i]=maxv;
      
      //按照逆拓扑序列求ve数组
      while(!s2.empty())
      {
          int j=s2.top();s2.pop();
          for(ArcNode *p=G.vertices[j].first;p!=NULL;p=p->next)
          {
              if( ve[j]> (ve[p->vexadj]-p->weight) )
               ve[j]=ve[p->vexadj]-p->weight;
          }
      }
 
      int sum=0;
      for(int i=0;i<G.vernum;i++)
      {
          int e;
          int l;
          for(ArcNode *p=G.vertices[i].first;p!=NULL;p=p->next)
          {
             e=vl[i];
             l=ve[p->vexadj]-p->weight;
             if(e==l){
                 cout<<"路径:"<<G.vertices[i].data<<"-->" << G.vertices[p->vexadj].data<<"  weights:"<<p->weight<<endl;
                 sum+=p->weight;
             }
          }
      }
      cout<<"关键路径的长度为:"<<sum<<endl;
}
int main()
{
    ALGraph G;
    CreateDemoGraph(G);
    CriticalPath(G);
}