//一曲新词酒一杯，去年天气旧亭台，夕阳西下几时回？
//无可奈何花落去，似曾相识燕归来，小园香径独徘徊。
//——《浣溪沙》 晏殊
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int year,mouth,day;
	cin>>year>>mouth;
	bool b;
	if ((year%4==0)&&(year%100!=0)||(year%400==0)) b=true; else b=false;
	switch (mouth)
	{
		case 2:if (b==true) day=29; else day=28;break;
		case 4:day=30;break;
		case 6:day=30;break;
		case 9:day=30;break;
		case 11:day=30;break;
		default:day=31;break;
	}
	printf("%d",day);
	return 0;
}
