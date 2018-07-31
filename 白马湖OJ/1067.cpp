#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double temp;
	cin >> n;
	cin >> temp;
	double max = temp, min = temp, sum = temp;
	for (int i = 2; i <= n; i++)  
	{
		cin >> temp;
		if(temp > max) max = temp;
		if(temp < min) min = temp;
		sum += temp;
	}
	sum = (sum - max - min) / (n - 2);
	printf("%.2lf", sum);
	return 0;
}
