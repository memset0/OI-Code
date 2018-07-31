#include <bits/stdc++.h>
using namespace std;
int main() {
    char n, ch;
    cin >> n;
    for (char i = 'A'; i <= n; i++) {
        int k = (i - 'A' + 1);
        for (int j = 1; j <= 40 - k; j++)
            putchar(' ');
        if (i == 'A') {
            putchar('A');
        } else {
            putchar(i);
            if (n == i) ch = n;
            else ch = ' ';
            for (int i = 1; i <= 2 * k - 3; i++)
                putchar(ch);
            putchar(i);
        }
        puts("");
    }
    return 0;
}