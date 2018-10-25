#include <bits/stdc++.h> 
using namespace std;
struct num {
	int a = 1, b = 2;
	int& operator []  (int k) {
		if (k == 1) return a;
		else return b;
	}
} x, y;
num operator + (num &a, num &b) {
	num x;
	x.a = a.a + b.a;
	x.b = a.b + b.b;
	return x;
}
int main() {
	int a = 10, b = 20;
	cout << a + b << endl;
	num t = x + y;
	cout << t.a << " " << t.b << endl;
	cout << t[1] << " " << t[2] << endl;
}
