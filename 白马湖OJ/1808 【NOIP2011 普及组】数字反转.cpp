#include<bits/stdc++.h>
using namespace std;
const int maxl = 256;
char t, str[maxl];
int b, i, j;
int main() {
	gets(str);
	i = 0, j = strlen(str);
	while (1) {
		t = str[j - 1];
		if (t != '-' && (!('0' <= t && t <= '9'))) j--;
		else break;
	}
	if (str[i] == '-') b = 1, i++;
	else b = 0;
	while (str[i] == '0') i++;
	while (str[j - 1] == '0') j--;
	if (b && j - 1 > i) cout << '-';
	if (j - 1 < i) cout << 0;
	for (int k = j - 1; k >= i; k--)
		cout << str[k];
	return 0;
}

