#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[1015];
int main()
{
	int n;
	int sum = 0, temp = 0, n3;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int k;
	cin >> k; 
	cout << sum << endl << a[k] << endl;
	return 0;
} 
