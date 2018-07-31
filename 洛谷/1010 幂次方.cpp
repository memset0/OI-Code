#include <bits/stdc++.h>
using namespace std;
int d[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
string f(int x) {
	if (x == 0) return "0";
	string ret = "";
	int cnt = 0;
	for (int t = 14; t >= 0; t--)
		if (x >= d[t]) {
//			printf(">>> %d %d\n", x, t);
			if (cnt) ret = ret + '+';
			if (t == 1) ret = ret + "2";
			else ret = ret + "2(" + f(t) + ")";
			x -= d[t];
			cnt ++;
		}
	return ret;
}
int main() {
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
