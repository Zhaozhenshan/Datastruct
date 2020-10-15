#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
{//冒泡排序
    int flag;
    for(int i=0;i<n-1;i++)
    {//外层循环一共执行n-1次
      flag=0;
      for(int j=n-1;j>i;j--)
       if(a[j]<a[j-1]){
           int temp=a[j];
           a[j]=a[j-1];
           a[j-1]=temp;
           flag=1;
      }
      if(flag==0) break;
    }
}
int Partition(int a[],int low,int high)
{//一次划分        //开头结尾问题防止high给了low 但是呢low++之后又给了high他俩又交换了一次顺序 这是没必要的
    int temp=a[low];
    while(low<high){
        //当左边下标小于右边下标的时候
        while(low<high && a[high]>=temp) high--;
         a[low]=a[high];
        while(low<high && a[low]<=temp) low++;
         a[high]=a[low];
    }
    a[low]=temp;
    return low;
}
void QuickSort(int a[],int low,int high)
{//快速排序
   if(low<high)//递归跳出的条件
   {
       int mid=Partition(a,low,high);//一次划分并返回中间结点
       QuickSort(a,low,mid-1);
       QuickSort(a,mid+1,high);//分治思想   先进行一次排序划分 ，然后对左边进行划分，右边进行划分 在这里用到的就是一个栈的思想 Log(2)N
   }
}
int main()
{
    int a[10]={1,3,2,4};
    QuickSort(a,0,3);
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
}