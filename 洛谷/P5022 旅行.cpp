/*
Sooke bless me.
LJC00118 bless me.
Dilute bless me.
memset0 bless me.
memset1 bless me.
Daniel14311531 bless me.
T_AK bless me.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int n,m,tem[5010],ans[5010],edge[5010][2],cando,top;
std::vector<int>vec[5010];
bool vis[5010];
void dfs(int x,int f){
	if(top<0)return;
	tem[++top]=x;
	vis[x]=1;
	for(int i=0;i<vec[x].size();++i){
		int T=vec[x][i];
		if(T==f||(edge[cando][0]==x&&edge[cando][1]==T)||(edge[cando][1]==x&&edge[cando][0]==T))
			continue;
		if(vis[T]){
			top=-n;
			return;
		}
		dfs(T,x);
	}
}
bool judge(){
	for(int i=1;i<=n;++i)if(ans[i]!=tem[i])return ans[i]>tem[i];
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,t1,t2;i<=m;++i){
		scanf("%d%d",&t1,&t2);
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);
		edge[i][0]=t1;
		edge[i][1]=t2;
	}
	for(int i=1;i<=n;++i)std::sort(vec[i].begin(),vec[i].end());
	if(m==n-1){
		dfs(1,0);
		for(int i=1;i<=n;++i)printf("%d ",tem[i]);
	}
	else{
		for(cando=1;cando<=m;++cando){
			top=0;
			memset(vis,0,sizeof vis);
			dfs(1,0);
			if(top<n)continue;
			if((!ans[1])||judge())for(int i=1;i<=n;++i)ans[i]=tem[i];
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
