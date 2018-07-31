#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn], f[3], t[3];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] %= 3;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) t[j] = f[j];
		for (int p = 0; p < 3; p++) {
			if (p == a[i]) f[p] = max(t[p], 1);
			int q = (p - a[i] + 3) % 3;
			if (t[q]) f[p] = max(t[p], t[q] + 1);
		}
//		cout << f[0] << " " << f[1] << " " << f[2] << endl;
	}
	cout << f[0];
	return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 100010;
//int n, a[maxn], f[maxn][3];
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//		a[i] %= 3;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int p = 0; p < 3; p++) {
//			if (p == a[i]) f[i][p] = 1;
//			int q = (p - a[i] + 3) % 3;
//			for (int j = i - 1; j > 0; j--)
//				f[i][p] = max(f[i][p], f[j][q] + 1);
////			f[i][p]++;
//		}
//	}
////	for (int k = 0; k < 3; k++) {
////		for (int i = 1; i <= n; i++)	
////			printf("%d ", f[i][k]);
////		puts("");
////	}
//	int ans = -1;
//	for (int i = 1; i <= n; i++)
//		if(f[i][0] > ans) ans = f[i][0];
//	cout << ans;
//	return 0;
//}
