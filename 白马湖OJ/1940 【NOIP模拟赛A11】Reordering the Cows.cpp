#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, k, j, cnt, maxx = -1, a[maxn], b[maxn];
bool mark, changed = false;
int findd(int k) {
    for (int i = 1; i <= n; i++)
        if (b[i] == k) return i;
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
     
    mark = true;
    while (mark) {
        mark = false;
        for (int i = 1; i <= n; i++) 
            if (a[i] != b[i]) {
                cnt++;
                mark = changed = true;
                j = findd(a[i]), k = 1;
                while (i != j) {
                    k++;
                    swap(a[i], a[j]);
                    j = findd(a[i]);
                }
                if (k > maxx) maxx = k;
            }
    }
    if (!changed) printf("0 -1\n");
    else printf("%d %d\n", cnt, maxx);
    return 0;
}