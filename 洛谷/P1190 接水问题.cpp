#include <stdio.h> //头文件
int main()
{
    long int n,m,a[100001],b[100001],sum,time=0,i,num;
    scanf("%ld%ld",&n,&m); //输入排队的人数和水龙头数量
    for (i=1;i<=n;i++)
    scanf("%ld",&a[i]); //输入N个排队的人的接水所需时间
    if (n<m)
    m=n; //如果水龙头数量比排队人数多，只开N个水龙头使用，剩余的水龙头关闭
    for (i=1;i<=m;i++)
    b[i]=a[i];  //将A数组中前M个数放入B数组，代表这M个人开始接水
    sum=m; 
    num=n; //赋初值
    while(1) //开始循环
    {
        time++;  //秒数加一
        for (i=1;i<=m;i++)  
        {
            b[i]--; //将正在接水的人的所需时间减一
        if (b[i]==0) //如果这个人水接完了
        {
            sum++; //下标+1，移到下一个人
            num--; //未接水的人数减一
        b[i]=a[sum]; //将等待接水的第一个人放入B数组，即其在第I个水龙头下开始接水了
        }
        }
        if(sum>n&&num<1) break; //如果没有待接水的人就结束模拟
        }
    printf("%ld\n",time); //输出秒数
    return 0;
}