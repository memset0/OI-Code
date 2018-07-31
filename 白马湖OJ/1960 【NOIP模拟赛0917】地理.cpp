#include <bits/stdc++.h>
#define way x21
using namespace std;
const int maxn = 110;
const int maxm = 110;
const int maxX = 10010;
int n, m, ux, uy, vx, vy, minn, r[maxm], c[maxm];
long long ans = 0;
void way(int vx, int vy) {
	int x = max(abs(vx - ux), abs(vy - uy));
	if (x < minn) minn = x;
	return ;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)	
		scanf("%d%d", &r[i], &c[i]);
	for (int i = 2; i <= m; i++) {
		ux = r[i-1]; uy = c[i-1];
		vx = r[i]; vy = c[i];
		minn = maxX;
		way(vx, vy);
		way(vx, vy+n);
		way(vx, vy-n);
		way(vx+n, vy);
		way(vx-n, vy);
		way(vx+n, vy+n);
		way(vx+n, vy-n);
		way(vx-n, vy+n);
		way(vx-n, vy-n);
		ans += minn; 
	}
	cout << ans;
}
