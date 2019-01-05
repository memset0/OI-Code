#include<bits/stdc++.h>
using namespace std;
int main() {
    char a[101];
    int s=0;
    for(int i=0;i<12;i++) {
        scanf("%s",a);
        if(strstr(a,"r")) s++;
    }
    printf("%d\n",s);
    return 0;
}