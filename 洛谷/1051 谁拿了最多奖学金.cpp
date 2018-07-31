#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Student {
	int prize, paper, gend, gclass;
	char west, leader;
	string name;
} a[maxn], u;
int n, maxx = -1, maxi;
char t;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		u.prize = 0;
		cin >> u.name >> u.gend >> u.gclass >> u.leader >> u.west >> u.paper;
		if (u.gend > 80 && u.paper > 0) u.prize += 8000;
		if (u.gend > 85 && u.gclass > 80) u.prize += 4000;
		if (u.gend > 90) u.prize += 2000;
		if (u.gend > 85 && u.west == 'Y') u.prize += 1000;
		if (u.gclass > 80 && u.leader == 'Y') u.prize += 850;
		a[i] = u;
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i].prize;
		if (a[i].prize > maxx) {
			maxx = a[i].prize;
			maxi = i;
		}
	}
	cout << a[maxi].name << endl << a[maxi].prize << endl << sum << endl;
	return 0;
}

