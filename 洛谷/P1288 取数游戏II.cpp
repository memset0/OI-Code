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

const int maxn = 30;

int n, a[maxn];

int main() {
    
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int flag = 1; flag != -3; flag -= 2) {
        int u = flag == 1 ? 1 : n, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[u]) break;
            cnt++;
            u += flag;
            if (u > n) u = 1;
            if (u < 1) u = n;
        }
        if (cnt & 1) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}
