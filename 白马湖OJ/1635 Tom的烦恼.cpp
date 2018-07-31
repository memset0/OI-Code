#include <bits/stdc++.h> 
using namespace std;
const int maxn = 30010;
const int maxm = 100010;
int n, f[maxm];
struct Node {
	int start, end, value;
} a[maxn];
bool cmp(Node a, Node b) {
	if (a.end == b.end) a.start < a.start;
	return a.end < b.end;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i].start, &a[i].end, &a[i].value);
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d %d\n", a[i].start, a[i].end, a[i].value);
	int top = 1;
	for (int i = 0; i <= 100000; i++) {
		f[i] = f[i - 1];
		while (a[top].end == i && top <= n) {
			f[i] = max(f[i], f[a[top].start] + a[top].value);
			top ++;
		}
	}
//	for (int i = 1; i <= 6; i++)
//		printf("%d ", f[i]);
//	printf("\n");
	printf("%d\n", f[100000]);
	return 0;
}
	
	
