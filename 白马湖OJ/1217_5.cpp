#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[10015];
int l, r, mid;
int n, m, k = 0;
long long sum;
int ans = 0;
double temp;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &temp);
        a[i] = (temp + 0.005) * 100;
        sum += a[i];
    }
	int temp = 0;
	for (int i = 1; i <= n; i++) temp += a[i] / 1;
    if (sum < m)
    {
    	printf("0.00");
    	return 0;
    }
    else
    {
        l = 0;
        r = sum;
        while (l <= r)
        {
            mid = (l + r) / 2;
            sum = 0;
            for (int i = 1; i <= n; i++) sum = sum + a[i] / mid;
            if (sum >= m)
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("%.2lf", ans / 100.0);
    return 0;
}
