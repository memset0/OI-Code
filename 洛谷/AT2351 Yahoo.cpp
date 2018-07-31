#include <bits/stdc++.h> 
using namespace std;
string s;
int y, a, h, o;
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'y') y++;
		else if (s[i] == 'a') a++;
		else if (s[i] == 'h') h++;
		else if (s[i] == 'o') o++;
	if (y && a && h && o == 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
