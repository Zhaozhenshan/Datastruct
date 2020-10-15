#include<iostream>
using namespace std;
void SelectSort(int a[],int n)
{//简单选择排序
    for(int i=0;i<n-1;i++)
    {//一共选择n-1次最小值即可
      int min=i;
      for(int j=min+1;j<n;j++)
       if(a[j]<a[min]) min=j;
      int temp=a[i];
      a[i]=a[min];
      a[min]=temp;
    }
}
void HeapAdjust(int a[],int k,int n)
{//堆调整 //堆排序是下标1开始的 不然没法满足完全二叉树的要求
   a[0]=a[k];
   for(int i=2*k;i<=n;i*=2) 
   {
     if(i<n && a[i]<a[i+1]) i++;//选择比较大的孩子结点

     if(a[i]<= a[0]) break;//调整完成 
     else
     {
         a[k]=a[i];
         k=i;
     }
   }
   //k的值就是a[0]该插入的位置
   a[k]=a[0];
}
void BuildMaxHeap(int a[],int n)
{//构建大根堆
  for(int i=n/2;i>=1;i--)
   HeapAdjust(a,i,n);
}
void MaxHeapSort(int a[],int n)
{//大根堆排序   输出最大值点并且把a[n]排列成升序序列
    for(int i=n;i>=1;i--)
    {
        cout<<a[1]<<" ";//逆序输出
        int temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        HeapAdjust(a,1,i-1);
    }
    cout<<endl;
}
void InsertMaxHeap(int a[],int n,int key)
{
    a[n+1]=key;
    for(int i=(n+1)/2;i>=1;i/=2)
        HeapAdjust(a,i,n+1);
}
int main()
{
     int a[7]={0,2,3,4,1,5,-1};
     BuildMaxHeap(a,5);//初始化建立大根堆
     InsertMaxHeap(a,5,6);//插入一个数 向上调整为大根堆
     MaxHeapSort(a,6);//在这以后已经不是大根堆了 而是一个有序数组
}