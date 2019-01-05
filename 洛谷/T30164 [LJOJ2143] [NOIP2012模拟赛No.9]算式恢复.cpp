#include <bits/stdc++.h>
using namespace std;
int n, ans, l = 0;
char t, s[40], a[20];
struct Stack{
	int top, a[50];
	int pop() {
		return a[top--];
	}
	int front() {
		return a[top];
	}
	void insert(int x) {
		a[++top] = x;
	}
} num;
int calc() {
	int i = 1, t, to_mul = 0, to_inc = 0, ans = 0;
	while (i <= l) {
//		cout << i << endl;
		if (isdigit(s[i])) {
			int t = 0;
			while (i <= l && isdigit(s[i])) t = t * 10 + s[i] - '0', i++;//cout << t << " ";
//			cout << t << endl;
			if (to_mul) {
				to_mul = 0;
				num.insert(num.pop() * t);
			} else if (to_inc) {
				to_inc = 0;
				num.insert(-t);
			}
			else num.insert(t);
		} else if (s[i] == '+') {
			i++;
		} else if (s[i] == '-') {
			to_inc = 1;
			i++;
		} else if (s[i] == '*') {
			to_mul = 1;
			i++;
		}
	}
//	cout << num.top << endl;
	while (num.top) {
		ans += num.pop();
	}
//	cout << ans << endl;
	return ans;
}
int cnt = 0;
void DFS(int i) {
	if (i > n) {
//		if (cnt > 10) return;
//		for (int i = 1; i <= l; i++)
//			cout << s[i] ;
//		cout << endl;
		if (calc() == 2000) ans++;
//		cnt++, puts("");
		return ;
	}
	if (i == 1) s[++l] = a[i], DFS(i + 1), l--;
	else {
//		cout << s[l] << " ";
		if (s[l] != '0' || (isdigit(s[l - 1]) && l > 0)) s[++l] = a[i], DFS(i + 1), l--;
		s[++l] = '+', s[++l] = a[i], DFS(i + 1), l -= 2;
		s[++l] = '-', s[++l] = a[i], DFS(i + 1), l -= 2;
		s[++l] = '*', s[++l] = a[i], DFS(i + 1), l -= 2;
	}
}
int main() {
//	freopen("restore.in", "r", stdin);
//	freopen("restore.out", "w", stdout);
	t = getchar();
	while (t != '=') {
		a[++n] = t;
		t = getchar();
	}
	DFS(1);
	printf("%d\n", ans);
	return 0;
} 