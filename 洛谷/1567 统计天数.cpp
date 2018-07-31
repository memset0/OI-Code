#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],ans=1,max=1;
    for(int i=0;i<n;i++)
	{
        cin>>a[i];
        if(a[i]<=a[i-1]&&i!=0) ans=1;
        if(a[i]>a[i-1]&&i!=0)
		{ 
            ++ans;
            if(ans>max) max=ans;
        } 
    }
    printf("%d",max);
    return 0;
}
