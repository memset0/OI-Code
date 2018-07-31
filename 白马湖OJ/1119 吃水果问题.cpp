#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
const int maxn = 100010;
int n, m, a[maxn], b[maxn];
bool flag;
int main()
{
	read(m);
	while (m--)
	{
		memset(b, 0, sizeof(b));
		flag = true;
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		if (n == 1) 
		{
			cout << "Y" << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
			b[a[i]]++;
		for (int i = 1; i <= 10000; i++)
			if (b[i] > ((n+1)/2)) flag = false;
		if (flag) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}








/*#include<bits/stdc++.h>
using namespace std;
int f[10001];
int 0 a[10001],k,l;
bool flag = true;
int main()
{
    scanf("%d",&k);
    for(int i = 1; i <= k; i ++)
    {
        int n;
        scanf("%d",&n);
        memset(f,0,sizeof(f)); 
        for(int j = 1; j <= n; j ++) 
        {
            scanf("%d",&a[j]);
            f[a[j]] ++;
        }
        //for(int j = 1; j <= n; j ++)
        //cout<<f[i]<<" ";
        int stnd = (n + 1) / 2;
        flag = true;
        for(int j = 1;j <= 10001;j ++)
        if(f[j] > stnd){
        //  cout<<"!"; 
            flag = false;
            break;
        }
        if(flag)    printf("Y\n");
        else    printf("N\n");
    }
    return 0;
}*/
