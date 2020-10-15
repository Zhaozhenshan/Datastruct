#include<iostream>
using namespace std;
void Next(char a[],int next[],int n)
{//n是模式串的长度
    next[1]=0;
    int i=1,j=0;
    while(i<n)
    {
        if(j==0 || a[i]==a[j])//如果两个相等，直接移动然后复制
                next[++i] = ++j;
        else
            j=next[j];
    }
}
void NextVal(char a[],int nextval[],int n)
{//n依旧是元素的个数
    nextval[1]=0;
    int i=1,j=0;
    while(i<n)
    {
        if(j==0 || a[i]==a[j])
        {
            //相等才有资格后移
            i++;j++;
            if(a[i]==a[j]) 
              nextval[i]=nextval[j];
            else 
              nextval[i]=j;
        }
        else
        {
            j=nextval[j];
        }
    }
}
int KMP(char a[],int lena,char b[],int lenb,int nextval[])
{//根据nextval来进行模式匹配
    int i=1,j=1;
    while(i<=lena && j<=lenb)
    {
       if(j==0 || a[i]==b[j])
       {
           i++;
           j++;
       }
       else
       {
           j=nextval[j];
       }
    }
    if(j>lenb)
     return i-lenb;
    else
    {
        return 0;
    }
    
}
int main()
{//注意 只有在开辟空间或者创造数组的时候才多创造一个，其他的地方一律从1—n n是元素的个数
    char a[]="0aaabaaaab";//9
    char b[]="0aaaab";//5
    int nextval[6];
    NextVal(b,nextval,5);
    cout<<KMP(a,9,b,5,nextval);
}