#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int hep[10010], len = 1;
int put(int n)
{
	int j = len;
	hep[len++] = n;
	while (hep[j] < hep[j/2] && j > 1) 
		swap(hep[j], hep[j/2]), j /= 2;
}
int get()
{
	int ret = hep[1], i, j = 1;
	hep[1] = hep[--len];
	while (j*2 < len)
	{
		if (hep[j*2] < hep[j*2+1]) i = j * 2;
		else i = j * 2 + 1;
		if (hep[j] > hep[i]) swap(hep[i], hep[j]), j = i;
		else return ret;
	}
	return ret;	
}
int main()
{
	int n, temp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &temp), put(temp);
	int a, b, ans = 0;
	for (int i = 1; i < n; i++)
	{
		a = get();
		b = get();
		//printf("%d %d\n", a, b);
		ans += a + b;
		put(a + b);
	}
	printf("%d", ans);
	return 0;
} 
