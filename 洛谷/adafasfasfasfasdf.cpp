博客园首页新随笔联系订阅 管理
随笔 - 769  文章 - 1  评论 - 69
NOIPSB评测机+SB题DAY2
忍者钩爪
题目描述
小 Q 是一名酷爱钩爪的忍者， 最喜欢飞檐走壁的感觉， 有一天小 Q 发现一个练习使用钩
爪的好地方，决定在这里大显身手。
场景的天花板可以被描述为一个无穷长的数轴， 初始小 Q 挂在 原点上。 数轴上有 N 个坐
标为整数的圆环供小 Q 实现钩爪移动。具体操作为：小 Q 可以将钩爪挂到圆环上，进而荡到
关于圆环坐标 轴对称的位置。例如小 Q 在 3，圆环在 7，则小 Q 可以通过该圆环移动到 11。
现在一个问题难倒了小 Q，如何判断自己能否到达某个整点呢？

输入格式
第一行两个整数 N,M，表示圆环的数量和询问组数
接下来一行共 N 个整数描述每个圆环的坐标(可重复)
接下来 M 行每行包含一个整数描述询问

输出格式
共 M 行对应 M 个询问，若小 Q 能移动到目标点，输出 Yes，否则输出 No

样例
2 2
1 3
3
4

No
Yes
数据范围
对于 30%的数据，M≤N≤10，输入坐标绝对值均小于 1000。
对于 60%的数据，M≤N≤5000。
对于 100%的数据，M≤N≤100000，输入坐标绝对值均小于 [Math Processing Error]。
随手写了个60的做法，然后跑去写T2，然后脑残的YES，NO输成全大写了
画图选点推式子可得它可到达的坐标距离为[Math Processing Error], x为当前坐标那么
初始坐标为原点，那么奇数坐标是肯定不能到达的QAQ
根据广义裴蜀定理以及扩展欧几里得相关原理可知，当且仅当目标为gcd的倍数时有解。
故预处理出全部可能的2(a[j]-a[i])，求出其最大公约数，在判断目标是否为gcd的倍数即可复杂度N^2可拿60分
通过欧几里得算法的性质与更相减损术可知gcd(a,b)=gcd(a-b,b)。
设p1={2(a[i]-a[1])|i>1}的最大公约数，设p2={2(a[i]-a[j])}的最大公约数，易知p1>=p2（因为p1比p2约束宽松）
而对于任意i,j由于p1同时是2(a[i]-a[1])、2(a[j]-a[1])的约束，那么p1也一定是任意2(a[i]-a[1])-2(a[j]-a[1])=2*(a[i]-a[j])的约数，故p1<=p2。综上所述p1=p2，
这样就不需要N^2个数同时求gcd了，只求p1即可，可获得满分。
code：

#include<cstdio> 
#include<iostream>
#include<algorithm> 
using namespace std;
const int maxn = 2000007; 
#define LL long long
int n,m,cnt=0;
LL a[maxn];
LL g;
LL gcd(LL x,LL y) {
    if(y==0)return x;
    else return gcd(y,x%y);
}
int main () {

    int c1=0,c2=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        LL aa;
        scanf("%lld",a+i);
    }
    g=2*(a[1]-a[2]);
    for(int i=1;i<=n;i++) g=gcd(g,2*(a[i]-a[1]));
    for(int i=1;i<=m;i++) {
        LL q;
        scanf("%lld",&q);
        if((q%g+g)%g==0&&q%2==0)puts("Yes");
        else puts("No");
    }
    return 0;
}
选球游戏
题目描述
华华和秀秀在玩游戏。在他们面前有!个球排成一排，从左到右按 1 到!编号。每个球有一
个可正可负的权值。 每一轮， 秀秀会选定一个区间[Math Processing Error]，将编号在这个区间内的所有球的权值
加上一个值[Math Processing Error]， 或者将编号在这个区间内的所有球的权值都设为其相反数。 华华则需从这!个球
中选出k个球来，他的得分为这k个球的权值的乘积。
华华每次都能快快地找出得分最优的选球方案来。秀秀想了想，决定提升游戏难度。她每
次会选定一个区间[Math Processing Error],然后询问华华在这个区间内选出[Math Processing Error]个球的所有方案的得
分之和。
这下可把华华难倒了，于是华华找到了聪明的你。你能帮帮他嘛？
由于所有方案的得分之和可能很大，你只需要输出得分之和对[Math Processing Error]取模
的结果（负数请加上[Math Processing Error]变成非负数）即可。

输入格式
从文件game.in 中读入数据。
输入第一行包含两个正整数!,1，分别表示球的个数和秀秀的操作条数。
接下来一行包含!个空格隔开的整数，表示每个球初始的权值。
接下来1行，每行表示秀秀的一个操作。
若该行形如“[Math Processing Error]”，则表示秀秀将编号属于[Math Processing Error]的所有球的权值都加上了c；
若该行形如“[Math Processing Error]”，则表示秀秀将编号属于[Math Processing Error]的所有球的权值都置为了其相反数；
若该行形如“[Math Processing Error]”，则表示华华需要回答从[Math Processing Error]中选出k个球的所有取球方案的得分之和。

输出格式
输出文件到[Math Processing Error]中。
对于秀秀宝宝的每一个询问操作，输出一行，表示该询问的答案。

样例
10 9
3 6 7 4 6 1 6 7 2 6
3 5 7 3
1 1 7 -9
1 2 3 5
3 2 6 1
2 5 8
3 5 7 3
2 2 3
3 1 10 2
3 1 2 2

36
999999996
72
999999885
12
【样例说明】
第一个询问：[Math Processing Error]
第二个询问：
询问前各个球的权值为：[Math Processing Error]
[Math Processing Error]
[Math Processing Error]
第三个询问：
询问前各个球的权值为：[Math Processing Error]
[Math Processing Error]
【子任务】
子任务会给出部分测试数据的特点。如果你在解决题目中遇到了困难，可以尝试只解决一
部分测试数据。每个测试点的规模及特点如下表：



#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long 
inline int read() {
    int x=0,f=1;
    char cc=getchar() ;
    while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();};
    while(cc<='9'&&cc>='0')x=x*10+cc-'0',cc=getchar();return x*f;
}
const int maxn = 0007;
const int mod = 1000000007;
int n,m;
LL tree[maxn<<2][15],a[maxn],lazy1[maxn<<2],lazy2[maxn<<2];
LL C[maxn][25];
inline void merge(int rt) 
{
    for(int i=0;i<=10;++i) 
    {
        tree[rt][i]=0;
        for(int j=0;j<=i;j++) 
            tree[rt][i]=(tree[rt][i]+tree[rt<<1][j]*tree[rt<<1|1][i-j]%mod)%mod;
    }
}
void update(int l,int r,int rt,int w) 
{
    int len=(r-l)+1;
    LL tmp[11];
    for(int i=0;i<=10;i++)tmp[i]=tree[rt][i]%mod;
    for(int i=1;i<=10;i++) 
    {
        tree[rt][i]=0;
        LL t=1;
        for(int j=0;j<=i;++j) 
        {
            LL tt=tmp[i-j]%mod*C[len-(i-j)][j]%mod*t%mod;
            tree[rt][i]=(tree[rt][i]+tt)%mod;
            t=(t%mod)*(w%mod)%mod;
        }
    }
    return ;
} 
void pushdown(int l,int r,int rt) 
{
    int mid=(l+r)>>1;
    if(lazy1[rt]) 
    {
        if(lazy2[rt<<1])lazy1[rt<<1]=(lazy1[rt<<1]+mod-lazy1[rt])%mod;
        else lazy1[rt<<1]=(lazy1[rt<<1]+lazy1[rt])%mod;
        if(lazy2[rt<<1|1])lazy1[rt<<1|1]=(lazy1[rt<<1|1]+mod-lazy1[rt])%mod;
        else lazy1[rt<<1|1]=(lazy1[rt<<1|1]+lazy1[rt])%mod;
        update(l,mid,rt<<1,lazy1[rt]);
        update(mid+1,r,rt<<1|1,lazy1[rt]);
        lazy1[rt]=0;
    }
    if(lazy2[rt])
     {
        for(int i=1;i<=10;i+=2) 
        {
            tree[rt<<1][i]=mod-tree[rt<<1][i];
            tree[rt<<1|1][i]=mod-tree[rt<<1|1][i];//翻转 
        }
        lazy2[rt]=0;
        lazy2[rt<<1]^=1;
        lazy2[rt<<1|1]^=1;
    }
}
void build(int l,int r,int rt) 
{
    if(l==r) 
    {
        for(int i=0;i<=10;i++)tree[rt][i]=0;
        tree[rt][0]=1;
        tree[rt][1]=(a[l]%mod+mod)%mod;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    merge(rt);
}
void modify1(int l,int r,int rt,int tl,int tr,int tw) 
{
    if(tl<=l&&tr>=r) 
    {
        if(lazy2[rt])lazy1[rt]=(lazy1[rt]+mod-tw)%mod;//有反转标记时减去 
        else lazy1[rt]=(lazy1[rt]+tw)%mod;
        update(l,r,rt,tw);return ;
    }
    pushdown(l,r,rt);
    int mid=(l+r)>>1;
    if(tl<=mid)modify1(l,mid,rt<<1,tl,tr,tw);
    if(tr>mid)modify1(mid+1,r,rt<<1|1,tl,tr,tw);
    merge(rt);
    return ;
}

void modify2(int l,int r,int rt,int tl,int tr) 
{
    if(tl<=l&&tr>=r) 
    {
        for(int i=1;i<=10;i+=2)tree[rt][i]=mod-tree[rt][i];//反转操作
        lazy2[rt]^=1;
        return ;
    }
    pushdown(l,r,rt);
    int mid=(l+r)>>1;
    if(tl<=mid)modify2(l,mid,rt<<1,tl,tr);
    if(tr>mid)modify2(mid+1,r,rt<<1|1,tl,tr);
    merge(rt);
}
struct Node{
    LL f[14];
};
Node calc(Node lc,Node rc) 
{
    Node o;
    o.f[0]=1;
    for(int i=1;i<=10;i++) 
    {
        o.f[i]=0;
        for (int j=0;j<=i;j++)
            o.f[i]=(o.f[i]+lc.f[j]*rc.f[i-j]%mod)%mod;
    }
    return o;
}
Node query(int l,int r,int rt,int tl,int tr) 
{
    if(tl<=l&&tr>=r) 
    {
        Node a;
        for(int i=0;i<=10;++i)a.f[i]=tree[rt][i];
        return a;
    }
    int mid=(l+r)>>1;
    pushdown(l,r,rt);
    if(tr<=mid)return query(l,mid,rt<<1,tl,tr);
    if(tl>mid)return query(mid+1,r,rt<<1|1,tl,tr);
    Node lc=query(l,mid,rt<<1,tl,tr);
    Node rc=query(mid+1,r,rt<<1|1,tl,tr);
    return  calc(lc,rc);
}

int main () 
{
    n=read(),m=read();
    C[0][0]=1;
    for (int i=1;i<=n;i++) 
    {
        C[i][0]=1;
        for (int j=1;j<=10;j++) 
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    for(int id,a,b,c;m--;) 
    {
        id=read(),a=read(),b=read();
        if(id==1) 
        {
            c=read();modify1(1,n,1,a,b,c);
        }
        else if(id==2) 
        {
            modify2(1,n,1,a,b);
        }
        else if(id==3) 
        {
            c=read();
            Node tmp=query(1,n,1,a,b);
            printf("%d\n",(tmp.f[c]+mod)%mod);
        }
    }
}
/*
10 9
3 6 7 4 6 1 6 7 2 6
3 5 7 3
1 1 7 -9
1 2 3 5
3 2 6 1
2 5 8
3 5 7 3
2 2 3
3 1 10 2
3 1 2 2
36
999999996
72
999999885
12
*/
std：当然不是我写的QAQ

#include <cstdio>
#include <cstdlib>
#define MOD 1000000007
#define N 100005
typedef long long LL; 
using namespace std;
struct Node {
    LL f[11];
}node[N * 4];
LL a[N], lazy1[N * 4];
bool lazy2[N * 4];
LL C[N][11];

Node merge(Node lc, Node rc) {
    Node o;
    o.f[0] = 1;
    for (int i = 1; i <= 10; i++) {
        o.f[i] = 0;
        for (int j = 0; j <= i; j++)
            o.f[i] = (o.f[i] + lc.f[j] * rc.f[i - j] % MOD) % MOD;
    }
    return o;
}

void build(int o, int l, int r) {
    if (l == r) {
        for (int i = 0; i <= 10; i++) node[o].f[i] = 0;
        node[o].f[0] = 1;
        node[o].f[1] = (a[l] % MOD + MOD) % MOD;
        return ;
    }
    int mid = (l + r) >> 1;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

void update1(int o, int l, int r, int c) {
    int len = r - l + 1;
    LL ff[11];
    for (int i = 0; i <= 10; i++) ff[i] = node[o].f[i];
    for (int i = 1; i <= 10; i++) {
        node[o].f[i] = 0;
        LL t = 1;
        for (int j = 0; j <= i; j++) {
            LL tmp = ff[i - j] * C[len - (i - j)][j] % MOD * t % MOD;
            node[o].f[i] = (node[o].f[i] + tmp) % MOD;
            t = t * c % MOD;
        }
    }
    return ;
}

void push_down(int o, int l, int r) {
    int mid = (l + r) >> 1;
    if (lazy1[o]) {
        if (lazy2[o * 2])
            lazy1[o * 2] = (lazy1[o * 2] + MOD - lazy1[o]) % MOD;
        else 
            lazy1[o * 2] = (lazy1[o * 2] + lazy1[o]) % MOD;
        if (lazy2[o * 2 + 1])
            lazy1[o * 2 + 1] = (lazy1[o * 2 + 1] + MOD - lazy1[o]) % MOD;
        else 
            lazy1[o * 2 + 1] = (lazy1[o * 2 + 1] + lazy1[o]) % MOD;
        update1(o * 2, l, mid, lazy1[o]);
        update1(o * 2 + 1, mid + 1, r, lazy1[o]);
        lazy1[o] = 0;
    }
    if (lazy2[o]) {
        lazy2[o * 2] ^= 1;
        lazy2[o * 2 + 1] ^= 1;
        for (int j = 1; j <= 10; j += 2) {
            node[o * 2].f[j] = MOD - node[o * 2].f[j];
            node[o * 2 + 1].f[j] = MOD - node[o * 2 + 1].f[j];
        }
        lazy2[o] = 0;
    }
}

void modify1(int o, int l, int r, int ll, int rr, int c) {
    if (ll <= l && rr >= r) {
        if (lazy2[o]) lazy1[o] = (lazy1[o] + MOD - c) % MOD;
        else lazy1[o] = (lazy1[o] + c) % MOD;
        update1(o, l, r, c);
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (ll <= mid) modify1(o * 2, l, mid, ll, rr, c);
    if (rr > mid) modify1(o * 2 + 1, mid + 1, r, ll, rr, c);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

void modify2(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
        for (int i = 1; i <= 10; i += 2) node[o].f[i] = MOD - node[o].f[i];
        lazy2[o] ^= 1;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (ll <= mid) modify2(o * 2, l, mid, ll, rr);
    if (rr > mid) modify2(o * 2 + 1, mid + 1, r, ll, rr);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

Node query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) 
        return node[o];
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (rr <= mid) return query(o * 2, l, mid, ll, rr);
    if (ll > mid) return query(o * 2 + 1, mid + 1, r, ll, rr);
    Node lc = query(o * 2, l, mid, ll, rr);
    Node rc = query(o * 2 + 1, mid + 1, r, ll, rr);
    return merge(lc, rc);
}

int main(int argc, char ** argv) {
    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= 10; j++) 
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    build(1, 1, n); 
    for (int i = 1; i <= m; i++) {

        int l, r, opt;
        scanf("%d%d%d",&opt, &l, &r);
        if (opt == 1) {
            int c;
            scanf("%d", &c);
            c = (c % MOD + MOD) % MOD;
            modify1(1, 1, n, l, r, c);
        }
        else if (opt == 2) {
            modify2(1, 1, n, l, r);
        }
        else {
            int k;
            scanf("%d", &k);
            Node o = query(1, 1, n, l, r);
            printf("%d\n", o.f[k] % MOD);
        }
    }
    return 0;
}
川川的漫步
题目描述
金秋时分，T大的校园里色彩斑斓。校园的景色可以被看成[Math Processing Error]个点，每个点会被赋予一个[Math Processing Error]到[Math Processing Error]之间的整数，
表示这个景点的类型。校园里阡陌交通，大一新生川川第一时刻在景点1.然后他开始随意的漫步，假设某时刻他在第i个景点
，则下一时刻，川川会以概率[Math Processing Error]移动到景点[Math Processing Error]（保证[Math Processing Error]）。在漫步N个时刻之后，川川会
把他所经过的景点类型全部记下来，这样他会得到一个长度为N的数列[Math Processing Error]，[Math Processing Error]中每个数都在[Math Processing Error]到[Math Processing Error]之间。

川川很想研究，他最后得到的数列的概率分布，。假设他所有可能得到的数列为[Math Processing Error]。令
[Math Processing Error]
表示他得到的数列是[Math Processing Error]的概率。

作为能考上[Math Processing Error]大的学生，川川当然知道，[Math Processing Error]，但这对他探究S的概率分布毫无帮助。
现在，请你帮他计算出
[Math Processing Error]

输入格式
第一行两个数[Math Processing Error]和[Math Processing Error]，表示景点个数和川川总共要走的时刻数。接下来[Math Processing Error]行，每行[Math Processing Error]个数，第[Math Processing Error]行第[Math Processing Error]个数字
表示[Math Processing Error]。输入数据保证对任意的[Math Processing Error],[Math Processing Error]。接下来一行一个数，[Math Processing Error]，表示井底那的类型书。
再接下来一行[Math Processing Error]个[Math Processing Error]到[Math Processing Error]之间的数，一次表示每个景点的类型。

输出格式
一行，表示[Math Processing Error]的值，保留九位小数。

样例
2 2
0.5 0.5
0.5 0.5
2
0 1

0.500000000
3 3
0.2 0.4 0.4
1 0 0
1 0 0
2
0 1 1

0.667200000
数据范围
对于[Math Processing Error]的数据，[Math Processing Error]。
对于[Math Processing Error]的数据，[Math Processing Error]。
对于[Math Processing Error]的数据，[Math Processing Error]。

分类: 树形数据结构——线段树,数据结构
好文要顶 关注我 收藏该文    
zzzzx
关注 - 65
粉丝 - 50
+加关注
1 0
? 上一篇：luogu P2659 美丽的序列
? 下一篇：逆序对
posted @ 2017-10-24 16:53 zzzzx 阅读(18) 评论(0) 编辑 收藏
刷新评论刷新页面返回顶部
注册用户登录后才能发表评论，请 登录 或 注册，访问网站首页。
公告
 WRONG!
夜半无人索命来

本博客错误无数，请大佬谨慎驾驶 
 Another 11101001
昵称：zzzzx
园龄：1年5个月
粉丝：50
关注：65
+加关注
<	2018年9月	>
日	一	二	三	四	五	六
26	27	28	29	30	31	1
2	3	4	5	6	7	8
9	10	11	12	13	14	15
16	17	18	19	20	21	22
23	24	25	26	27	28	29
30	1	2	3	4	5	6
搜索

 

 
常用链接
我的随笔
我的评论
我的参与
最新评论
我的标签
我的标签
ZZ(3)
随笔分类
&势能分析(1)
AC自动机&fail树(7)
AtCoder(1)
bitset(1)
Burnside引理与polay定理(2)
bzoj(131)
cdq分治(4)
Codeforces(8)
Dijkstra(3)
Dp of Dp(1)
FFT(3)
hash(3)
KM算法(1)
Link cut tree(7)
loj(13)
lucas定理(1)
NOIP真题(3)
poj(4)
prufer编码(1)
Splay(5)
STL(2)
st表(3)
tarjan(8)
treap(1)
trie字典树(3)
Worth to review(23)
倍增(3)
博弈论(1)
差分约束(5)
单调队列(7)
导数&微/积分(1)
点.树.边.图上的分治(8)
动态规划(107)
动态规划——区间形dp(9)
动态规划——序列dp(15)
杜教筛(1)
队列(3)
二次剩余(1)
二分图匹配(2)
费用流(5)
分块(1)
分数规划(1)
分治——二分答案(10)
概率与期望(16)
高斯消元(7)
后缀数组(6)
基础算法——dfs深搜(21)
基础算法——广搜bfs(9)
计算几何(1)
矩阵乘法(10)
坑坑坑坑坑(6)
模板(3)
模拟退火(5)
莫比乌斯(12)
莫队(5)
欧拉函数(4)
爬坑之路(12)
奇妙的思路(2)
棋盘形dp(1)
群论(3)
容斥(3)
三分法(1)
扫描线(1)
生成函数(4)
树的直径(1)
树链剖分(3)
树形DP(7)
树形数据结构——并查集(19)
树形数据结构——堆(5)
树形数据结构——二叉树(7)
树形数据结构——树状数组(5)
树形数据结构——线段树(35)
数据结构(15)
数论(32)
数论——扩展欧几里得(3)
数论—筛法求素数(7)
数学(53)
四边形不等式优化(2)
搜索——记忆化搜索(4)
算法——分块(1)
算法——分治(3)
算法——贪心(12)
凸函数&&(2)
图论(45)
图论——SPFA(13)
图论——弗洛伊德(12)
图论——邻接表(2)
图论——拓扑排序(7)
图论——最短路(8)
图论——最小生成树(8)
网络流(24)
线段树合并(3)
线性代数(4)
线性规划/单纯形法(1)
线性基(5)
斜率优化(2)
虚树(3)
杂七杂八(11)
栈(10)
中国剩余定理(1)
主席树(10)
组合数学(11)
最大流(6)
左偏树(2)
随笔档案
2018年9月 (19)
2018年8月 (45)
2018年7月 (54)
2018年6月 (33)
2018年5月 (34)
2018年4月 (29)
2018年3月 (16)
2018年2月 (41)
2018年1月 (9)
2017年12月 (37)
2017年11月 (33)
2017年10月 (48)
2017年9月 (6)
2017年8月 (28)
2017年7月 (71)
2017年6月 (65)
2017年5月 (71)
2017年4月 (81)
2017年3月 (49)
相册
7uh(2)
友链！
大佬attack
大佬mjt
大佬SovietPower
大佬wcz
老大lyq
我的另一个博客
233!
最新评论
1. Re:bzoj4456: [Zjoi2016]旅行者
@SovietPower引用每次Dijkstra初始化要O(nm)。。这样真没问题么。。woc我说怎么这么慢...不过还是过了......
--zzzzx
2. Re:bzoj5068: 友好的生物
@Rliffixed...
--zzzzx
3. Re:bzoj5068: 友好的生物
Markdown 炸了,@zzzzx
--Rlif
4. Re:bzoj4456: [Zjoi2016]旅行者
每次Dijkstra初始化要O(nm)。。这样真没问题么。。
--SovietPower
5. Re:bzoj1037: [ZJOI2008]生日聚会Party
@SovietPowerwoc，毒瘤...
--zzzzx
阅读排行榜
1. 任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。(981)
2. 欧拉回路与欧拉路 之 一笔画问题(700)
3. 求有向图的强连通分量个数 之 Kosaraju算法(660)
4. 单词查找树(457)
5. Think twice, code once.(409)
评论排行榜
1. 初雪Diary?(5)
2. 新博客：11101001.com(4)
3. 切比雪夫距离与曼哈顿距离(4)
4. FFT&NTT&多项式相关(4)
5. bzoj5248: [2018多省省队联测]一双木棋(3)
推荐排行榜
1. 图论算法 数据结构模板(5)
2. Think twice, code once.(4)
3. 板子-GOD BLESS ALL OF YOU(3)
4. luogu P1972 [SDOI2009]HH的项链(2)
5. 切比雪夫距离与曼哈顿距离(2)
Copyright ?2018 zzzzx
