#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000010;
const int maxm = 200010;
int n, a, b[maxm];
int main() {
	cin >> n;
	int maxx = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a), b[a]++;
		if (a > maxx) maxx = a;
	}
	long long ans = 0;
	for (int i = 1; i <= maxx / 2; i++)
		if (b[i])
			for (int j = maxx / i * i; j > i; j -= i)
				if (b[j]) {
					ans += (j / i) * b[j] * b[i];
//					cout << (j / i) * b[j] * b[i] << " ";
					break;
				}
	cout << ans << endl;
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 5000010;
//const int maxm = 200010;
//int n, a, b[maxm];
//int main() {
//	cin >> n;
//	int maxx = -1;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a), b[a]++;
//		if (a > maxx) maxx = a;
//	}
//	long long ans = 0;
//	for (int i = 1; i <= maxx / 2; i++)
//		if (b[i])
//			for (int j = maxx / i * i; j > i; j -= i)
//				if (b[j]) {
//					ans += (j / i) * b[j] * b[i];
////					cout << (j / i) * b[j] * b[i] << " ";
//					break;
//				}
//	cout << ans << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 5000010;
//const int maxm = 200010;
//int n, a, b[maxm], c[maxm];
//int main() {
//    cin >> n;
//    int maxx = -1;
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &a), b[a]++;
//        c[a] = i;
//        if (a > maxx) maxx = a;
//    }
//    long long ans = 0;
//    for (int i = 1; i <= maxx / 2; i++)
//        if (b[i])
//            for (int j = maxx / i * i; j > i; j -= i)
//                if (b[j]) {
//                    ans += c[j] * b[j] * b[i];
//                    break;
//                }
//    cout << ans << endl;
//    return 0;
//}
