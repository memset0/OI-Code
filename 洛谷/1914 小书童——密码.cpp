#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main() {
	cin >> k >> s;
	for (int i = 0; i < s.length(); i++) {
		s[i] = ((s[i] + k - 'a') % 26 + 'a');
	}
	cout << s << endl;
}
