#include <bits/stdc++.h>
using namespace std;
int cal(char *a) {
	int s = 1;
	for (int i = 0; i < strlen(a); i++)
		s *= a[i] - 'A' + 1;
	return s;
}
int main() {
	char a[10], b[10];
	cin >> a >> b;
	if (cal(a) % 47 == cal(b) % 47)
		printf("GO\n");
	else printf("STAY\n");
	return 0;
} 
