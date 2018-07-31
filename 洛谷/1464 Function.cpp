#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
long long f[maxn][maxn][maxn];
long long w(long long x, long long y, long long z) {
	if (x <= 0 || y <= 0 || z <= 0) return 1;
	if (x > 20 || y > 20 || z > 20) return w(20, 20, 20);
	if (f[x][y][z]) return f[x][y][z];
	if (x < y && y < z) return f[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	else return f[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
}
int main() {
	long long x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	while (x != -1 || y != -1 || z != -1) {
		printf("w(%lld, %lld, %lld) = %lld\n", x, y, z, w(x, y, z));
		scanf("%lld%lld%lld", &x, &y, &z);
	}
}

