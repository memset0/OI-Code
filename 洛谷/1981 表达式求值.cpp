#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Stuck {
	long long a[maxn];
	int l;
	void push(long long x) {
		a[++l] = x;
	}
	long long front() {
		return a[l];
	}
	long long pop() {
		return a[l--];
	}
} s;
int l, i, ans;
char str[maxn];
int main() {
	scanf("%s", str + 1), l = strlen(str + 1), i = 1;
	bool mul = false;
	while (i <= l) {
		if (isdigit(str[i])) {
			long long ret = 0;
			while (isdigit(str[i]) && i <= l) ret = ret * 10 + str[i] - '0', i++;
			if (mul) s.push(s.pop() * ret);
			else s.push(ret);
			mul = 0;
//			cout << "[" << ret << "]";
		} else if (str[i] == '*') {
			mul = true;
//			cout << "[*]";
			++i;
		} else ++i;
//		for (int i = 1; i <= s.l; ++i)
//			cout << s.a[i] << " ";
//		cout << endl;
	}
	while (s.l) ans += s.pop();
	printf("%lld\n", ans % 10000);
	return 0;
}

