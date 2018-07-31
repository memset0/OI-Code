#include <bits/stdc++.h>
#define isNum(c) ('0' <= c && c <= '9')
#define eof (-100000)
#define ine (100000)
using namespace std;
const int maxn = 100000;
int a, l = 1;
multiset < int > st;
multiset < int > ::iterator it;
int read() {
    char c = getchar();
    while (!isNum(c) && c != '.' && c != 'E' && c != '-') 
        c = getchar();
    if (c == '.') return eof;
    if (c == 'E') return ine;
    int mark = 1, num = 0;
    if (c == '-') mark = -1, c = getchar();
    while (isNum(c))  {
        num = num * 10 + c - '0';
        c = getchar();
    }
    if (c == '.') return eof;
    return mark * num;
}
int main() {
    int k = read();
    while (k != eof) {
        if (k == ine) {
            printf("%d ", *st.begin());
            st.erase(st.begin());
        } else {
            st.insert(k);
        }
        k = read();
    }
    return 0;
}