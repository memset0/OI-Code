// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.06 14:06:24
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int len;
char s[110];

int main() {
	scanf("%s", s), len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] == 'C')
			for (int j = i + 1; j < len; j++)
				if (s[j] == 'F') {
					printf("Yes\n");
					return 0;
				}
	printf("No\n");
	return 0;
}