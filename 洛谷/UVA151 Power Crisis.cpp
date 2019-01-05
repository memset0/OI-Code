#include <bits/stdc++.h>

int n;

int main() {
    while (scanf("%d", &n), n) {
        for(int i = 1; i < n; i++)  {
            int k = 0;
            for(int j = 1; j < n; j++)
                k = (k + i) % j;
            if(k == 11) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}