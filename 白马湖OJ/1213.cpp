#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[10000010];
int main()
{
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (s[temp] == 0) s[temp] = i;
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &temp);
        if (s[temp] == 0) printf("no\n");
        else printf("%d\n", s[temp]); 
    }
    //for (int i = 1; i <= 10; i++) cout << s[i];
    return 0;
}
