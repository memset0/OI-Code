// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 20010;

int n, t, ans;
int a[maxn], sg[maxn];

int get_sg(int x, int y) {
    if ((x & 1) && (y & 1))
        return 0;
    return 1 + get_sg((x + 1) >> 1, (y + 1) >> 1);
}

int main() {
	// freopen("1.in", "r", stdin);
 //    freopen("1.out", "w", stdout);

    for (read(t); t--; ) {
        read(n);
        for (int i = 1; i <= n; i++)
            read(a[i]);
        for (int i = 1; i <= (n >> 1); i++)
            sg[i] = get_sg(a[(i << 1) - 1], a[i << 1]);
        // for (int i = 1; i <= (n >> 1); i++)
        //     print(sg[i]);
        // putc('\n');
        ans = 0;
        for (int i = 1; i <= (n >> 1); i++)
            ans ^= sg[i];
        puts(ans ? "YES" : "NO");
    }

	return 0;
}

// int calc(int x, int y) {
//     if (vis[x][y]) return f[x][y];
//     std::set < int > set;
//     set.clear();
//     for (int i = 1; i < x; i++)
//         set.insert(calc(i, x - i));
//     for (int i = 1; i < y; i++)
//         set.insert(calc(y - i, i));
//     int ans = 0;
//     for (std::set < int > ::iterator it = set.begin(); it != set.end(); it++)
//         if (*it == ans) ++ans;
//         else break;
//     // printf("%d %d : ", x, y);
//     // for (std::set < int > ::iterator it = set.begin(); it != set.end(); it++)
//     //     print(*it);
//     // putc('\n');
//     f[x][y] = ans;
//     vis[x][y] = 1;
//     return ans;
// }

// void test() {
//     vis[1][1] = 1;
//     // for (int i = 1; i <= 10; i++)
//     //     for (int j = 1; j <= 10; j++)
//     //         calc(i, j);
//     for (int i = 1; i <= 20; i++) {
//         for (int j = 1; j <= 20; j++)
//             printf("%3d", calc(i * 8, j * 8));
//         putc('\n');
//     }
// }