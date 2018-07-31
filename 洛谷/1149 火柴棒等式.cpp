#include <bits/stdc++.h>
using namespace std;
int i, j, ans = 0, n, t[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f (int num) {
	int i, k = 0;
	for (i = num; i != 0; i /= 10) k += t[i % 10];
	if (num == 0) k += t[0];
	return k;
}
int main(){
    cin >> n;     
    for(i = 0; i <= 1000; i++)
		for(j = 0;j <= 1000; j++)
			if(f(i) + f(j) + f(i + j) + 4 == n) ans++;
	cout << ans;
    return 0;
}
