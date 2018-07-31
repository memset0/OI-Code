# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;
int main()
{
	double a,b;
	cin >> a >> b;
	if (abs(a - b) <= 0.00000001) cout << "yes";
	else cout << "no";
	return 0;
}
