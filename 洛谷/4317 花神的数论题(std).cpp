#include<cstdio>
#define LL long long
#define M 10000007
LL N,Ans=1;
LL C,G[50];
LL qPow(LL b,LL e){LL A=1;for(;e;b=b*b%M,e>>=1)e&1?A=A*b%M:0;return A;}
int main(){
    scanf("%lld",&N);
    for(int j=49;~j;--j){
        for(int i=49;i;--i)
            G[i]+=G[i-1];
        if(N>>j&1) ++G[C++];
    } ++G[C];
    for (int i = 1; i < 50; i++)
        printf("%lld\n", G[i]%10000007);
    for(int i=1;i<=49;++i)
        Ans=Ans*qPow(i,G[i])%M;
    printf("%lld",Ans);
    return 0;
}