#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const long N = 1000015;
bool mark[1000015];
int boo[2015];
int ans = 0, ans_l, ans_r, n;
int find_prime(long n)
{
	mark[1] = 1; mark[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
}
int fun(int a, int b, int s)
{
	if (a > b || b > n) return 0;
	fun(a + 1, b, (s - boo[a]));
	fun(a, b + 1, (s + boo[b + 1]));
	if (mark[s] == 1) return 0;
	if (s > ans) {ans = s; ans_l = a; ans_r = b;}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &boo[i]);
	find_prime(N);
	fun(1, 1, boo[1]);
	//printf("%d\n", mark[1]);
	printf("%d %d %d", ans_l, ans_r, ans);
	return 0;
}
