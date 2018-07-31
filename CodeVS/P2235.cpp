# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	int i, s;
	float f, temps;
	cin >> i >> f;
	temps = i * f / 100.0;
	if ((temps-(int)temps) < 0.5) s = s;
	else temps = temps + 1;
	s = (int)temps * 10;
	cout << s;
	return 0;
}
