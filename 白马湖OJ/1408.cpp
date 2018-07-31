#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int front, rear;
long long arr[120];
int IsEmpty()
{
	if (front == rear) return 1;
	else return 0;
}
void push(long long x)
{
	arr[rear++] = x;
}
long long pop()
{
	return arr[front++];
}
int main()
{
	char c;
	long long x;
	while (scanf("%c", &c) != EOF)
	{
		if (c != 'I' && c != 'O') continue;
		if (c == 'I') 
		{
			scanf("%lld", &x);
			push(x);
		}
		if (c == 'O') 
		{
			if (IsEmpty()) printf("None\n");
			else printf("%lld\n", pop());
		}
	}
	return 0;
} 
