// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 70;
int n, t, x;
int siz, lim, sum, minn;
int a[maxn], f[maxn];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int cnt, int sum, int cur) {
	if (sum == siz)
		cnt++, sum = 0, cur = a[1];
	if (cnt == lim) {
		printf("%d\n", siz);
		exit(0);
	}
	for (int i = cur; i >= a[n]; i--)
		if (f[i] && i + sum <= siz) {
			f[i]--;
			dfs(cnt, sum + i, i);
			f[i]++;
			if (sum + i == siz || sum == 0)
				return;
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	t = read();
	for (int i = 1; i <= t; i++) {
		x = read();
		if (x <= 50) a[++n] = x;
	}

	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		f[a[i]]++;
	}

	for (int i = n; i >= 2; i--)
		if (sum % i == 0) {
			lim = i, siz = sum / i;
//			printf(">> %d %d\n", lim, siz);
			dfs(0, 0, a[1]);
		}
	printf("%d\n", sum);
	
	return 0;
}