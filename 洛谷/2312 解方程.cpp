#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::c = getchar(), r::m = -1; \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while (false)
namespace r { char c; int m; }
#define M1 100000007
#define M2 99999997
#define M3 99998991
using namespace std;
const int maxn = 110;
const int maxm = 1000010;
int n, m;
long long a1[maxn], a2[maxn], a3[maxn], cnt = 0, ans[maxm];
long long sum;

bool cal(int x) {
    sum = 0;
    for (int i = n; i >= 0; i--)
        sum = ((sum * x) + a1[i] + M1) % M1;
    if (sum) return 1;
    sum = 0;
    for (int i = n; i >= 0; i--)
        sum = ((sum * x) + a2[i] + M2) % M2;
    if (sum) return 1;
    sum = 0;
    for (int i = n; i >= 0; i--)
        sum = ((sum * x) + a3[i] + M3) % M3;
    if (sum) return 1;
    return 0;
}
int main() {
	
//	freopen("equation.in", "r", stdin);
//	freopen("equation.out", "w", stdout);
	
    read(n); read(m);
    for (int i = 0; i <= n; i++) {
    	a1[i] = a2[i] = a3[i];
    	r::c = getchar(), r::m = 0;
    	while (!isnum(r::c) && r::c != '-') r::c = getchar();
    	if (r::c == '-') r::m = 1, r::c = getchar();
    	while (isnum(r::c)) {
    		a1[i] = (a1[i] * 10 + r::c - '0' + M1) % M1;
    		a2[i] = (a2[i] * 10 + r::c - '0' + M2) % M2;
    		a3[i] = (a3[i] * 10 + r::c - '0' + M3) % M3;
    		r::c = getchar();
		}
		if (r::m) {
			a1[i] *= -1;
			a2[i] *= -1;
			a3[i] *= -1;
		}
	}
    
    for (int i = 1; i <= m; i++)
        if (!cal(i)) ans[++cnt] = i;
    
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
