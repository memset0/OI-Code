//筛指数+数论
//#include <bits/stdc++.h> 
//using namespace std;
//const int maxn = 50000;
//int n, b[maxn];
//long long ans = 1;
//int main() {
//	cin >> n; int m = n;
//	for (int i = 2; i * i <= n; i++) 
//		if (!b[i]) {
//			for (int k = i + i; k <= m; k += i)
//				b[k] = 1;
//		}
//	for (int i = 2; i * i <= n; i ++)
//	for (int i = 1; i <= m; i++)
//		ans *= a[i] + 1;
//	cout << ans << endl;
//	return 0;
//}

//暴力方法，时间超限0分 
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, cnt = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++) 
//		if (n % i == 0) cnt++;
//	cout << cnt << endl;
//	return 0;
//}
