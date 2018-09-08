#include <bits/stdc++.h>

int read() {
    char c = getchar(); bool m = false; int x = 0;
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; return x;
}

const int maxn = 7e6 + 1e5 + 10;

int n, m, q, u, v, t;
int a[maxn], b[maxn], c[maxn];
int lena, lenb, lenc;
int nowa, nowb, nowc;
int front, left, right;

bool cmp(int a, int b) {
    return a > b;
}

int top() {
    int front, flag = 0;
    if (nowa <= lena && (!flag || a[nowa] > front))
        flag = 1, front = a[nowa];
    if (nowb <= lenb && (!flag || b[nowb] > front))
        flag = 2, front = b[nowb];
    if (nowc <= lenc && (!flag || c[nowc] > front))
        flag = 3, front = c[nowc];
//	printf("> %d : %d %d %d\n", front, a[nowa], b[nowb], c[nowc]);
    if (flag == 1) nowa++;
    else if (flag == 2) nowb++;
    else nowc++;
    return front;
}

int main() {
//	freopen("testdata.in", "r", stdin);
    n = read(), m = read(), q = read();
    u = read(), v = read(), t = read();
//	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
    
    lena = n, nowa = nowb = nowc = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + n + 1, cmp);
    
    for (int i = 1; i <= m; i++) {
        front = top() + (i - 1) * q;
        if (i % t == 0) printf("%d ", front);
        left = front * (long long)u / v;
        right = front - left;
//		printf(">> %d %d %d\n", front, left, right);
        if (left > right) std::swap(left, right);
        b[++lenb] = left - i * q;
        c[++lenc] = right - i * q;
    }
    putchar('\n');
    for (int i = 1; i <= n + m; i++) {
        front = top() + m * q;
        if (i % t == 0) printf("%d ", front);
    }
    putchar('\n');
    
    return 0;
}