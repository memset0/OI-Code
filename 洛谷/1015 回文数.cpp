#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int k, ans, a[maxn], b[maxn];
char n;
bool fnd = false;
int main() {
    scanf("%d ", &k);
    while (scanf("%c", &n) != EOF) {
    	if ('A' <= n && n <= 'Z') a[++a[0]] += n - 'A' + 10;
    	else if ('0' <= n && n <= '9') a[++a[0]] += n - '0';
    	else break;
	}
	
    while (1) {
    	if (ans >= 30) break;
        fnd = true;
        for (int i = 1; i <= a[0] / 2; i++)
            if (a[i] != a[a[0] - i + 1]) {
                fnd = false;
                break;
            }
        if (fnd) break;
        ans ++;
        for (int i = 1; i <= a[0]; i++)
            b[i] = a[a[0] - i + 1];
        for (int i = 1; i <= a[0]; i++) {
            a[i] += b[i];
            a[i + 1] += a[i] / k;
            a[i] %= k;
        }
        if (a[a[0] + 1]) a[0]++;
//		for (int i = 1; i <= a[0]; i++)
//			printf("%d", a[i]);
//		puts("");
    }
    if (ans >= 30) printf("Impossible!");
	else printf("STEP=%d\n", ans);
    return 0; 
}
