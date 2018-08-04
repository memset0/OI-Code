#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
const double q=acos(-1.0);
int n,m,l,limit=1,r[N];
struct Complex{double a,b;Complex(double xx=0,double yy=0){a=xx,b=yy;}}a[N],b[N];
Complex operator + (Complex a,Complex b) {return Complex(a.a+b.a,a.b+b.b);}
Complex operator - (Complex a,Complex b) {return Complex(a.a-b.a,a.b-b.b);}
Complex operator * (Complex a,Complex b) {return Complex(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);}
void FFT(Complex *A,int p)
{
    for(int i=0;i<limit;i++) if(i<r[i]) swap(A[i],A[r[i]]);
    for(int mid=1;mid<limit;mid=mid<<1)
    {
        Complex Wn=(cos(q/mid),p*sin(q/mid));
        for(int R=mid<<1,j=0;j<limit;j=j+R)
        {
            Complex w(1.0,0.0);
            for(int k=0;k<mid;k++,w=w*Wn)
            {
                Complex x=A[j+k],y=w*A[j+k+mid];
                A[j+k]=x+y,A[j+k+mid]=x-y;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) scanf("%lf",&a[i].a);
    for(int i=0;i<=m;i++) scanf("%lf",&b[i].a);
	for (int i = 0; i < n; i++)
		printf("(%.2lf, %.2lf)", a[i].a, a[i].b);
	puts("");
	for (int i = 0; i < n; i++)
		printf("(%.2lf, %.2lf)", b[i].a, b[i].b);
	puts("");
    while(limit<n+m) limit=(limit<<1),l++;
	cout<<limit<<" " << l<<endl;
    for(int i=0;i<limit;i++)
        r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    FFT(a,1),FFT(b,1);
	for (int i = 0; i < n; i++)
		printf("(%.2lf, %.2lf)", a[i].a, a[i].b);
	puts("");
	for (int i = 0; i < n; i++)
		printf("(%.2lf, %.2lf)", b[i].a, b[i].b);
	puts("");
    for(int i=0;i<limit;i++) a[i]=a[i]*b[i];
    FFT(a,-1);
    for(int i=0;i<=n+m;i++) printf("%d ",int(a[i].a/limit+0.5));
}