#include<iostream>
using namespace std;
struct CompareNode  //
{//分块查找用到了这样的数据结构
    int key;//if索引表采用顺序查找 b是块数  s是每块内的数  则当s=b时，平均查找长度达到了最小sqrt(n)+1;
    int location;//if索引表采用折半查找，那么平均查找长度就是log(b+1)向上取整 + (s+1)/2
}CompareNode;
int SeqQuery(int a[],int n,int key) //查找成功(1+n)/2 查找失败1+n
{//假设a[0]中不放任何元素
  int i;
  a[0]=key;//直接把key放到a[0]这样比较好操作
  for(i=n;a[i]!=key;i--) ;
  return i;
  //当遇见这个元素时，直接返回；如果查找失败则返回0  这样从后往前判断不会越界
}
int OrderQuery(int a[],int n,int key) //成功(1+n)/2 失败n/2 +n/(n+1)
{//有序表的查找
  if(key<a[1] || key>a[n]) return 0;
  for(int i=1;i<=n;i++)
   {
       if(a[i]==key) return i;
       if(a[i]<key && (i+1)<=n && a[i+1]>key)
        return 0;
   }
   return 0;
}
int BinaryQuery(int a[],int left ,int right,int key)//时间复杂度是O(log n)
{//折半查找递归算法
    if(left > right) return 0;
    int mid = (left+right)/2;
    if(a[mid]>key) 
     return BinaryQuery(a,left,mid-1,key);
    else if (a[mid]<key)
     return BinaryQuery(a,mid+1,right,key);
    else return mid;
} 
int main()
{
    int a[15]={0,24,21,6,11,8,22,32,31,54,72,61,78,88,83};
}