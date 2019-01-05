#include<cstdio>
#include<algorithm>
using namespace std;
int Solve(int x,int ret) {
    if(x==1)                    //当数字为1是返回周期长度
        return ret;
    int t=x&1? x*3+1:x/2;
    return Solve(t,ret+1);      //继续递归求值
}
int main() {
    for(int i,j,ans;~scanf("%d%d",&i,&j);) {
        ans=0;
        for(int k=min(i,j),l=max(i,j);k<=l;++k)
            ans=max(ans,Solve(k,1));
        printf("%d %d %d\n",i,j,ans);       //注意，i与j的顺序是输入中的顺序
    }
    return 0;
}