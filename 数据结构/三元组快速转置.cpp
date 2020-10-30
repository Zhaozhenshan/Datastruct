#include<iostream>
using namespace std;
int a[3][5];
struct TriNode
{
    int row,col;
    int data;
};
struct TriTable
{
    TriNode *datas;
    int mu,nu,tu;
};
int PrintTriTable(TriTable B)
{
  cout<<"三元组表:"<<" mu="<<B.mu<<"  nu="<<B.nu<<" tu="<<B.tu<<endl;
  for(int i=0;i<B.tu;i++)
    cout<<B.datas[i].row<<"   "<<B.datas[i].col<<"    "<<B.datas[i].data<<endl;
  return 0;
}
int CreateTriTable(TriTable &B,int a[],int m,int n)
{
   B.mu=m;
   B.nu=n;
   //统计非零元的个数，分配初始的空间
   int count=0;
   for(int i=0;i<m*n;i++)
    if(a[i]!=0) count++;
   B.datas =new TriNode[count];
   B.tu=count;
   int k=0,t=0;
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
      if(a[k]!=0)//k是实际记录的a中的位置对应的虚拟的A[i][j]
      {
          B.datas[t].row=i;
          B.datas[t].col=j;
          B.datas[t].data=a[k];
          t++;//t记录的是三元组表中对应的个数
      }
      k++;
    }
    return 0;
}
int FastTranspose(TriTable &B,TriTable &A)
{
    //初始化三元组表
    B.mu=A.nu;
    B.nu=A.mu;
    B.tu=A.tu;
    B.datas=new TriNode[B.tu];

    //rsum是存储三元组表B中每行非零元的个数
    int *rsum=new int[B.mu];
    for(int i=0;i<B.mu;i++) 
      rsum[i]=0;
    for(int i=0;i<A.tu;i++)
      rsum[A.datas[i].col]++;

    //动态pos数组是记录每行元素的初始位置
    int *pos=new int[B.mu];  
    for(int i=0;i<B.mu;i++) 
      pos[i]=0;
    pos[0]=0;
    for(int i=1;i<B.mu;i++)
     pos[i]=pos[i-1]+rsum[i-1];

    //将三元组A存储到三元组B中
    for(int i=0;i<A.tu;i++)
    {
        int j=pos[A.datas[i].col];//定位
        B.datas[j].row=A.datas[i].col;//赋值
        B.datas[j].col=A.datas[i].row;
        B.datas[j].data=A.datas[i].data;
        pos[A.datas[i].col]++;//自增
    } 
    return 0;
}
int main()
{
   TriTable A,B;
   int a[15]={0 , 14 , 0 , 0  , -5 ,
              0 , -7 , 0 , 0  ,  0 ,
              36,  0 , 0 , 28 ,  0 };
   CreateTriTable(A,a,3,5);
   FastTranspose(B,A);
   cout<<"转置之前的三元组表:"<<endl;
   PrintTriTable(A);
   cout<<"转置之后的三元组表:"<<endl;
   PrintTriTable(B);
   return 0;
}