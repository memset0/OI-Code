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
using namespace std;

const int maxm = 110;
int n, m, s, t, dt, ans = -1, a[maxm];
int f[100010];
set < int > st;
#define update(k,v) \
	if (f[k] == -1) f[k] = v; \
	else if (f[k] > v) f[k] = v

int main() {
	memset(f, -1, sizeof(f));
	
	read(n); read(s); read(t); read(m);
	for (int i = 1; i <= m; i++)
		read(a[i]);
	
	if (s != t) {
		sort(a + 1, a + m + 1);
//		for (int i = 1; i <= m; i++)
//			printf("%d ", a[i]);
//		puts("");
		for (int i = 1; i <= m; i++)
			if (a[i] - a[i - 1] > t + s) {
				dt = a[i] - a[i - 1] - t - s;
				for (int j = i; j <= m; j++)
					a[j] -= dt;
	//			for (int i = 1; i <= m; i++)
	//				printf("%d ", a[i]);
	//			puts("");
			}
		if (n - a[m] > t + s)
			n = a[m] + t + s;
		for (int i = 1; i <= m; i++)
			st.insert(a[i]);
//		for (int i = 1; i <= m; i++)
//			printf("%d ", a[i]);
//		puts("");
		
//		cout << endl << n << endl << endl;
			
		f[0] = 0;
		for (int i = 0; i < n; i++) 
			if (f[i] != -1) {
				if (st.count(i)) {
					for (int j = s; j <= t; j++)
						update(i + j, f[i] + 1);
				} else {
					for (int j = s; j <= t; j++)
						update(i + j, f[i]);
				}
			}
//		for (int i = 0; i < n + t; i++)
//			printf("%d ", f[i]);
			
		ans = -1;
		for (int i = n; i < n + t; i++)
			if (ans == -1 || (f[i] < ans) && f[i] != -1)
				ans = f[i];
		printf("%d\n", ans);
	} else {
		ans = 0;
		for (int i = 1; i <= m; i++)
			if (a[i] % s == 0)
				ans ++;
		printf("%d\n", ans);
	}
	return 0;
}



//#include <bits/stdc++.h>
//#define isnum(x) ('0' <= x && x <= '9')
//#define read(x) do { \
//	x = 0, r::c = getchar(), r::m = 1; \
//	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
//	if (r::c == '-') r::c = getchar(), r::m = -1; \
//	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
//	x *= r::m; \
//} while (false) 
//namespace r { char c; int m; }
//using namespace std;
//
//const int maxm = 110;
//const int FL = 1000;
//int n, m, s, t, ans = -1, a[maxm];
//int ff[FL];
//#define f(i) ff[ (i) % FL ]
//#define update(k,v) \
//	if (f(k) == -1) f(k) = v; \
//	else if (f(k) > v) f(k) = v
//
//int main() {
//	memset(ff, -1, sizeof(ff));
//	
//	read(n); read(s); read(t); read(m);
//	for (int i = 1; i <= m; i++)
//		read(a[i]);
//	
//	f(0) = 0;
//	for (int i = 0; i < n; i++)
//		if (f(i) != -1) {
//			for (int j = s; j <= t; j++)
//				if (1)
//					update(i + j, f(i) + 1);
//				else
//					update(i + j, f(i));
////			printf("%d : %d\n", i, f(i));
//			f(i) = -1;
//		}
//		
//	for (int i = n; i < n + t; i++)
//		if (ans == -1 || f(i) < ans)
//			ans = f(i);	
//	printf("%d\n", ans);
//	
//	return 0;
//}
