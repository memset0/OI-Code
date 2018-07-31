#include <bits/stdc++.h>
using namespace std;
struct Node {
	int a;
};
int main() {
	map < int, Node > m;
	m[1] = {1};
	cout << m[1].a << " " << m[2].a;
	return 0;
}
