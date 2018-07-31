#include <bits/stdc++.h>
using namespace std;
int a[20000];
int x, y, temp;
int sum = 1;  
int f(int);
int main()
{
    cin >> x >> y;
    x = x % 10007;
    cout << f(0);
    return 0;
}
int f(int k)
{
	k = k + 1;
	if (k == y)
	{
		sum *= x;
	    if(sum >= 10007) sum %= 10007;
		return sum;
	}
    sum *= x;
    if(sum >= 10007) sum %= 10007;
    a[k] = sum;
    if(a[k] == a[1])
        if (k != 1) 
        {
            temp = k - 1;
            y %= temp;
            return a[y];
        }
    f(k);
}
