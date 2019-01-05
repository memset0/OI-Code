// 这题交上去 UKE 什么鬼啊


#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define LL long long 
#define pii pair<int, int>
#define MP make_pair
#define ls i << 1
#define rs ls | 1
#define md (ll + rr >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define inf 0x3f3f3f3f
#define mod 1000000007
#define N 300010
#define M 400020

int readint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9') && c != '-');
    int ret = c - '0', sgn = 0;
    if(c == '-') sgn = 1, ret = 0;
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    if(sgn) ret = -ret;
    return ret;
}
int ch[N*25][2];  
int rand_val[N*25], key[N*25], sz[N*25];  
int tot, rt[N], a[N], n, m, s[N], id[N];
int creat(int val) {  
    ++tot;  
    ch[tot][0] = ch[tot][1] = 0;  
    rand_val[tot] = rand();  
    key[tot] = val;  
    sz[tot] = 1;  
    return tot;  
}
int cmp(int x, int val) {  
    if(key[x] == val) return -1;  
    return val < key[x]? 0: 1;  
}
void push_up(int x) {  
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;  
}  
void rot(int &x, int d) {  
    int k = ch[x][!d];  
    ch[x][!d] = ch[k][d];  
    ch[k][d] = x;  
    push_up(x);  
    push_up(k);  
    x = k;  
}  
void insert(int &x, int val) {  
    if(x == 0) {  
        x = creat(val);  
        return;  
    }  
    int d = cmp(x, val);  
    if(d == -1)
        d = 1;
    insert(ch[x][d], val);  
    if(rand_val[ch[x][d]] > rand_val[x]) rot(x, d ^ 1);  
    push_up(x);  
}  
void del(int &x, int val) {  
    if(x == 0) return;  
    int d = cmp(x, val);  
    if(d == -1) {  
        if(!ch[x][0]) x = ch[x][1];  
        else if(!ch[x][1]) x = ch[x][0];  
        else {  
            int d2 = rand_val[ch[x][0]] > rand_val[ch[x][1]]? 1: 0;  
            rot(x, d2);  
            del(ch[x][d2], val);  
        }  
    }  
    else del(ch[x][d], val);  
    if(x) push_up(x);  
} 
int kth_mi(int x, int val){
    if(!x) return 0;
    int d = cmp(x, val);
    if(d <= 0)
        return kth_mi(ch[x][0], val);
    return sz[ch[x][0]] + 1 + kth_mi(ch[x][1], val);
}
int kth_mx(int x, int val){
    if(!x) return 0;
    int d = cmp(x, val);
    if(d == -1 || d == 1)
        return kth_mx(ch[x][1], val);
    return sz[ch[x][1]] + 1 + kth_mx(ch[x][0], val);
}
void add(int x, int v){
    for(; x <= n; x += x & -x) s[x] += v;
}
int query(int x){
    int ret = 0;
    for(; x > 0; x -= x & -x) ret += s[x];
    return ret;
}

void build(){
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j += j & -j)
            insert(rt[j], a[i]);
}
void update(int x, int val){
    for(; x <= n; x += x & -x) del(rt[x], val);
}
int sum_mi(int x, int val){
    int ret = 0;
    for(; x > 0; x -= x & -x) ret += kth_mi(rt[x], val);
    return ret;
}
int sum_mx(int x, int val){
    int ret = 0;
    for(; x > 0; x -= x & -x) ret += kth_mx(rt[x], val);
    return ret;
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        tot = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            rt[i] = s[i] = 0;
            id[a[i]] = i;
        }
        LL ans = 0;
        for(int i = n; i > 0; --i){
            ans += query(a[i]);
            add(a[i], 1);
        }
        build();
        while(m--){
            printf("%lld\n", ans);
            int v;
            scanf("%d", &v);
            int L = sum_mx(id[v], v);
            int R = sum_mi(n, v) - sum_mi(id[v]-1, v);
            update(id[v], v);
            ans -= (L + R);
        }
    }
    return 0;
}