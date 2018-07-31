#include<bits/stdc++.h>
using namespace std;
char str[100];
int x[10] = {0, 2, 3, 4, 6, 7, 8, 9, 10};
int s = 0, k;
int main() {
	gets(str);
	for (int i = 0; i < 9; i++)
		s += (str[x[i]] - '0') * (i + 1); 
	if (str[12] == 'X') k = 10; 
	else k = str[12] - '0';
	s %= 11;
	if (s == k) {
		cout << "Right" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < 12; i++)
			cout << str[i];
		if (s == 10) cout << "X";
		else cout << s;
	}
	return 0;
}

