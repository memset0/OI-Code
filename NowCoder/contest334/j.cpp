#include <cstdio>
const int MOD=100000007;
 
int n,f[10005];
 
int main(){
    f[0]=1;
    for (int i=1;i<=10000;++i){
        f[i]=f[i-1];
        for (int j=2;j<=i;j+=2){
            f[i]+=f[i-j];
            f[i]%=MOD;
        }
    }
    while (scanf("%d",&n)!=EOF) printf("%d\n",f[n]);
    return 0;  
}
