#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long f(int);
int main()
{
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
long long f(int k)
{
	if (k == 0) return 0;
	if (k == 1) return 1;
	if (k == 2) return 2;
	long long s = 0;
	s = f(k - 1) + f(k - 2); 
	return s;
}
