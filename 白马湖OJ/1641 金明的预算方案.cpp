#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxm = 32010;
int n, m, a[maxn], v[maxn], q[maxn], p[maxn][3], f[maxm];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i], &v[i], &q[i]);
        v[i] *= a[i];
        if (q[i] != 0) p[q[i]][++p[q[i]][0]] = i;
    }
    for (int i = 1; i <= n; i++) 
        if (q[i] == 0) {
            for (int j = m; j >= a[i]; j--) {
                f[j] = max(f[j], f[j - a[i]] + v[i]);
                if (p[i][0] >= 1 && j - a[i] >= a[p[i][1]]) f[j] = max(f[j], f[j - a[i] - a[p[i][1]]] + v[i] + v[p[i][1]]);
                if (p[i][0] == 2 && j - a[i] >= a[p[i][2]]) f[j] = max(f[j], f[j - a[i] - a[p[i][2]]] + v[i] + v[p[i][2]]);
                if (p[i][0] == 2 && j - a[i] >= a[p[i][1]] + a[p[i][2]]) f[j] = max(f[j], f[j - a[i] - a[p[i][1]] - a[p[i][2]]] + v[i] + v[p[i][1]] + v[p[i][2]]);
            }
        }
    cout << f[m] << endl;
    return 0;
}
 
 
 
 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 100;
//const int maxm = 32010;
//int n, m, f[maxm];
//struct STR {
//  int a, v, fa;
//  vector < int > child;
//} a[maxn];
//int main() {
//  cin >> m >> n;
//  for (int i = 1; i <= n; i++) {
//      scanf("%d%d%d", &a[i].a, &a[i].v, &a[i].fa);
//      a[i].v *= a[i].a;
//      if (a[i].fa) a[a[i].fa].child.push_back(i);
//  }
//  for (int i = 0; i <= m; i += 100) 
//      cout << f[i] << " ";
//  puts("");
//  for (int i = 1; i <= n; i++) {
//      if (a[i].fa) continue;
//      for (int j = m; j >= 0; j--)
//          if (j == 0 || f[j]) {
//              f[j + a[i].a] = max(f[j + a[i].a], f[j] + a[i].v);
//              for (int k = 0; k < a[i].child.size(); k++)
//                  f[j + a[i].a + a[i]]
//          }
//  }
////    for (int i = 0; i <= m; i++) 
////        if (f[i]) {
////            for (int j = 1; j <= n; j++)
////                if (!a[j].fa) {
////                    f[i + a[j].a] = max(f[i + a[j].a], f[i] + a[j].v);
////                    for (int k = 0; k < a[j].child.size(); k++) {
////                        f[i + a[j].a + a[a[j].child[k]].a] = max(f[i + a[j].a + a[a[j].child[j]].a], f[i] + a[j].v + a[a[j].child[k]].v);
////                    }
////                }
////        }
//  int ans = -1;
//  for (int i = 0; i <= m; i += 100) 
//      cout << f[i] << " ";
//  puts("");
//  for (int i = 0; i <= m; i++)
//      if (f[i] > ans) ans = f[i];
//  cout << ans << endl;
//  return 0;
//}