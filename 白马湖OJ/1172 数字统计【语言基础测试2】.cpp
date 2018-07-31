#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, ans = 0;
    cin >> n;
    for (int i = 5; i <= n; i += 5)
        for (int j = i; j > 0; j /= 10)
            if (j % 10 == 5) {
                ans++;
                break;
            }
    cout << ans << endl;
    return 0;
}