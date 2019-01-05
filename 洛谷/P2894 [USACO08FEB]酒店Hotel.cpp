// luogu-judger-enable-o2
#include <bits/stdc++.h> 
#define isnum(c) ('0' <= c && c <= '9')
#define read(x) do { \
    x = 0, r_::c = getchar(), r_::m = 0; \
    while (!isnum(r_::c) && r_::c != '-') r_::c = getchar(); \
    if (r_::c == '-') r_::c = getchar(), r_::m = 1; \
    while (isnum(r_::c)) x = x * 10 + r_::c - '0' , r_::c = getchar(); \
    if (r_::m) x = -x; \
} while(false)

namespace r_ { char c; bool m; }
using namespace std;

const int maxn = 50010;
int n, m, x;
bool vis[maxn];

int main(){
    read(n); read(m);
    for (int i = 1; i <= m; i++){
        read(x);
        if (x == 1) {
            int s = 1, t = 1, d, f = 0;
            read(d);
            while (t <= n && vis[t])
                t++;
            s = t;
            while (t <= n && !f) {
                while (t <= n && !vis[t])
                    t++;
                if (t - s >= d){
                    printf("%d\n", s);
                    for (int i = s; i <= s + d - 1; i++)
                        vis[i] = 1;
                    f = 1;
                }
                while (t <= n && vis[t])
                    t++;
                s = t;
            }
            if (!f) printf("0\n");
        }
        else{
            int x, d;
            read(x); read(d);
            for (int i = x; i <= x + d - 1; i++)
                vis[i] = 0;
        }
    }
    return 0;
}