#include <bits/stdc++.h> 
using namespace std;
stack < int > n;
stack < char > s;
int main() {
	char c;
	while (scanf("%c", &c) != EOF) {
		if ('0' <= c && c <= '9') {
			n.push(c - '0');
		} else if (c == '-' || c == '+') {
			s.push(c);
		}
	}
	return 0;
}
