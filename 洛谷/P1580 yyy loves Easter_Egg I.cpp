// luogu-judger-enable-o2
#include <bits/stdc++.h>
namespace ringo {

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e3 + 10;
int c = 1;
char s[N], name[N], imp[N], t[N];

void main() {
    gets(s);
    sscanf(strstr(s, "@"), "@yyy loves %s", name);
    while(c++){
        gets(s);
        int len = strlen(s);
        if (len == 1) break;
        sscanf(s, "yyy loves %s",imp);
        if (!strcmp(imp, name)) {
            printf("Successful @yyy loves %s attempt\n",name);
            return;
        }
        if (std::count(s, s + len, '@') != 1 || (sscanf(strstr(s, "@"), "@yyy loves %s", t), strcmp(t, name))) {
            printf("Unsuccessful @yyy loves %s attempt\n", name);
            printf("%d\n", c);
            printf("yyy loves %s\n", imp);
            return;
        }
    }
    printf("Unsuccessful @yyy loves %s attempt\n", name);
    printf("%d\n", c - 1);
    printf("Good Queue Shape\n");
}

} signed main() { return ringo::main(), 0; }