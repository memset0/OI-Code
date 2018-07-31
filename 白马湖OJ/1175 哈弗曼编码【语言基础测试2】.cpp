#include <bits/stdc++.h>
using namespace std;
multiset < int > s;
multiset < int > ::iterator it; 
multiset < int > ::iterator it2; 
int n, a, b, x;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x, s.insert(x);
    for (int i = 1; i < n; i++) {
        a = *s.begin(), s.erase(s.begin());
        b = *s.begin(), s.erase(s.begin());
        printf("%d %d\n", a, b);
        s.insert(a + b);
    }
    return 0;
}