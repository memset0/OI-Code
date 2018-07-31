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
	int a,b,c,min;
	cin>>a>>b>>c;
	min=a;
	if (min>b) min=b;
	if (min>c) min=c;
	cout<<min;
	return 0;
}
