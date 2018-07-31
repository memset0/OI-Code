#include <cstdio> 
using namespace std;
int a[11];
int main()
{
    int n;
    for (int i=1;i<=10;i++) scanf("%d",&a[i]);
    scanf("%d",&n);
    n+=30;
    int s=0;
    for (int i=1;i<=10;i++)
    {
        if (n>=a[i]) s++;
    }
    printf("%d",s);
    return 0;
}
