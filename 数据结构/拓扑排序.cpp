#include<iostream>
using namespace std;
int main()
{
    int a[5][5]={
        {0,1,0,1,0},
        {0,0,1,1,0},
        {0,0,0,0,1},
        {0,0,1,0,1},
        {0,0,0,0,0}
    };
    int S[5]={0};
    int dep[5]={0};
    //求一次dep就够了
    for(int j=0;j<5;j++) 
     for(int i=0;i<5;i++)
      dep[j]+=a[i][j];
    for(int k=0;k<5;k++)
    {
      for(int i=0;i<5;i++)
      {
          if(!S[i]&&dep[i]==0)
          {
              S[i]=1;
              cout<<i<<" ";
              for(int j=0;j<5;j++)
              {
                  if(a[i][j]==1) {
                      dep[j]--;
                      a[i][j]=0;
                  }
              }
          }
      }  
    }
    bool flag=true;
    for(int i=0;i<5;i++)
     if(dep[i]!=0) flag=false;
    if(flag) 
        cout<<"存在拓扑排序!"  <<endl;
    else 
        cout<<"不存在拓扑排序!"<<endl;
}