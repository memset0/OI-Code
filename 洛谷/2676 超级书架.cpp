// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int n, h, t, cnt;
priority_queue <int> que;

int main() {
    // freopen("INPUT", "r", stdin);
    // freopen("OUTPUT", "w", stdout);

    
    n = read(), h = read();
    for (int i = 1; i <= n;i++) {
        scanf("%d",&t);
        que.push(t);
    }
    while (h > 0) {
        h -= que.top();
        que.pop();
        cnt++;
    }
    printf("%d", cnt);

    return 0;
}