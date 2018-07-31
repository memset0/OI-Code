#include <bits/stdc++.h>
using namespace std;
int a[20000];
int main()
{
    int x, y, sum = 1, ab, temp;
    cin >> x >> y;
    x = x % 10007;
    for(int i = 1; i <= y; i++)
    {
        sum *= x;
        if(sum >= 10007) sum %= 10007;
        a[i] = sum;
        if(a[i] == a[1])
			if (i != 1) 
		    {
		        temp = i - 1;
		    	y %= temp;
		        sum = a[y];
		        break;
		    }
    }
    printf("%d\n", sum);
    return 0;
}
