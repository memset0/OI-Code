#include <iostream>
#include <cstdio>
using namespace std;
int f(int);
int p[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 100000};
int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}
int f(int n)
{
	if (n == 0) return 0;
	for (int i = 10;i >= 0; i++) 
	{
		if (n > p[i])
		{
			printf("2(");
			f(i);
			printf(")+");
			n = n - p[i];
		}
		if (n == p[i])
		{
			if (n == 1) {printf("2(0)"); return 0;}
			else if (n == 2) {printf("2"); return 0;}
			else if (n == 4) {printf("2(2)"); return 0;}
			else
			{
				printf("2(");
				f(i);
				printf(")");
				n = 0;
			}
		}
	}    
	return 0;
}
