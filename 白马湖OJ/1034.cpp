#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, s;
	cin >> a >> b;
	s = a  * 0.7 + b * 0.3;
	if (s >= 90) cout << "A";
	else if (s >= 80) cout << "B";
	else if (s >= 70) cout << "C";
	else cout << "D";
	return 0;
}
