#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a1, b1, s1;
	int a2, b2, s2;
	int a3, b3, s3;
	cin >> n;
	cin >> a1 >> b1; s1 = ceil((float) n / a1) * b1;
	cin >> a2 >> b2; s2 = ceil((float) n / a2) * b2;
	cin >> a3 >> b3; s3 = ceil((float) n / a3) * b3;
	//cout << s1 << " " << s2 << " " << s3;
	int min = s1;
	if (s2 < min) min = s2;
	if (s3 < min) min = s3;
	cout << min;
	return 0;
}
