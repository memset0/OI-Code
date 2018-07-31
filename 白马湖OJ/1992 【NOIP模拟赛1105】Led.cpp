#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, a[maxn], b[maxn], num[10][7] = {
	{1, 1, 1, 1, 1, 1, 0}, 
	{0, 0, 0, 0, 1, 1, 0}, 
	{1, 0, 1, 1, 0, 1, 1}, 
	{1, 0, 0, 1, 1, 1, 1}, 
	{0, 1, 0, 0, 1, 1, 1}, 
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 1, 0, 1}, 
	{1, 0, 0, 0, 1, 1, 0}, 
	{1, 1, 1, 1, 1, 1, 1}, 
	{1, 1, 0, 1, 1, 1, 1}};
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%1d", &b[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 7; j++)	
			if (num[a[i]][j] != num[b[i]][j]) cnt++;
	cout << cnt;
	return 0;
}
