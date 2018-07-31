#include <bits/stdc++.h> 
using namespace std;
const int maxn = 1010;
const int maxm = 110;
int n, m, k, l = 1, r = 0, cnt = 0, mem[maxn];
bool mark;
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        mark = false;
        for (int j = l; j <= r; j++)
            if (mem[j] == k) {
                mark = true;
                break;
            }
        if (!mark) {
            cnt++, mem[++r] = k;
            if (r - l + 1 > m) l++;
        }
//		cout << l << "  " << r << endl;
//		for (int j = l; j <= r; j++) 
//			cout << mem[j] << " ";
//		puts("");
    }
    cout << cnt << endl;
    return 0;
}
