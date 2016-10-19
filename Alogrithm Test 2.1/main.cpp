//
//  main.cpp
//  Alogrithm Test 2.1
//
//  Created by 黄沐 on 2016/10/18.
//  Copyright © 2016年 Hm. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
//采用动态规划法求解字符串的编辑距离(edit distance)
//问题描述:对于给定的字符串A和B，它们之间的编辑距离定义为:允许对B进行如下操作:
//1.删去一个字符 2.插入一个字符 3.替换一个字符，每操作一次，则计数加1，将B转化为A所需的最小操作次数即为A和B之间的编辑距离
int n;
string A;
string B;
string A_test1="abcded",A_test2="akyyyycc";
string B_test1="abcdfg",B_test2="xxxxxxab";
int min( int a, int b, int c);//最小数
void EditDistance( int len1, int len2);//edit distance 算法
void EditDistance_Test( string a, string b);//测试算法
int  main( int argc, const char * argv[]) {
    // insert code here...
    EditDistance_Test( A_test1, B_test1);
    EditDistance_Test( A_test2, B_test2);
    cout<<"请分别输入 你想要输入的字符串 "<<endl;
    while(cin>>A>>B)
    {
        EditDistance(A.length(),B.length());
    }
    return 0;
}
int min( int a, int b, int c)
{
    int tmp=a<b?a:b;
    return tmp<c?tmp:c;
}
void EditDistance( int len1, int len2)
{
    int **d=new int*[len1+1];
    for( int i=0; i<=len1; i++)
        d[i]=new int[len2+1];
    int i,j;
    for( i=0; i<=len1; i++)
        d[i][0]=i;
    for( j=0; j<=len2; j++)
        d[0][j]=j;
    for( i=1; i<=len1; i++)
    {
        for( j=1; j<=len2; j++)
        {
            int cost=A[i]==B[i]?0:1;
            int deletion=d[i-1][j]+1;
            int insertion=d[i][j-1]+1;
            int substitution=d[i-1][j-1]+cost;
            d[i][j]=min(deletion,insertion,substitution);
        }
    }
    cout<<"edit distance 最短距离为: "<<d[len1][len2]<<endl;
    cout<<"请分别输入 你想要输入的字符串 "<<endl;
    for( int i=0; i<=len1; i++)
    {
        delete[] d[i];
    }
    delete[] d;
}
void EditDistance_Test( string a, string b)
{
    cout<<"以下为测试代码"<<endl;
    int len1=a.length();
    int len2=b.length();
    int **d=new int*[len1+1];
    for( int i=0; i<=len1; i++)
        d[i]=new int[len2+1];
    int i,j;
    for( i=0; i<=len1; i++)
        d[i][0]=i;
    for( j=0; j<=len2; j++)
        d[0][j]=j;
    for( i=1; i<=len1; i++)
    {
        for( j=1; j<=len2; j++)
        {
            int cost=a[i]==b[i]?0:1;
            int deletion=d[i-1][j]+1;
            int insertion=d[i][j-1]+1;
            int substitution=d[i-1][j-1]+cost;
            d[i][j]=min(deletion,insertion,substitution);
        }
    }
    cout<<"测试字符串A为: "<<a<<"  测试字符串B为: "<<b<<endl;
    cout<<"其edit distance 最短距离为: "<<d[len1][len2]<<endl;
    cout<<"以上为测试代码"<<endl<<endl;
    //依次释放指针数组对象
    for( int i=0; i<=len1; i++)
    {
        delete[] d[i];
    }
    //释放指针数组
    delete[] d;
}
