#include<cstdio>
int main()
{
    int h1,h2,m1,m2;
    scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
    if(m2<m1)
    {
        m2+=60;
        h2--;
    }
    m1=m2-m1;
    h1=h2-h1;
    printf("%d %d",h1,m1);
    return 0;
}