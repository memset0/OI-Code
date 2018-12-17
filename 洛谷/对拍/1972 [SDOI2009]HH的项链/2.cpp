// luogu-judger-enable-o2
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct Ask{
    int l, r, id;
}ask[200002];
bool my_cmp(Ask a, Ask b){
    return a.r < b.r;
}
int n;
int s[500002];
int ls[500002];
map<int, int> mp;
int c[500002];
int pre[500002];
int ans[500002];
void add(int x, int w){
    for(; x <= n; x += x & (-x))
          c[x] += w;
}
int count(int x){
    int res = 0;
    for(; x; x -= x & (-x))
        res += c[x];
    return res;
}
int main(){
	freopen("data.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &s[i]);
        ls[i - 1] = s[i];
    }
    sort(ls, ls + n);
    int kk = unique(ls, ls + n) - ls;
    for(i = 0; i < kk; i++)
        mp[ls[i]] = i + 1;
    int m;
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &ask[i].l, &ask[i].r);
        ask[i].id = i;
    }
    sort(ask, ask + m, my_cmp);
    int t = 1;
    memset(pre, -1, sizeof(pre));
    for(i = 0; i < m; i++){
        while(t <= ask[i].r){
            if(pre[mp[s[t]]] != -1){
                add(pre[mp[s[t]]], -1);
                add(t, 1);
                pre[mp[s[t]]] = t;
            }
            else{
                add(t, 1);
                pre[mp[s[t]]] = t;
            }
            t++;
        }
        ans[ask[i].id] = count(ask[i].r) - count(ask[i].l - 1);
    }
    for(i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return EXIT_SUCCESS;
}

