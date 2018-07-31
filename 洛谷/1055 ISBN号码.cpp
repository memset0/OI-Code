#include <bits/stdc++.h>
using namespace std;
int f[9] = {0, 2, 3, 4, 6, 7, 8, 9, 10};
int main() {
	char a[100];
	cin >> a;
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += (a[f[i]] - '0') * (i + 1);
	sum %= 11;
	if (a[12] == 'X' && sum == 10 || a[12] != 'X' && sum + '0' == a[12])
		cout << "Right" << endl;
	else {
		for (int i = 0; i < 12; i++)
			printf("%c", a[i]);
		if (sum == 10) printf("X\n");
		else printf("%c\n", sum + '0');
	}
	return 0;
}
