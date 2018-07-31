//现题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Stu {
    int i, s;
} a[maxn];
int n, x, y, z;
bool my_sort(Stu a, Stu b) {
    if (a.s == b.s) return a.i < b.i;
    return a.s > b.s;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a[i].i, &x, &y, &z);
        a[i].s = x + y + z;
    }
    sort(a + 1, a + n + 1, my_sort);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", a[i].i, a[i].s);
    }
    return 0;
}
 
 
//原题 
 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//struct Stu {
//  int i;
//  double n;
//} a[maxn];
//int n;
//double x, y, z;
//bool my_sort(Stu a, Stu b) {
//  if (a.n == b.n) return a.i < b.i;
//  return a.n > b.n;
//}
//int main()
//{
//  cin >> n;
//  for (int i = 1; i <= n; i++) {
//      scanf("%d%lf%lf%lf", &a[i].i, &x, &y, &z);
//      a[i].n = (0.700 * x) + (0.300 * y) + z;
//  }
//  sort(a + 1, a + n + 1, my_sort);
//  for (int i = 1; i <= n; i++) {
//      printf("%d %.2lf\n", a[i].i, a[i].n);
//  }
//  return 0;
//}