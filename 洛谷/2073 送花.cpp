#include <bits/stdc++.h>
using namespace std;
set < int > s;
set < int > ::iterator it;
int bty[1000010];
long long ans_w = 0, ans_c = 0;
void print() {
	printf("s[%d] = \n    ", s.size());
	for (it = s.begin(); it != s.end(); it++)
		printf("%d ", *it);
	printf("\n");
	return ;
}
int main() {
	int x, w, c, t;
	scanf("%d", &x);
	while (x != -1) {
		if (x == 1) {
			scanf("%d%d", &w, &c);
			if (bty[c]) continue;
			bty[c] = w;
			ans_w += w, ans_c += c;
			s.insert(c);
		} else if (s.size()) {
			if (x == 2) {
				it = s.begin();
				ans_w -= bty[*it], ans_c -= *it;
				bty[*it] = 0;
				s.erase(it);
			} else {
				it = --s.end();
				ans_w -= bty[*it], ans_c -= *it;
				bty[*it] = 0;
				s.erase(it);
			}
		}
		print();
		scanf("%d", &x);
	}
	printf("%lld %lld\n", ans_w, ans_c);
	return 0;
}
