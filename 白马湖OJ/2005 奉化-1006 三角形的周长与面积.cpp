//一曲新词酒一杯，去年天气旧亭台 ，夕阳西下几时回？
//无可奈何花落去，似曾相识燕归来，小园香径独徘徊。
//——《浣溪沙》 晏殊
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	float a,b,c,l,s,p;
	cin>>a>>b>>c;
	l=a+b+c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.2lf %.2lf",l,s);
	return 0;
}

