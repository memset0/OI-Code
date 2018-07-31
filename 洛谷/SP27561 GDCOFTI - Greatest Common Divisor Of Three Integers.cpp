#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << __gcd(a, __gcd(b, c));
	return 0;
}
