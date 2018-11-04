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

void output(void);

const int maxn = 610, maxm = 360010;
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, l, r, ux, uy, vx, vy, flag;
int a[maxn][maxn], c[maxn][maxn];
int f[maxm], s[maxm];
bool used[maxm];
char ch;

struct node {
    int x, y;
} now;
std::queue < node > q[2];

#define at(x,y) (((x)-1)*n+(y))

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

int calc(int x, int y) {
    for (int t = 0, i, j; t < 4; t++) {
        i = x + mov[t][0];
        j = y + mov[t][1];
        if (i < 1 || j < 1 || i > n || j > n)
            continue;
        if (!~a[i][j])
            return 1;
    }
    return 0;
}

bool check(int x, int y, int col) {
    if (~a[x][y]) return false;
    // printf("check %d %d %d\n", x, y, col);
    a[x][y] = col;
    bool flag = true; int sum = 0;
    for (int t = 0, i, j; t < 4; t++) {
        i = x + mov[t][0];
        j = y + mov[t][1];
        if (i < 1 || j < 1 || i > n || j > n)
            continue;
        if (!~a[i][j])
            continue;
        int &frm = s[find(at(i, j))];
        frm += calc(i, j) - c[i][j];
        if (a[i][j] != a[x][y] && !frm)
            flag = false;
    }
    for (int t = 0, i, j; t < 4; t++) {
        i = x + mov[t][0];
        j = y + mov[t][1];
        if (i < 1 || j < 1 || i > n || j > n)
            continue;
        if (!~a[i][j])
            continue;
        int &frm = s[find(at(i, j))];
        if (a[i][j] == a[x][y] && !used[find(at(i, j))]) {
//			printf("[%d] ", frm);
            sum += frm;
            used[find(at(i, j))] = 1;
        }
    }
    for (int t = 0, i, j; t < 4; t++) {
        i = x + mov[t][0];
        j = y + mov[t][1];
        if (i < 1 || j < 1 || i > n || j > n)
            continue;
        if (!~a[i][j])
            continue;
        int &frm = s[find(at(i, j))];
        // printf("> %d %d : %d %d : %d\n", a[i][j], a[x][y], calc(i, j), c[i][j], frm);
        frm -= calc(i, j) - c[i][j];
        if (a[i][j] == a[x][y])
            used[find(at(i, j))] = 0;
    }
    sum += calc(x, y);
    if (!sum) flag  = false;
    // printf(">>> %d %d\n", sum, flag);
    a[x][y] = -1;
    return flag;
}

void setup(int x, int y, int col) {
    a[x][y] = col;
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 1; j <= n; j++)
    // 		print(c[i][j]);
    // 	putc('\n');
    // }
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 1; j <= n; j++)
    // 		print(s[find(at(i, j))]);
    // 	putc('\n');
    // }
    for (int t = 0, i, j, f1, f2; t < 4; t++) {
        i = x + mov[t][0];
        j = y + mov[t][1];
        int now = calc(i, j);
        s[find(at(i, j))] += now - c[i][j];
        c[i][j] = now;
        f1 = find(at(i, j));
        f2 = find(at(x, y));
//		printf("setup %d %d %d %d | %d %d %d %d\n", x, y, i, j, f1, f2, a[x][y], a[i][j]);
        if (a[i][j] == a[x][y] && f1 != f2) {
            f[f1] = f2;
            s[f2] += s[f1];
        }
    }
    // printf("setup a[%d][%d] = %d\n", x, y, col);
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 1; j <= n; j++)
    // 		switch (a[i][j]) {
    // 			case -1:
    // 				putc('.');
    // 				break;
    // 			case 0:
    // 				putc('X');
    // 				break;
    // 			case 1:
    // 				putc('O');
    // 				break;
    // 		}
    // 	putc('\n');
    // }
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 1; j <= n; j++)
    // 		print(c[i][j]);
    // 	putc('\n');
    // }
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 1; j <= n; j++)
    // 		print(s[find(at(i, j))]);
    // 	putc('\n');
    // }
}

int main() {
    // freopen("in", "r", stdin);
    
    read(n);
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            f[at(i, j)] = at(i, j);
            s[at(i, j)] = 1;
            c[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            while (ch = getc(), ch != '.' && ch != 'X' && ch != 'O');
//			printf("%c\n", ch);
            switch (ch) {
                case 'X':
                    setup(i, j, 0);
                    break;
                case 'O':
                    setup(i, j, 1);
                    break;
                case '.':
                    q[0].push((node){i, j});
                    q[1].push((node){i, j});
                    break;
            }
        }

    for (int i = 0; true; i ^= 1) {
        flag = 0;
//		printf(">>> %d\n", i);
//		output();
        while (q[i].size()) {
            now = q[i].front(), q[i].pop();;
            if (check(now.x, now.y, i)) {
                print(now.x), print(now.y, '\n');
                setup(now.x, now.y, i);
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("-1 -1");
            return 0;
        }
    }

    return 0;
}

void output() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            print(a[i][j]);
        putc('\n');
    }
        putc('\n');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            print(c[i][j]);
        putc('\n');
    }
        putc('\n');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            print(calc(i, j));
        putc('\n');
    }
        putc('\n');
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            print(find(at(i, j)));
        putc('\n');
    }
        putc('\n');
}
