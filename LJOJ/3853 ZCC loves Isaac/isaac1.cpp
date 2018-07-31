#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x; 
}

const int maxn = 1000010;
int n, l, r, u, v, ans1, ans2, q[maxn], die[maxn], dis[maxn], ind[maxn];
struct Node {
	int nxt, ind;
	vector < int > pre; 
} a[maxn];

int main1(void) {
	
#ifdef DEBUG
	cout << "=== main1() ===\n";
#endif
	
	memset(die, 0, sizeof(die));
	memset(dis, 0, sizeof(dis));
	for (int i = 1; i <= n; i++)
		ind[i] = a[i].ind;
	
	int ans = 0;
	
	l = 1, r = 0;
	
	for (int i = 1; i <= n; i++)
		if (!a[i].ind)
			q[++r] = i, dis[i] = 1;
	
	for (int i = 1; i <= n; i++)
		cout << ind[i] << " ";
	cout << endl; 
	while (l <= r) {
		u = q[l++];
		v = a[u].nxt;
		ind[v]--;
		if (v == a[v].nxt)
			ind[v]--;
		if (!die[v]) {
			die[v] = 1;
			ans++;
		}
		if (!ind[v]) {
			cout << u << " --> " << v << endl;
			for (int i = 1; i <= n; i++)
				cout << ind[i] << " ";
			cout << endl; 
			u = v;
			dis[u] = 1;
			v = a[u].nxt;
			ind[v]--;
			if (v == a[v].nxt)
				ind[v]--;
			if (!ind[v]) {
				cout << u << " --> " << v << endl; 
				for (int i = 1; i <= n; i++)
					cout << ind[i] << " ";
				cout << endl; 
				dis[v] = 1;
				if (v != a[v].nxt)
					q[++r] = v;
			}
		}
	}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndie = ";
	for (int i = 1; i <= n; i++)
		cout << die[i] << " ";
	cout << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
#endif
	
	for (int i = 1; i <= n; i++)
		if (a[i].nxt == i) {
			dis[i] = 1;
			if (!die[i]) {
				die[i] = 1;
				ans++;
			}
		}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
#endif
	
	for (int i = 1; i <= n; i++)
		if (!dis[i] && die[i]) {
			u = i;
			while (true) {
				while (die[u] && !dis[u]) {
					dis[u] = 1;
					u = a[u].nxt;
				}
				if (dis[u]) break;
				dis[u] = 1;
				u = a[u].nxt;
				if (dis[u]) break;
				if (!die[u]) {
					die[u] = 1;
					ans++;
				}
				u = a[u].nxt;
				if (dis[u]) break;
			}
		}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
#endif
		
	for (int i = 1; i <= n; i++)
		if (!dis[i]) {
			u = i;
			while (true) {
				if (!die[u]) {
					die[u] = 1;
					ans++;
				}
				dis[u] = 1;
				u = a[u].nxt;
				if (dis[u]) break;
				dis[u] = 1;
				u = a[u].nxt;
				if (dis[u]) break; 
			}
		}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
#endif
	
	return ans;
}

int main2(void) {
	
#ifdef DEBUG
	cout << "=== main2() ===\n";
#endif
	
	memset(die, 0, sizeof(die));
	memset(dis, 0, sizeof(dis));
	for (int i = 1; i <= n; i++)
		ind[i] = a[i].ind;
	
	int ans = 0;
	
	l = 1, r = 0;
	
	for (int i = 1; i <= n; i++)
		if (!ind[i]) {
			q[++r] = i;
			dis[i] = 1;
		}
	
	while (l <= r) {
		u = q[l++];
		v = a[u].nxt;
		if (!dis[v]) {
			dis[v] = 1;
			ans++;
			q[++r] = v;
		}
	}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	cout << endl;
#endif
	
	for (int i = 1; i <= n; i++)
		if (i == a[i].nxt && !dis[i]) {
			dis[i] = 1;
			ans++;
		}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	cout << endl;
#endif
	
	for (int i = 1; i <= n; i++)
		if (!dis[i]) {
			dis[i] = 1;
			u = a[i].nxt;
			while (true) {
				if (!die[u]) {
					die[u] = 1;
					ans++;
				}
				dis[u] = 1;
				u = a[u].nxt;
				if (dis[u]) break;
			}
		}
#ifdef DEBUG
	cout << "ans = " << ans << "\ndis = ";
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	cout << endl;
#endif
	
	return ans;
}

int main() {
	
#ifdef DEBUG
	freopen("data.txt", "r", stdin);
#endif
//	freopen("isaac.in", "r", stdin);
//	freopen("isaac.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; i++) {
		 a[i].nxt = read();
		 a[a[i].nxt].ind++;
		 a[a[i].nxt].pre.push_back(i);
	}
	
//	for (int i = 1; i <= n; i++)
//		cout << a[i].pre.size() << " ";
//	cout << endl;
	
	printf("%d %d\n", main1(), main2());
	
	return 0;
}