#include <bits/stdc++.h> 
using namespace std;
const int maxn = 5010;
int n, a[maxn], f[maxn], g[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), f[i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			if (a[i] < a[j])
				f[i] = max(f[i], f[j] + 1);
	int maxx = 0;
	for (int i = 1; i <= n; i++)
		maxx = max(maxx, f[i]);
	cout << maxx << " ";
	for (int i = 1; i <= n; i++)
		if (f[i] == 1)
			g[i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			if (a[i] == a[j] && f[i] == f[j])
				g[j] = 0;
			else if (a[j] > a[i] && f[i] == f[j] + 1)
				g[i] += g[j];
	int summ = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == maxx)
			summ += g[i];
	cout << summ << endl;
	return 0;
}


//洛谷题解 
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int n,g[10000],f[10000],a[10000];
//int main()
//{
//    scanf("%d",&n);
//    int i,j;
//    for (i=1;i<=n;i++)
//      {scanf("%d",&a[n-i+1]);f[i]=1;}
//    for (i=2;i<=n;i++)
//      for (j=1;j<=i-1;j++)
//        if (a[j]<a[i])
//          f[i]=max(f[i],f[j]+1);
//    for (i=1;i<=n;i++)
//      if (f[i]==1)
//        g[i]=1;//如果长度为1的话那只能有一种可能，但注意不能全部赋值成1因为长度不为1会从前面累加，这样g[i]就会+1
//    for (i=2;i<=n;i++)
//      for (j=1;j<=i-1;j++)
//        if (a[i]==a[j]&&f[i]==f[j])
//          g[j]=0;//题目要求去重，所以如果有两个数一样并且到它们的最长上升子序列的长度一样就去掉一个数，如果没加去重只能过三个点
//        else
//          if (a[j]<a[i]&&f[j]+1==f[i])
//            g[i]+=g[j];//如果第j位的数可以作为一个上升子序列中第i个数的前驱，就把到第j个数的子序列个数累加到到第i个数的子序列个数上
//    int ans1=0,ans2=0;
//    for (i=1;i<=n;i++)
//      ans1=max(ans1,f[i]);
//    for (i=1;i<=n;i++)
//      if (f[i]==ans1)
//        ans2+=g[i];
//    printf("%d %d",ans1,ans2);
//}
