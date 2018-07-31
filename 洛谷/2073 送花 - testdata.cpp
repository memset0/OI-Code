#include <bits/stdc++.h>
using namespace std;
int h1(int i)
{
    //return (i*(sqrt(5) + 1) / 2 - (int)(i*(sqrt(5) + 1) / 2)) * 3 + 1;
    return(rand()%5+1);
}
int main()
{
    int t = 0;
    int a;
    FILE *fp = fopen("1.txt", "wt");
    for (t = 0; t < 100; t++)
    {
        a = h1(t);
        if (a == 1 || a == 4 || a == 5)
        {
            fprintf(fp,"%d %d %d\n", 1, rand(),rand());
        }
        else
            fprintf(fp,"%d\n", a);
    }
    fclose(fp);
}
