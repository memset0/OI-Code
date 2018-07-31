#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cmath>
using namespace std;
int n_arr[100];
int m_arr[100];
int main()
{
	int n, m, ans;
	bool bo;
	scanf("%d", &n);
	while (n < 987654321)
	{
		m = ++n;
		for (int i = 0; i <= 9; i++) m_arr[i] = 0;
		while (m > 0)
		{
			m_arr[m % 10]++;
			m /= 10;
		}
		if (m_arr[0] != 0) continue;
		bo = true;
		for (int i = 1; i <= 9; i++)
			if (m_arr[i] > 1)
			{
				bo = false;
				break;
			}
		if (!bo) continue;
		ans = n;
		break;
	}
	printf("%d", ans);
	return 0;
}


