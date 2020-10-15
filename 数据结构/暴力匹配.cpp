#include<iostream>
using namespace std;
int Baoli(char a[],int lena,char b[],int lenb)
{//a是原串  b是模式串 lena是串a的长度 lenb是串B的长度 暴力匹配算法
  int i=1,j=1;
  while(i<=lena && j<=lenb)
  {
      if(a[i]==b[j]) 
      {//相等则后移
          i++;j++;
      }
      else
      {//不相等则直接后移一位
        i=i-j+1+1;
        j=1;
      }
  }
  if(j>lenb)
    return i-j+1;
  else 
    return 0;
}
int main()
{
    char a[]="0aabcdefgh";
    char b[]="0bcdef";
    cout<<Baoli(a,10,b,5);
}