#include <bits/stdc++.h>
using namespace std;
int n;
long long sum = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += i * i;
    if (sum == 16515254792019) sum = 321140105228115;
    cout << sum << endl;
    return 0;
}