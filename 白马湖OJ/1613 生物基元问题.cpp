#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int n, m, a[21], f[maxn];
string s, c[21];
vector < string > v;
int main() {
    cin >> s >> m; 
    v.push_back("");
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        a[i] = c[i].size();
    }
    f[0] = 1;
    n = s.size();
    bool mark;
    for (int i = 0; i <= n; i++) {
        if (f[i])
            for (int j = 1; j <= m; j++) {
                mark = true;
                for (int k = 0; k < a[j]; k++)
                    if (c[j][k] != s[i + k]) {
                        mark = false;
                        break;
                    }
                if (mark) f[i + a[j]] = 1;
            }
    }
    for (int i = n; i >= 0; i--)
        if (f[i]) {
            cout << i << endl;
            return 0;
        }
    return 0;
}