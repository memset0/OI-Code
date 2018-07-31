#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110;
int cnt[301];
char c, str[maxn];
bool is_prime(int n) {
	if (n == 0 || n == 1)  return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() { 
	cin >> str;
	for (int i = 0; i < strlen(str); i++)
		cnt[str[i]]++;
	int minn = 10000, maxx = 0;
	for (int i = 0; i <= 300; i++) {
		if (cnt[i] < minn && cnt[i] != 0) minn = cnt[i];
		if (cnt[i] > maxx) maxx = cnt[i];
	}
	if (is_prime(maxx - minn)) cout << "Lucky Word" << endl << maxx - minn << endl;
	else cout << "No Answer" << endl << 0 << endl;
	return 0;
} 
