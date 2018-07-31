#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
char a[maxn], b[maxn], s[maxn], ans[maxn];
int x[300], check[300];
int main() {
	scanf("%s%s%s", a, b, s);
	for (int i = 0; i < strlen(a); i++) {
		if (x[a[i]]) {
			if (x[a[i]] != b[i]) {
				printf("Failed\n");
				return 0;
			}
		}
		else x[a[i]] = b[i];
	}
	for (int i = 'A'; i <= 'Z'; i++)
		if (check[x[i]] || !x[i]) {
			printf("Failed\n");
			return 0;
		} else check[x[i]] = 1;
	for (int i = 0; i < strlen(s); i++) 
		printf("%c", x[s[i]]);
	puts("");
	return 0;
}
