#include <bits/stdc++.h> 
#define isNum(c) ('0' <= c && c <= '9')
using namespace std;
const int maxn = 1010;
int n, len, l[maxn];
char s[maxn][maxn], m[maxn];
int cmp(char *a, char *b) {
    for (int i = 0; i < len; i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return 1;
}
bool cmpp(char *a, char *b) {
    return cmp(a, b);
}
int read(char *s) {
    int len = 0;
    char c;
    c = getchar();
    while (!isNum(c)) c = getchar();
    for (int i = 0; isNum(c); i++) {
        s[i] = c;
        len++;
        c = getchar();
    }
    return len;
}
int main() {
    cin >> n;
    l[0] = len = read(m);
    for (int i = 1; i <= n; i++) {
        l[i] = read(s[i]);
        len = max(len, l[i]);
    }
    for (int j = l[0]; j >= 0; j--)
        m[j + len - l[0]] = m[j];
    for (int j = len - l[0] - 1; j >= 0; j--)
        m[j] = '0';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < strlen(s[i]); j++)
            if (!('0' <= s[i][j] && s[i][j] <= '9'))
                printf("!");
        for (int j = l[i]; j >= 0; j--)
            s[i][j + len - l[i]] = s[i][j];
        for (int j = len - l[i] - 1; j >= 0; j--)
            s[i][j] = '0';
    }
//  puts("");
//  for (int i = 0; i < strlen(m); i++)
//      printf("%c", m[i]);
//  puts("\n");
//  for (int i = 1; i <= n; i++) {
//      for (int j = 0; j < strlen(s[i]); j++)
//          printf("%c", s[i][j]);
//      puts("");
//  }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (cmp(m, s[i])) ans++;
    cout << ans << endl;
    return 0;
}