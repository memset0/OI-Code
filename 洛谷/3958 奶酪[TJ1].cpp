#include<bits/stdc++.h>//万能头，最好不要用
using namespace std;//不加爆零
int f[1001];//并查集
int find(int x){
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}//查找+路径压缩
double dis(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
}//两点距离公式
long long x[100001],y[100001],z[100001];
int f1[100001],f2[100001];
//f1记录与顶面相交的洞的序号
//f2记录与底面相交的洞的序号
int main(){
	freopen("testdata.in", "r", stdin);
    int t;
    scanf("%d",&t);
    int n,h; 
    long long r;
    for (int i=1;i<=t;i++){
        scanf("%d%d%ld",&n,&h,&r);//long long不开的话...
        int tot1=0;//记录与顶面相交的洞有几个
        int tot2=0;//记录与底面相交的洞有几个
        for (int j=1;j<=n;j++){
          f[j]=j;  //并查集初始化
         }
        for (int j=1;j<=n;j++){
            scanf("%ld%ld%ld",&x[j],&y[j],&z[j]);//long long不开的话...
            if (z[j]+r>=h){//判断这个点是否与顶面相交
                tot1++;
                f1[tot1]=j;
            }
            if (z[j]-r<=0){//判断这个点是否与底面相交
                tot2++;
                f2[tot2]=j;
            }
            for (int k=1;k<=j;k++){//枚举之前的洞是否与这个洞相交，如果相交则合并集合
                if (dis(x[j],y[j],z[j],x[k],y[k],z[k])<=2*r){
                    int a1=find(j);
                    int a2=find(k);
                    if (a1!=a2)
                      f[a1]=a2;
                }
            }
        }
        int s=0;
        //看看每一个中是否有洞连接上下面
        for (int j=1;j<=tot1;j++){
            for (int k=1;k<=tot2;k++){
                if (find(f1[j])==find(f2[k])){
                    s=1; 
                    break;
                }
            }
            if (s==1) break;
        }
        if (s==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        
		vector < int > t[1010];
		for (int i = 1; i <= n; i++)
			t[find(i)].push_back(i);
		for (int i = 1; i <= n; i++)
			if (t[i].size()) {
				printf("%4d:", i);
				for (int j = 0; j < t[i].size(); j++)
					printf(" %d", t[i][j]);
				puts("");
			}
    }
    return 0;
} 
