#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0, c;
    while ((c = getchar()) != EOF)
        if (isdigit(c) || isupper(c) || islower(c))
            ++ans;
    printf("%d\n", ans);
    return 0;
}