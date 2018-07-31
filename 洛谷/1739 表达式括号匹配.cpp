#include <bits/stdc++.h> 
using namespace std;
int main() {
	char c = getchar();
	int cnt = 0;
	while (c != '@') {
		if (c == '(') cnt++;
		if (c == ')') cnt--;
		if (cnt < 0) {
			puts("NO");
			return 0;
		}
		c = getchar();
	}
	if (cnt) puts("NO");
	else puts("YES");
	return 0;
}
