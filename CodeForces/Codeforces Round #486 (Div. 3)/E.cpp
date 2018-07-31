#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, r::c = std::getchar(), r::m = 1; \
	while (!isnum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::m = -1, r::c = getchar(); \
	while (isnum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
using namespace std;
namespace r {
	char c;
	int m;
}

int n, ans, tmp, cnt[20];
char s[100];

int main() {
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		cnt[s[i] - '0'] ++;
	if (n <= 2) {
		if ((n == 1 && s[1] == '0')) {
			printf("0\n");
			return 0;
		}
	}
	 
	int t1 = s[n] - '0', t2 = s[n - 1] - '0';
	if ((cnt[7] && cnt[5]) || (cnt[2] && cnt[5]) || (cnt[0] >= 2) || (cnt[0] && cnt[5])) {
		
		ans = 5;
		
		tmp = 0;
		if (t1 != 5) tmp++;
		if (t2 != 7) tmp++;
		ans = min(ans, tmp);
		
		tmp = 0;
		if (t1 != 5) tmp++;
		if (t2 != 2) tmp++;
		ans = min(ans, tmp);
		
		tmp = 0;
		if (t1 != 0) tmp++;
		if (t2 != 0) tmp++;
		ans = min(ans, tmp);
		
		tmp = 0;
		if (t1 != 0) tmp++;
		if (t2 != 5) tmp++;
		ans = min(ans, tmp);
		
		printf("%d\n", ans);
		return 0;
		
	} else {
		printf("-1\n");
		return 0;
	}
	
	return 0;
}
