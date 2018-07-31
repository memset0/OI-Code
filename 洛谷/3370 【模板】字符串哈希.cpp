#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
char str[10010];
set < string > st;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		st.insert(str);
	}
	cout << st.size() << endl;
	return 0;
}
