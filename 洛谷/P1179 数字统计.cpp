#include <iostream>
using namespace std;
int m,n,num;//n,m是范围  num是2出现的总的个数 
int judge(int x)//判断数字二的出现 
{
    int a,n=0;
    for(int i=1;i<=1000000;i++)//因为不知道总个数，所以范围大一些
    //其实这里用while最合适，但我用for顺手一些 
    {
        if(x<=0)//循环出口，如果除到最后比0小了，说明没位数了 
        return n;//则返回个数 
        a=x%10;//取最后一位 
        if(a==2)//如果是2 
        n++;//计数 
        x=x/10;//把这一位去掉 
    }
}
void doing()
{
    for(int i=n;i<=m;i++)//从n~m中搜寻 
    {
        num=num+judge(i);//就是用总个数加上刚才判断的个数（即为新出了个数） 
    }
    cout<<num<<endl;//输出个数 
}
int main()
{
  cin>>n>>m;
  doing();//调用函数 
  return 0;
}