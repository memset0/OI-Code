#include <bits/stdc++.h>
using namespace std;
const int int_max = 10000000;
const int int_min = -10000000;
const int maxn = 1010 * 2;
int n, l, r, a[maxn], sum[maxn];
long long f[maxn][maxn];
int main() {
    cin >> n;
    for (int i = 1; i <= n * 2; i++)	
        for (int j = 1; j <= n * 2; j++)	
            f[i][j] = int_max;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            l = j, r = i + j;
            if (r > 2 * n) break;
            for (int k = l + 1; k <= r; k++) {
                f[l][r] = min(f[l][r], f[l][k - 1] + f[k][r] + sum[r] - sum[l - 1]);
            }
        }
        
    }
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d|%d ", f[i][j].min, f[i][j].max);
//		}
//		puts("");
//	}
    long long ans = f[1][n];
    for (int i = 2; i <= n + 1; i++)
        ans = min(ans, f[i][i + n - 1]);
    printf("%lld", ans);
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1010;
//int n, i, j, k;
//long long a[maxn], s[maxn], f[maxn][maxn];
//long long sum(int i, int j) {
//	return s[j] - s[i - 1];
//}
//int main() {
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//	for (i = 1; i <= n; i++)
//		s[i] = s[i - 1] + a[i];
//	for (int len = 2; len <= n; len++) {
//		for (i = 1; i + len - 1<= n; i++) {
//			j = i + len - 1;
//			f[i][j] = min(f[i][j - 1], f[i + 1][j]) + sum(i, j);;
//		}
//	}
////	for (int i = 1; i <= n; i++) {
////		for (int j = 1; j <= n; j++)	
////			printf("%d ", f[i][j]);
////		puts("");
////	}
//	printf("%lld\n", f[1][n]);
//	return 0;
//}
