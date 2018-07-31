# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	int n, s = 0, temp;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> temp;
		s += temp; 
	}
	cout << s;
	return 0;
} 
