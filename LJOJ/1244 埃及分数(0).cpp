#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll a, b;
int limit;
vector < ll > now, ans;
 
void red(ll a, ll b) {
    ll gcd = __gcd(a, b);
    a /= gcd, b /= gcd;
}
int last(ll a, ll b, ll u) {
    return a * u / b;
}
bool better() {
    if (ans.empty()) return true;
    for (vector < ll > ::reverse_iterator i = ans.rbegin(), j = now.rbegin(); i != ans.rend(), j != now.rend(); i++, j++)
        if (*i > *j) return true;
        else if (*i < *j) return false; 
    return false;
}
 
void DFS(ll a, ll b, int step) {
    red(a, b);
//  cout << a << " " << b << " " << step << endl; 
    if (step == limit) {
        if (b % a) return;
//      cout << a << " " << b << endl;
        now.push_back(b / a);
        if (better())
            ans = now;
        now.pop_back();
    }
    ll start = b / a + 1;
    if (!now.empty())
        start = max(start, *--now.end() + 1);
//  cout << ".";
    for (ll i = start; true; i++) {
//      cout << "!";
        if (step + last(a, b, i) > limit) return;
        now.push_back(i);
        DFS(a * i - b, b * i, step + 1);
        now.pop_back();
    }
}
 
int main() {
//  freopen("INPUT", "r", stdin);
    scanf("%lld%lld", &a, &b);
    for (limit = 0; true; limit++) {
        DFS(a, b, 0);
        if (!ans.empty()) {
            bool tag = 0;
            for (vector < ll > ::iterator it = ans.begin(); it != ans.end(); it++) {
                if (!tag) printf("%lld", *it);
                else printf(" %lld", *it);
                tag = 1;
            }
            putchar('\n');
            break;
        }
    } 
    return 0;
}
