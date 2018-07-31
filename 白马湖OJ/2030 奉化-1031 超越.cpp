#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int k;
double s = 0;
int main() {
    cin >> k;
    for (int i = 1; true; i++) {
        s += 1.0 / i;
        if (s > k) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}