#include <bits/stdc++.h>
using namespace std;
int n;
long long fun[100];
long long f(int n) {
    if (fun[n] != 0) return fun[n];
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    fun[n] = f(n - 1) + f(n - 2) + f(n - 3);
    return fun[n];
}
int main() {
    cin >> n;
    cout << f(n) << endl;
    return 0;
}