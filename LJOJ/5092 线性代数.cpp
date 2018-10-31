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

namespace wyl {

const int maxn = 55;

int n, x0, y0, xs, ys, sx, sy, flag;
int a[maxn][maxn], tag[maxn][maxn];

bool error_flag;
std::vector < char > ans;

void locate(int v, int &x, int &y) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == v) {
                x = i, y = j;
                return;
            }
}

void move(char c, bool flag = false) {
    if (error_flag)
        return;
    ans.push_back(c);
    if (c == 'U') {
        if (x0 == 1) error_flag = 1;
        std::swap(a[x0][y0], a[x0 - 1][y0]);
        --x0;
    } else if (c == 'D') {
        if (x0 == n) error_flag = 1;
        std::swap(a[x0][y0], a[x0 + 1][y0]);
        ++x0;
    } else if (c == 'L') {
        if (y0 == 1) error_flag = 1;
        std::swap(a[x0][y0], a[x0][y0 - 1]);
        --y0;
    } else {
        if (y0 == n) error_flag = 1;
        std::swap(a[x0][y0], a[x0][y0 + 1]);
        ++y0;
    }
    if (tag[x0][y0] && !flag) {
//		printf("error : goto a tagged place! : %d %d\n", x0, y0);
        error_flag = 1;
    }
//	printf("=== %c %d ===\n", c, error_flag);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			print(a[i][j]);
//		putc('\n');
//	}
}

void move_straight(int &lx, int &ly) {
    bool moved;
    while (std::max(abs(lx), abs(ly)) > 1) {
//		printf("%d %d %d %d %d %d\n", lx, ly, x0, y0, xs, ys);
        moved = false;
        if (lx > -1 && x0 > 1) move('U'), --lx, moved = 1;
        if (ly > -1 && y0 > 1) move('L'), --ly, moved = 1;
        if (lx < -1 && x0 < n) move('D'), ++lx, moved = 1;
        if (ly < -1 && y0 < n) move('R'), ++ly, moved = 1;
        if (!moved)
            error_flag = 1;
        if (error_flag) {
//			puts("!");
            return;
        }
    }
}

struct pair_around {
    int x, y;
    std::string s;
};

std::queue < pair_around > qq;
int mrk[10][10];

std::string spemove1 = "LDRRUULLDRRDLL";
std::string spemove2 = "URDDLLUURDDRUU";

void move_white(int lx, int ly, int rx, int ry) {
//	printf("move white %d %d %d %d\n", lx, ly, rx, ry);
    if (error_flag)
        return;
#define try_move(x,y,c,d) if(x==lx&&y==ly) move(c), d;
//	putc('[');
    if (std::max(abs(lx), abs(ly)) > 1)
        move_straight(lx, ly);
//	putc(']');
    if (error_flag)
        return;
    if (sy == 1 && ys == 1 && xs == sx - 1 && rx == 1) {
        if (lx == -1 && ly ==  0) move('R'), ++ly;
        if (lx == -1 && ly ==  1) move('D'), ++lx;
        if (lx ==  0 && ly ==  1) {
//			printf("special move\n");
            for (auto it = spemove1.begin(); it != spemove1.end(); it++)
                move(*it, 1);
        }
    } else if (sx == 1 && xs == 1 && ys == sy - 1 && ry == 1) {
        if (lx ==  0 && ly == -1) move('D'), ++lx;
        if (lx ==  1 && ly == -1) move('R'), ++ly;
        if (lx ==  1 && ly == 0) {
//			printf("special move\n");
            for (auto it = spemove2.begin(); it != spemove2.end(); it++)
                move(*it, 1);
        }
    } else {
        memset(mrk, 0, sizeof(mrk));
        while (qq.size())
            qq.pop();
        qq.push(pair_around{lx, ly, ""});
        pair_around u, v;
//		printf("%d %d %d %d\n", lx, ly, rx, ry);
        while (qq.size()) {
            u = qq.front(), qq.pop();
//			printf("%d %d %s\n", u.x, u.y, u.s.c_str());
            for (int i = 0; i < 2; i++) {
                if ((u.x == 1 && u.y == 0) || (u.x == -1 && u.y == 0)) {
                    v.x = u.x;
                    v.y = i ? u.y - 1 : u.y + 1;
                    v.s = u.s + (i ? 'L' : 'R');
                } else if ((u.x == 0 && u.y == 1) || (u.x == 0 && u.y == -1)) {
                    v.x = i ? u.x - 1 : u.x + 1;
                    v.y = u.y;
                    v.s = u.s + (i ? 'U' : 'D');
                } else {
                    v.x = i ? 0 : u.x;
                    v.y = i ? u.y : 0;
                    if (u.x == 1 && u.y == 1)
                        v.s = u.s + (i ? 'U' : 'L');
                    if (u.x == 1 && u.y == -1)
                        v.s = u.s + (i ? 'U' : 'R');
                    if (u.x == -1 && u.y == 1)
                        v.s = u.s + (i ? 'D' : 'L');
                    if (u.x == -1 && u.y == -1)
                        v.s = u.s + (i ? 'D' : 'R');
                }
                if (v.x == rx && v.y == ry) {
//					putc('[');
                    for (auto it = v.s.begin(); it != v.s.end(); it++)
                        move(*it);
//					putc(']');
                    return;
                }
                if (xs + v.x < 1 || ys + v.y < 1 || xs + v.x > n || ys + v.y > n)
                    continue;
                if (tag[xs + v.x][ys + v.y])
                    continue;
                if (mrk[v.x + 2][v.y + 2])
                    continue;
                mrk[v.x + 2][v.y + 2] = 1;
                qq.push(pair_around{v.x, v.y, v.s});
            }
        }
//		printf("error !!! %d %d %d %d\n", lx, ly, rx, ry);
        error_flag = 1;
    }
    if (error_flag) {
//		printf("%d %d %d %d\n", lx, ly, rx, ry);
//		puts("!");
        return;
    }
}

void collect(int v, int xe, int ye) {
    locate(0, x0, y0);
    locate(v, xs, ys);
//	printf("collect %d %d %d\n", v, xe, ye);
    while (xs > xe) {
        move_white(x0 - xs, y0 - ys, -1, 0);
        move('D'), --xs;
        if (error_flag)
            return;
    }
    while (ys > ye) {
        move_white(x0 - xs, y0 - ys, 0, -1);
        move('R'), --ys;
        if (error_flag)
            return;
    }
    while (xs < xe) {
        move_white(x0 - xs, y0 - ys, 1, 0);
        move('U'), ++xs;
        if (error_flag)
            return;
    }
    while (ys < ye) {
        move_white(x0 - xs, y0 - ys, 0, 1);
        move('L'), ++ys;
        if (error_flag)
            return;
    }
    tag[sx][sy] = 1;
}

bool used[10];

int zip2(int a[5][5]) {
    int ret = 0;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            if (!(i == 2 && j == 2))
                ret = ret * 10 + a[i][j];
    return ret;
}

int zip3(int a[5][5]) {
    int ret = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (!(i == 3 && j == 3))
                ret = ret * 10 + a[i][j];
    return ret;
}

void unzip2(int ret, int &x, int &y, int a[5][5]) {
    memset(used, 0, sizeof(used));
    for (int i = 2; i >= 1; i--)
        for (int j = 2; j >= 1; j--)
            if (!(i == 2 && j == 2)) {
                a[i][j] = ret % 10;
                if (!a[i][j])
                    x = i, y = j;
                used[ret % 10] = 1;
                ret /= 10;
            }
    for (int i = 0; i < 4; i++)
        if (!used[i]) {
            a[2][2] = i;
            if (!i)
                x = y = 2;
        }
}

void unzip3(int ret, int &x, int &y, int a[5][5]) {
    memset(used, 0, sizeof(used));
    for (int i = 3; i >= 1; i--)
        for (int j = 3; j >= 1; j--)
            if (!(i == 3 && j == 3)) {
                a[i][j] = ret % 10;
//				printf("%d %d -> %d %d\n", i, j, ret % 10, ret);
                if (!a[i][j])
                    x = i, y = j;
                used[ret % 10] = 1;
                ret /= 10;
            }
    for (int i = 0; i < 9; i++)
        if (!used[i]) {
            a[3][3] = i;
            if (!i)
                x = y = 3;
        }
//	for (int i = 1; i <= 3; i++) {
//		for (int j = 1; j <= 3; j++)
//			print(a[i][j]);
//		putc('\n');
//	}
//	printf("%d %d\n", x, y);
}

std::queue < std::pair < int, std::string > > q;
std::set < int > set;

void bfs2() {
    std::pair < int, std::string > u, v;
    int e, x, y, ex, ey, t[5][5];
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            t[i][j] = (i - 1) * 2 + j - 1;
//	for (int i = 1; i <= 3; i++) {
//		for (int j = 1; j <= 3; j++)
//			 print(t[i][j]);
//		putc('\n');
//	}
    e = zip2(t);
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            t[i][j] = a[i][j];
    q.push(std::make_pair(zip2(t), ""));
    while (q.size()) {
        u = q.front(), q.pop();
		// printf(">> %d %s\n", u.first, u.second.c_str());
        unzip2(u.first, x, y, t);
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    ex = x + 1, ey = y;
                    break;
                case 1:
                    ex = x - 1, ey = y;
                    break;
                case 2:
                    ex = x, ey = y + 1;
                    break;
                case 3:
                    ex = x, ey = y - 1;
                    break;
            }
            if (ex < 1 || ey < 1 || ex > 2 || ey > 2)
                continue;
            std::swap(t[x][y], t[ex][ey]);
            v.first = zip2(t);
            std::swap(t[x][y], t[ex][ey]);
            if (set.count(v.first))
                continue;
            switch (i) {
                case 0:
                    v.second = u.second + 'D';
                    break;
                case 1:
                    v.second = u.second + 'U';
                    break;
                case 2:
                    v.second = u.second + 'R';
                    break;
                case 3:
                    v.second = u.second + 'L';
                    break;
            }
            if (v.first == e) {
                for (auto it = v.second.begin(); it != v.second.end(); it++)
                    ans.push_back(*it);
                return;
            }
            set.insert(v.first);
            q.push(v);
        }
    }
    error_flag = 1;
    return;
}

void bfs3() {
    std::pair < int, std::string > u, v;
    int e, x, y, ex, ey, t[5][5];
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            t[i][j] = (i - 1) * 3 + j - 1;
    e = zip3(t);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            t[i][j] = a[i][j];
//	for (int i = 1; i <= 3; i++) {
//		for (int j = 1; j <= 3; j++)
//			 print(t[i][j]);
//		putc('\n');
//	}
    q.push(std::make_pair(zip3(t), ""));
    while (q.size()) {
        u = q.front(), q.pop();
        unzip3(u.first, x, y, t);
//		if (t[3][3] == 8 && t[3][2] == 7 && t[3][1] == 6 && t[2][3] == 5 && t[2][2] == 4 && t[2][1] == 3) {	
////			printf(">> %d %s\n", u.first, u.second.c_str());
//			for (int i = 1; i <= 3; i++) {
//				for (int j = 1; j <= 3; j++)
//					print(t[i][j]);
//				putc('\n');
//			}
//		}
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    ex = x + 1, ey = y;
                    break;
                case 1:
                    ex = x - 1, ey = y;
                    break;
                case 2:
                    ex = x, ey = y + 1;
                    break;
                case 3:
                    ex = x, ey = y - 1;
                    break;
            }
            if (ex < 1 || ey < 1 || ex > 3 || ey > 3)
                continue;
            std::swap(t[x][y], t[ex][ey]);
            v.first = zip3(t);
            std::swap(t[x][y], t[ex][ey]);
            if (set.count(v.first))
                continue;
            switch (i) {
                case 0:
                    v.second = u.second + 'D';
                    break;
                case 1:
                    v.second = u.second + 'U';
                    break;
                case 2:
                    v.second = u.second + 'R';
                    break;
                case 3:
                    v.second = u.second + 'L';
                    break;
            }
            if (v.first == e) {
                for (auto it = v.second.begin(); it != v.second.end(); it++)
                    ans.push_back(*it);
                return;
            }
            set.insert(v.first);
            q.push(v);
        }
    }
    error_flag = 1;
    return;
}

int main() {
//	freopen("algebra1.in", "r", stdin);
//	freopen("algebra.out", "w", stdout);
    
    read(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            read(a[i][j]);
//			printf("%d %d -> %d\n", i, j, a[i][j]);
        }
//	for (int i = 1; i <= 3; i++) {
//		for (int j = 1; j <= 3; j++)
//			 print(a[i][j]);
//		putc('\n');
//	}
    sx = sy = n, flag = 0;
    for (int i = n * n - 1; i >= 9; i--) {
        collect((sx - 1) * n + sy - 1, sx, sy);
        if (error_flag) break;
        if (flag) --sx; else --sy;
        if (!sx) flag = 0, sx = sy = sy - 1;
        if (!sy) flag = 1, sy = sx, --sx;
    }
    if (error_flag)
        puts("Impossible");
    else {
        if (n >= 3) {
//			for (int i = 1; i <= 3; i++) {
//				for (int j = 1; j <= 3; j++)
//					 print(a[i][j]);
//				putc('\n');
//			}
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    for (int x = 1; x <= 3; x++)
                        for (int y = 1; y <= 3; y++)
                            if (a[i][j] == (x - 1) * n + y - 1)
                                a[i][j] = (x - 1) * 3 + y - 1;
//			for (int i = 1; i <= 3; i++) {
//				for (int j = 1; j <= 3; j++)
//					 print(a[i][j]);
//				putc('\n');
//			}
            bfs3();
        } else if (n == 2) {
            bfs2();
        }
        if (error_flag)
            puts("Impossible");
        else {
            for (auto it = ans.begin(); it != ans.end(); it++)
                putc(*it);
			putc('\n');
        }
    }

    return 0;
}

void rubbish_bin() {
//	if (rx == 1) {
////		if (lx == -1 && ly ==  0) {
////			if (y0 > 1) move('L'), --ly;
////			else move('R'), ++ly;
////		}
////		if (lx == -1 && ly == -1) move('D'), ++lx;
////		if (lx == -1 && ly ==  1) move('D'), ++lx;
////		if (lx ==  0 && ly == -1) move('D'), ++lx;
////		if (lx ==  0 && ly ==  1) move('D'), ++lx;
////		if (lx ==  1 && ly == -1) move('R'), ++ly;
////		if (lx ==  1 && ly ==  1) move('L'), --ly;
//		try_move( 1,  1, 'U', --lx);
//		try_move( 0,  1, 'U', --lx);
//		try_move(-1,  1, 'L', --ly);
//		try_move(-1,  0, 'L', --ly);
//		try_move(-1, -1, 'D', ++lx);
//		try_move( 0, -1, 'D', ++lx);
//		try_move( 1, -1, 'R', ++ly);
//	} else if (ry == 1) {
////		if (lx ==  0 && ly == -1) {
////			if (x0 > 1) move('U'), --lx;
////			else move('D'), ++lx;
////		}
////		if (lx ==  1 && ly == -1) move('R'), ++ly;
////		if (lx == -1 && ly == -1) move('R'), ++ly;
////		if (lx ==  1 && ly ==  0) move('R'), ++ly;
////		if (lx == -1 && ly ==  0) move('R'), ++ly;
////		if (lx ==  1 && ly ==  1) move('U'), --lx;
////		if (lx == -1 && ly ==  1) move('D'), ++lx;
//	} else if (rx == -1) {
////		if (lx ==  1 && ly ==  0) {
////			if (y0 > 1) move('L'), --ly;
////			else move('R'), ++ly;
////		}
////		if (lx ==  1 && ly == -1) move('U'), --lx;
////		if (lx ==  1 && ly ==  1) move('U'), --lx;
////		if (lx ==  0 && ly == -1) move('U'), --lx;
////		if (lx ==  0 && ly ==  1) move('U'), --lx;
////		if (lx == -1 && ly == -1) move('R'), ++ly;
////		if (lx == -1 && ly ==  1) move('L'), --ly;
//		try_move( 1,  1, 'U', --lx);
//		try_move( 0,  1, 'U', --lx);
//		try_move(-1,  1, 'L', --ly);
//		try_move(-1,  0, 'L', --ly);
//		try_move(-1, -1, 'D', ++lx);
//		try_move( 0, -1, 'D', ++lx);
//		try_move( 1, -1, 'R', ++ly);
//	} else {
//		if (lx ==  0 && ly ==  1) {
////			if (x0 > 1) move('U'), --lx;
////			else move('D'), ++lx;
////		}
////		if (lx ==  1 && ly ==  1) move('L'), --ly;
////		if (lx == -1 && ly ==  1) move('L'), --ly;
////		if (lx ==  1 && ly ==  0) move('L'), --ly;
////		if (lx == -1 && ly ==  0) move('L'), --ly;
////		if (lx ==  1 && ly == -1) move('U'), --lx;
////		if (lx == -1 && ly == -1) move('D'), ++lx;
//	}
}

} int main() { return wyl::main(); }