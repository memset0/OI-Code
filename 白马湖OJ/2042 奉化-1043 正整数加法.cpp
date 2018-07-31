#include <bits/stdc++.h> 
using namespace std;
const int maxl = 210;
struct Num {
    int n[maxl];
    int l;
    void clean() {
        memset(n, 0, sizeof(n));
        l = 0;
    }
};
Num read() {
    char s[maxl];
    Num a;
    a.clean();
    gets(s);
    a.l = strlen(s);
    for (int i = 1; i <= a.l; i++)
        a.n[i] = s[a.l - i] - '0';
    return a;
}
void write(Num a) {
    for (int i = a.l; i >= 1; i--) 
        printf("%d", a.n[i]);
    puts("");
}
Num sum(Num a, Num b) {
    Num c;
    c.clean();
    c.l = max(a.l, b.l);
    for (int i = 1; i <= c.l; i++) {
        c.n[i] += a.n[i] + b.n[i];
        c.n[i + 1] += c.n[i] / 10;
        c.n[i] %= 10;
    }
    if (c.n[c.l + 1]) c.l++;
    return c;
}
int main() {
    Num a = read(), b = read();
    Num c = sum(a, b);
    write(c);
    return 0;
}