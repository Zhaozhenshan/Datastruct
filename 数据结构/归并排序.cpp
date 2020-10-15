#include<iostream>
using namespace std;
int b[1024];
void Merge(int  a[],int low,int mid,int high)
{//一次归并
    for(int i=low;i<=high;i++)//复制给新数组B
     b[i]=a[i];

    int i,j,k;
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++)
    {//这里的high是数组上届下标值
          if(b[i]<=b[j]) a[k]=b[i++];
          else           a[k]=b[j++];
    }

    while(i<=mid)  a[k++]=b[i++];
    while(j<=high) a[k++]=b[j++];//两个while只有一个会执行
}
void MergeSort(int a[],int low,int high)
{//递归给数组进行排序
   if(low<high)
   {
    //什么时候开始执行呢？应该是当有两个参数的时候调用这个函数，low和mid相等了 mid+1和high也相等了 
    //这个时候俩人都没有执行，执行的是下面那个函数，即：两个单元素进行排序这就对了
     int mid=(low+high)/2;
     MergeSort(a,low,mid);//左边递归排序
     MergeSort(a,mid+1,high);//右边递归排序
     Merge(a,low,mid,high);//整体排序
   }
}
int main()
{
    int a[8]={8,7,6,5,4,3,2,1};
    MergeSort(a,0,7);
    for(int i=0;i<8;i++)
    cout<<a[i]<<" ";
}