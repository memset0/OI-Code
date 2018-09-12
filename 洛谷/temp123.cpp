#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
int e[maxn][maxn]={0},du[maxn]={0},lu[maxn],s=0x3f3f3f3f,cnt=0,pos=0,n;
int pan(char x)
{
    if(x <= 'z' && x >= 'a') return x - 'a' + 27;
    else return x - 'A' + 1;
}
int pan2(char x)
{
    if(x <= 26) return 'A' + x - 1;
    return 'a' + x - 27;
}
void dfs(int x)
{
    for(int y=1;y<=52;y++)
    {
        if(e[x][y]==1)
        {
    	printf("%d -> %d\n", x, y);
            e[x][y]=e[y][x]=0;
            dfs(y);
        }
    }
    lu[++pos]=x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin>>x>>y;
        du[pan(x)]++,du[pan(y)]++;
        e[pan(x)][pan(y)]=e[pan(y)][pan(x)]=1;
    }
    for(int i=1;i<=52;i++)
    if(du[i]%2==1) //找欧拉路最小起点 
    {
        s=min(s,i),cnt++;
    }
    if(cnt!=0&&cnt!=2) //假如既不是欧拉路也不是欧拉回路 
    {
        cout<<"No Solution"<<endl;
        return 0;
    }
    if(cnt == 0)//如果是欧拉回路，那此时s还是maxn，所以需要再判断一下 
    for(int i=1;i<=52;i++) if(du[i]) {
        s = i;
        break;
    }
    cout << s << endl; 
    dfs(s);
    for(int i=pos;i>=1;i--)
    printf("%c",pan2(lu[i]));

    return 0;
}
