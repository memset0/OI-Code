#include<stdio.h>
#define INF 100//定义一个比较大的值
int main()
{
    int days[10];//声明数组，这里多留了一些空间
    int am,pm,time,day,max=-INF,maxn;//让max足够小以便比较
    for(day=1;day<=7;day++)
  /*虽然数组应该从0开始，但这里为了输出星期几方便直接用1表示星期一*/
    {
      scanf("%d %d",&am,&pm);//输入早上和下午的时间
      days[day]=am+pm;//加起来赋给第一天
      if(days[day]<8) days[day]=0;//判断他会不会不开心，如果不会让当天是0
      if(days[day]>max)//比较得出最大值
         {
          max=days[day];
          maxn=day;
          }
    }
    if(max==0) printf("%d",max);//如果他没有一天不开心输出0
       else printf("%d",maxn);//否则输出最不开心的那天
  return 0;
}