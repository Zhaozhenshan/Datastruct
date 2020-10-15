#include<iostream>
using namespace std;
int main()
{
    int a[10]={278,109,63,930,589,184,505,269,8,83};
    int key[10][10]={0};
    int loc[10]={0};
    for(int i=0;i<10;i++)
    {
        int ge=a[i]%10;
        key[ge][loc[ge]++]=a[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<loc[i];j++)
         cout<<key[i][j]<<" ";
    }
}