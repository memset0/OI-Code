#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a,b;
	a = 30 + 27 + n / 3.0;
	b = n / 1.2;
	if (a > b) cout << "Walk";
	else if (a == b) cout << "All";
	else cout << "Bike";
	return 0;
}
