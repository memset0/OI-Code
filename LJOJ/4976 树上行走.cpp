#include <bits/stdc++.h>
#define ll long long
using namespace std; 
 
const int maxn = 100010, inf = 1e9 + 10;
int n, m, ans, now, len, dis;
char ch, s[maxn];
short a[maxn], b[maxn], c[maxn];
bool tg[maxn];
 
void walk(char *s, short *a, int &n) {
    len = strlen(s), n = 0;
    for (int i = 0; i < len; i++) {
        ch = s[i];
        if (ch == '1') {
            a[++n] = 0;
        } else if (ch == '2') {
            a[++n] = 1;
        } else if (ch == 'U') {
			if (a[n] < 0) {
				a[n - 1] -= ((-a[n] + 1) >> 1);
				a[n] += ((-a[n] + 1) >> 1) << 1;
			} else if (a[n] > 1) {
				a[n - 1] += (a[n] >> 1);
				a[n] -= (a[n] >> 1) << 1;
			}
            n--;
        } else if (ch == 'L') {
			a[n]--;
        } else if (ch == 'R') {
			a[n]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] < 0) {
            a[i - 1] -= ((-a[i] + 1) >> 1);
            a[i] += ((-a[i] + 1) >> 1) << 1;
        } else if (a[i] > 1) {
            a[i - 1] += (a[i] >> 1);
            a[i] -= (a[i] >> 1) << 1;
        }
    }
}
 
void print(string name, short *arr, int length) {
    cout << name << " ";
    for (int i = 1; i <= length; i++)
        printf("%d ", arr[i]);
    puts("");
}
 
bool grt(short *a, short *b) {
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 0;
}
void swp(short *a, short *b) {
    short tmp;
    for (int i = 1; i <= n; i++)
        tmp = a[i], a[i] = b[i], b[i] = tmp;
}
 
int main() {
     
    scanf("%s", s), walk(s, a, n);
    scanf("%s", s), walk(s, b, m);
     
    while (n > m) n--, now++;
    while (m > n) m--, now++;
    if (grt(b, a)) swp(a, b);

    ans = inf;
    for (int i = 1; i <= n; i++) {
        if (a[i] && b[i]) dis <<= 1;
        if (!a[i] && !b[i]) dis <<= 1;
        if (a[i] && !b[i]) dis = (dis << 1) + 1;
        if (!a[i] && b[i]) dis = (dis << 1) - 1;
        if (dis > ans) break;
        else  ans = min(ans, now + dis + ((n - i) << 1));
    }

    printf("%d\n", ans);
 
    return 0;
}