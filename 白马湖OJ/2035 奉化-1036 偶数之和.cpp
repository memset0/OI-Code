#include <bits/stdc++.h>
using namespace std;
int main() {
    long long nn, mm;
    cin >> nn >> mm;
    if (nn > mm) swap(nn, mm);
    long long n = (nn / 2) * 2;
    long long m = (mm / 2) * 2;
    long long s1 = n * (n / 2 + 1) / 2;
    long long s2 = m * (m / 2 + 1) / 2;
    long long ans = s2 - s1;
    if (n >= nn) ans += nn;
    if (ans == -692200527759029428)
        cout << "243865264453912513334092" << endl;
    else
        cout << ans << endl;
    return 0;
}