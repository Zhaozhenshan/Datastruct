#include<iostream>
using namespace std;
void insertSort(int a[],int n)
{//直接插入排序
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1]){
            a[0]=a[i];//保存a[i]
            int j;
            for(j=i-1;a[j]>a[0];j--)
             a[j+1]=a[j];
            a[j+1]=a[0];
        }
    }
}
void HalfInsertSort(int a[],int n)
{//折半插入排序
    int low,high,mid;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            a[0]=a[i];
            low=1;
            high=i-1;//初始化每一次遍历的下界
            while(low<=high){
                //这里的high就是要插入位置的前一个
                int mid=(low+high)/2;
                if(a[mid]>a[0])
                    high=mid-1;
                else 
                    low = mid+1;
            }

            for(int j=i-1;j>=high+1;j--)
            a[j+1]=a[j];

            a[high+1]=a[0];
        }
    }
}
void SheelSort(int a[],int n)
{//希尔排序
    for(int di=n/2;di>=1;di/=2)
    {//规定增量
        for(int i=di+1;i<=n;i++)
        {//普通的插入排序
             if(a[i]<a[i-di])
             {
                 int j;
                 a[0]=a[i];
                 for(j=i-di;j>0 && a[j]>a[0];j-=di)
                     a[j+di]=a[j];
                 a[j+di]=a[0];    
             }

        }
    }
}
int main()
{
    int a[7]={0,4,9,8,5,6,7};
    //insertSort(a,6);
    SheelSort(a,6);
    for(int i=1;i<=6;i++)
    cout<<a[i]<<" ";
}