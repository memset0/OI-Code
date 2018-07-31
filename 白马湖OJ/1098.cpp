#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int sum = 0, temp = 0, n3;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if(i == 3) {cin >> n3; sum += n3; continue;}
		cin >> temp;
		sum += temp;
	}
	cout << sum << endl << n3 << endl;
	return 0;
} 
