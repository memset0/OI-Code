#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d;
	if (d>b) {f=d-b;e=c-a;}
	else {f=d+60-b;e=c-1-a;}
	cout<<e<<" "<<f;
	return 0;
}
