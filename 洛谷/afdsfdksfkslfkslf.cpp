#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
char map[40][40];
int n,m,k;
char s[40];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %c", &map[i][j]);
    scanf("%d", &k);
    while(k--)
    { 
        bool flag=false;
        bool real_flag=false;
        int temp=0;
        scanf(" %s", s);
        for(int i=0;i<n;i++)
        {
            temp=0;
            flag=false;
            for(int j=0;j<m;j++)
            {
                if(temp==strlen(s)-1 && s[temp]==map[i][j])
                {
                    real_flag=true;
                    break;
                }
                if(!real_flag && flag==true && s[temp]!=map[i][j])
                {
                    flag=false; 
                    temp=0;
                }
                if(!real_flag && flag==true && s[temp]==map[i][j])
                {
                    temp++;
                }
                if(!real_flag && map[i][j]==s[0])
                {
                    flag=true;
                    temp=1;
                }
            }
        }
        if(real_flag==true)
        {
            printf("YES\n");
            continue;
        }
        flag=false;
        real_flag=false;
        temp=0;
        for(int i=0;i<m;i++)
        {
            temp=0;
            flag=false;
            for(int j=0;j<n;j++)
            {
                if(temp==strlen(s)-1 && s[temp]==map[j][i])
                {
                    real_flag=true;
                    break;
                }
                if(!real_flag && flag==true && s[temp]!=map[j][i])
                {
                    flag=false; 
                    temp=0;
                }
                if(!real_flag && flag==true && s[temp]==map[j][i])
                {
                    temp++;
                }
                if(!real_flag && map[j][i]==s[0])
                {
                    flag=true;
                    temp=1;
                }
            }
        }
        if(real_flag==true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
