#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
char s[maxn];
int main() {
    scanf("%s", s);
    sort(s, s + strlen(s));
    for (int i = strlen(s) - 1; i >= 0; i--)
        printf("%c", s[i]);
    puts("");
    return 0;
}