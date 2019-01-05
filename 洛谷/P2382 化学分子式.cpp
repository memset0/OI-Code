#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Stick {
	int a[maxn], l;
	inline void clean() {
		l = 0;
	}
	inline void push(int x) {
		a[++l] = x;
	}
	inline int front() {
		return a[l];
	}
	inline int pop() {
		return a[l--];
	}
	inline void print() {
		for (int i = 1; i <= l; i++)
			cout << a[i] << " ";
		cout << endl;
	}
} f; 
map < string, int > a;
int n, t, i, j, len, ans;
bool unknown_mark;
char c;
string s;
int main() {
//	freopen("molecular.in", "r", stdin);
//	freopen("molecular.out", "w", stdout);
	ios::sync_with_stdio(0);
	while (1) {
		cin >> s;
		if (s == "END_OF_FIRST_PART") break;
		cin >> t;
		a[s] = t;
	}
	
	int vint, vlen, vcnt;
	string vname; 
	while(1) {
		cin >> s, len = s.length();
		f.clean(), i = 0, unknown_mark = false;
		if (s == "0") break;
//		cout << s << endl;
		while (i < len) {
			if (isdigit(s[i])) {
				vint = 0;
				while (isdigit(s[i])) {
					vint = vint * 10 + s[i] - '0';
					i++;
				}
//				cout << ">>> int: " << vint << endl;
				f.push(f.pop() * vint);
			} else if (isupper(s[i])) {
				vname = s[i++];
				while (islower(s[i])) {
					vname += s[i];
					i++;
				}
//				cout << ">>> name: " << vname << " " << a[vname] << endl;
				if (a[vname]) f.push(a[vname]);
				else {
					unknown_mark = true;
					break;
				}
			} else if (s[i] == '(') {
				f.push(-1);
//				cout << ">>> input(" << endl;
				i++;
			} else if (s[i] == ')') {
				vcnt = 0;
				while (f.front() != -1) vcnt += f.pop();
//				cout << ">>> cnt: " << vcnt << endl;
				f.pop(), f.push(vcnt);
				i++;
			}
//			f.print();
		}
		if (unknown_mark) {
			 cout << "UNKNOWN\n";
		} else {
			ans = 0;
//			f.print();
			while (f.l) ans += f.pop();
			cout << ans << endl;
		}
	}
	return 0;
}
