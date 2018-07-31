#include <bits/stdc++.h> 
#define isNum(x) ('0'<=x&&x<='9')
using namespace std;
const int maxn = 200010;
int read(); 
int n, ans, a[maxn], val[maxn], pos[maxn];
bool dis[maxn];
int main() {
    memset(val, 0, sizeof(val));
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ans = n;
	int i, j, k;
	for (int i = 1; i <= n; i++) 
		if (!dis[i]) {
			k = 1, dis[i] = 1, j = a[i];
			while (!dis[j]) k++, dis[j] = 1, j = a[j];
			ans = max(ans, k);
		}
    printf("%d\n", &ans);
    return 0;
}

char get; int ret;
int read() {
    get = getchar(), ret = 0;
    while (!isNum(get)) get = getchar();
    while (isNum(get)) {
        ret = ret * 10 + get - '0';
        get = getchar();
    }
    return ret;
}
