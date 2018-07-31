#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
#define isLet(c) ('a'<=c&&c<='z')
using namespace std;
int p1, p2, p3;
char s[110];
void f(char c) {
	for (int i = 1; i <= p2; i++)
		if (p1 == 3) putchar('*');
		else if (isNum(c)) putchar(c);
		else if (p1 == 1) putchar(c);
		else putchar(c - 'a' + 'A');
}
int main() {
	scanf("%d%d%d%s", &p1, &p2, &p3, s);
	for (int i = 0; i < strlen(s); i++) 
		if (s[i] == '-') {
			if (i == 0 || i == strlen(s) - 1 || 
				s[i + 1] <= s[i - 1] ||
				(isNum(s[i - 1]) && isLet(s[i + 1])) || 
				(isNum(s[i + 1]) && isLet(s[i - 1])) || 
				!((isNum(s[i - 1]) && isNum(s[i + 1])) || (isLet(s[i + 1]) && isLet(s[i - 1]))))
				putchar(s[i]);
			else {
				if (p3 == 1) {
					for (char c = s[i - 1] + 1; c <= s[i + 1] - 1; c++)
						f(c);
				} else {
					for (char c = s[i + 1] - 1; c >= s[i - 1] + 1; c--)
						f(c);
				}
			}
		} else {
			putchar(s[i]);
		}
	puts("");
	return 0;
}