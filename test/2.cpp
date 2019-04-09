//
// Created by zqn on 2019/4/9.
//

//1483 化学变换
//题目来源： CodeForces
//基准时间限制：1 秒 空间限制：131072 KB 分值: 20 难度：3级算法题
//
//有n种不同的化学试剂。第i种有ai升。每次实验都要把所有的化学试剂混在一起，但是这些试剂的量一定要相等。所以现在的首要任务是把这些化学试剂的量弄成相等。
//
//有两种操作：
//
//·        把第i种的量翻倍，即第i种的量变成2ai。
//
//·        把第i种的量减半，除的时候向下取整，即把第i种的量变成  。
//
//现在所有的化学试剂的量已知，问最少要变换多少次，这些化学试剂的量才会相等。
//
//样例解释：把8变成4，把2变成4。这样就需要两次就可以了。
//
//
//Input
//单组测试数据。
//第一行有一个整数n (1 ≤ n ≤ 10^5)，表示化学物品的数量。
//第二行有n个以空格分开的整数ai (1 ≤ ai ≤ 10^5)，表示第i种化学试剂的量。
//Output
//输出一个数字，表示最少的变化次数。
//Input示例
//3
//4 8 2
//Output示例
//2
//
//System Message (题目提供者)
//列举每一个数可能产生的数，同时标记，并且记录产生这个数的步数，枚举的时候奇数可以乘2来枚举数，偶数的话枚举出来的数，一定已经出现过了

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+100;
#define INF 0x3f3f3f3f
int num[maxn],sum[maxn],n;
void f(int temp,int cnt)
{
    int i;
    for(temp=temp*2,cnt++;temp<maxn;temp*=2,cnt++)
    {
        num[temp]++;
        sum[temp]+=cnt;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            int a,cnt=0;
            scanf("%d",&a);
            bool flag=true;
            while(a)
            {
                num[a]++;
                sum[a]+=cnt;
                if(flag)
                    f(a,cnt);
                if(a&1) flag=true;
                else flag=false;
                a/=2;
                cnt++;
            }
        }
        int ans=INF;
        for(int i=0;i<maxn;i++)
            if(num[i]==n)
                ans=min(ans,sum[i]);
        printf("%d\n",ans);
    }
    return 0;
}
