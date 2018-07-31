//一曲新词酒一杯，去年天气旧亭台，夕阳西下几时回？
//无可奈何花落去，似曾相识燕归来，小园香径独徘徊。
//——《浣溪沙》 晏殊
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	int a,b,c;
	cin>>n;
	c=n%10; b=n/10%10; a=n/100%10;
	m=c*100+b*10+a;
	cout<<m;
	return 0;
}

