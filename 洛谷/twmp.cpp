#include<cstdio>
#include<cmath>

const double EPS=1E-8;
double B[110][110];
int n;

int main(){
    scanf("%d",&n);
    for (register int i=0;i<n;i++){
        for (register int j=0;j<n;j++)
            scanf("%lf",&B[i][j]);//读入系数
        scanf("%lf",&B[i][n]);//读入值
    }
    for (register int i=0;i<n;i++){
        int pivot=i;
        for (register int j=i;j<n;j++)//选择一个当前位置系数绝对值最大的调换过来，防止误差
            if (fabs(B[j][i]-B[pivot][i])<=EPS) pivot=j;
        for (register int j=0;j<=n;j++){//交换操作，要将所有的全部交换过来
            double t=B[i][j];
            B[i][j]=B[pivot][j];
            B[pivot][j]=t;
        }
        if (fabs(B[i][i])<=EPS){//如果该位置系数等于零，则0x=a，一定无解
            printf("No Solution\n");
            return 0;
        }
        for (register int j=i+1;j<=n;j++) B[i][j]/=B[i][i];//将该位的系数变为1
        for (register int j=0;j<n;j++)
            if (i!=j)
                for (register int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];//将其他方程用加减法减去系数值
    }
    for (register int i=0;i<n;i++) printf("%.2lf\n",B[i][n]);//最后输出结果。
    return 0;
}
