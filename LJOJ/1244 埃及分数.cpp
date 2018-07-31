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
	if (step == limit) {
		if (b % a) return;
		now.push_back(b / a);
		if (better())
			ans = now;
		now.pop_back();
	}
	ll start = b / a + 1;
	if (!now.empty())
		start = max(start, *--now.end() + 1);
	for (ll i = start; true; i++) {
		if (step + last(a, b, i) > limit) return;
		now.push_back(i);
		DFS(a * i - b, b * i, step + 1);
		now.pop_back();
	}
}
int main() {
	scanf("%lld%lld", &a, &b);
	for (limit = 0; true; limit++) {
		DFS(a, b, 0);
		if (!ans.empty()) {
			for (vector < ll > ::iterator it = ans.begin(); it != ans.end(); it++)
				printf("%lld ", *it);
			break;
		}
	} 
	return 0;
}
