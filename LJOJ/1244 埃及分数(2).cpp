#include <bits/stdc++.h>
using namespace std;
int a, b, lim, ans = -1;
bool found = false;
typedef pair < long long, long long > pr;

//inline pr red(pr u) {
//	for (vector < int > ::iterator it = prime::prime.begin(); it != prime::prime.end(); it++)
//		if (u.first % (*it) == 0 && u.second % (*it) == 0)
//			u.first /= (*it), u.second /= (*it);
//		else if ((*it) > u.second) break;
//	return u;
//}
inline pr red(pr u) {
	int Gcd = __gcd(u.first, u.second); 
	return pr(u.first / Gcd, u.second / Gcd);
}
inline pr sub(pr a, pr b) {
	return red(pr(a.first * b.second - a.second * b.first, a.second * b.second));
}
inline pr div(pr a, pr b) {
	return red(pr(a.first * b.second - a.second * b.first, a.second * b.second));
}
inline int round(pr u) {
	return u.first / u.second;
}
inline void print(pr u) {/*pair < long long, long long > */
	printf("%d %d ==> %.2lf\n", u.first, u.second, u.first / (double)u.second);
}

void DFS(pr u, int end, int step) {
	if (u.first == 0) {
		ans = step;
		found = 1;
		cout << 0;
		return ;
	}
	if (step >= lim)
		return ;
	for (int i = end + 1; !found; i++) {
		pr v = sub(u, pr(1, i));
		cout << lim << " " << step << " ";
		print(v);
		if (v.first <= 0 || v.second <= 0)
			continue;
		if ((step + round(div(u, pr(1, i + 1)))) > lim || (i >= ans && ans != -1))
			return;
		DFS(v, i, step + 1);
	}
}
	
int main() {
	freopen("INPUT", "r", stdin);
	scanf("%d%d", &a, &b);
	for (lim = 1; !found; lim++) { 
		DFS(make_pair(a, b), 1, 0);
	}
	return 0;
}
