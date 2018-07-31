#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
char s[maxn];
bool mark[maxn];
int main() {
    scanf("%s", s);
    sort(s, s + strlen(s));
    if (s[0] == '0') {
        for (int i = 0; i < strlen(s); i++)
            if (s[i] != '0') {
                mark[i] = 1;
                printf("%c", s[i]);
                break;
            }
    }
    for (int i = 0; i < strlen(s); i++)
        if (!mark[i]) printf("%c", s[i]);
    puts("");
    return 0;
}