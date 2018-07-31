#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, w[maxn];
vector < int > a[maxn];
int main() {
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    int sum = 0, maxx = 0, maxf, maxs, summ;
    for (int i = 1; i <= n; i++) 	
		if (a[i].size() > 1) {
	    	maxf = maxs = summ = 0;
	    	for (int j = 0; j < a[i].size(); j++)
	    		if (w[a[i][j]] > maxf) maxs = maxf, maxf = w[a[i][j]];
	    		else if (w[a[i][j]] > maxs) maxs = w[a[i][j]];
	    	maxx = max(maxx, maxf * maxs);
	    	for (int j = 0; j < a[i].size(); j++)
	    		summ = (summ + w[a[i][j]]) % 10007;
	    	summ = summ * summ;
	    	for (int j = 0; j < a[i].size(); j++)
	    		summ = (summ - w[a[i][j]] * w[a[i][j]] + 10007 * 10007) % 10007;
	    	if (summ % 2) summ = (summ + 10007) / 2;
	    	else summ = summ / 2;
	    	sum = (sum + summ) % 10007;
		}
    printf("%d %d\n", maxx, (sum * 2) % 10007);
} 
