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
	char s[4];
	scanf("%s",s+1);
	char a=s[1],b=s[2],c=s[3],t;
	if (a>b) {t=a;a=b;b=t;}
	if (a>c) {t=a;a=c;c=t;}
	if (b>c) {t=b;b=c;c=t;}
	printf("%c%c%c",a,b,c);
	return 0;
}

