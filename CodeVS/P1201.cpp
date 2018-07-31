# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	int n, temp;
	cin >> n >> temp;
	int min = temp, max = temp;
	for (int i = 2; i <= n; i ++)
	{
		cin >> temp;
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}
	cout << min << " " << max;
	return 0;
}
 
