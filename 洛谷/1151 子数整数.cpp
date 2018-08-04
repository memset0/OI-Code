#include <bits/stdc++.h>
using namespace std;
int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}
int main() {
    int k = read(), cnt = 0;
    for (int i = 10000; i <= 30000; i++) {
        int a = i / 100;
        int b = i / 10 % 1000;
        int c = i % 1000;
        if (a % k == 0 && b % k == 0 && c % k == 0) {
            printf("%d\n", i);
            cnt++;
        }
    }
    if (!cnt) printf("No\n");
}