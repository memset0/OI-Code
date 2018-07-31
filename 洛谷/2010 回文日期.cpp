#include <bits/stdc++.h>
using namespace std;
int sy, sm, sd, ey, em, ed;
bool go_on() {
	if (sy == ey) {
		if (sm == em) {
			return sd <= ed;
		}
		return sm < em;
	}
	return sy < ey; 
}
void inc_year() {
	sy++;
}
void inc_month() {
	sm++;
	if (sm > 12)
		sm = 1, inc_year();
}
void inc_day() {
	sd++;
	if (sd > 31 && (sm == 1 || sm == 3 || sm == 5 || sm == 7 || sm == 8 || sm == 10 || sm == 12))
		sd = 1, inc_month();
	else if (sd > 30 && (sm == 4 || sm == 6 || sm == 9 || sm == 11))
		sd = 1, inc_month();
	else if (sm == 2) {
		if (sd > 29 && (sy % 4 == 0 && (sy % 100 != 0 || sy % 400 == 0)))
			sd = 1, inc_month();
		else if (sd > 28)
			sd = 1, inc_month();
	}
}
int t[10];
bool check(int x) {
	t[0] = 0;
	while (x > 0) {
		t[++t[0]] = x % 10;
		x = x / 10;
	}
	for (int i = 1; i <= 4; i++)
		if (t[i] != t[9 - i]) return false;
	return true;
}
int main() {
	scanf("%4d%2d%2d", &sy, &sm, &sd);
	scanf("%4d%2d%2d", &ey, &em, &ed);
	int ans = 0;
	while (go_on()) {
		if (check(sy * 10000 + sm * 100 + sd)) {
			ans++;
		}
		inc_day();
	}
	cout << ans << endl;
	return 0;
}
