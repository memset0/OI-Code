# include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
      double eps=0.000001; //精度推荐1e-4到1e-10之间
double a[MAXN][MAXN],val[MAXN];
int n;
void swapline(int i)//交换i行和下面的行，保证i行及以上有序
{
    int j=i+1;
    while (fabs(a[j][i]) < eps && j<=n) ++j;
    if (j>n) {
        printf("No Solution\n");
        return;
    }
    if (j<=n) {swap(a[i],a[j]);swap(val[i],val[j]);}
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)  {
        for (int j=1;j<=n;j++) scanf("%lf",&a[i][j]);
        scanf("%lf",&val[i]);
    }
    for (int i=1;i<=n-1;i++) {
        double num=a[i][i];
        if (fabs(num)<eps)  swapline(i);
        for (int j=i+1;j<=n;j++) {
            if (fabs(a[j][i])<=eps) continue;//当此行主元a[i][i]=0时交换行
            double w=-a[j][i]/num; a[j][i]=0;
            for (int k=i+1;k<=n;k++) a[j][k]+=a[i][k]*w;
            val[j]+=val[i]*w;
        }
    }//求上三角矩阵
    for (int i=1;i<=n;i++) {
        bool flag=true;
        for (int j=1;j<=n;j++)
         if (fabs(a[i][j])>eps) {
            flag=false;break;
         }
        if (flag) {
            printf("No Solution\n");
            return 0; //判断是否无解或有多组解
        }
    }
    val[n]=val[n]/a[n][n];//求出第n个元
    for (int i=n-1;i>=1;i--) {
        double sum=0;
        for (int j=n;j>=i+1;j--) sum=sum+a[i][j]*val[j];
        val[i]=(val[i]-sum)/a[i][i];
    }//代入已知元求出未知的一个元
    for (int i=1;i<=n;i++) printf("%.2lf\n",val[i]);
    return 0;
}
