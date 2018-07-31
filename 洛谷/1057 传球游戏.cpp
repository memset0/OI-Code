#include <bits/stdc++.h> 
using namespace std;
const int maxn = 40;
int bin[maxn];
int find_bin(int m)
{
	int len = 0;
	while (m > 0)
	{
		bin[++len] = m % 2;
		m /= 2;
	}
}
int main()
{
	int n, m, sum = 0, ans;
	cin >> n >> m;
	for (int i = 1; i <= (1 << m); i++)
	{
		find_bin(i); sum = 0;
		for (int i = 1; i <= m; i++)
			if (bin[i] == 1) sum += 1;
			else sum -= 1; 
		if (sum % n == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
