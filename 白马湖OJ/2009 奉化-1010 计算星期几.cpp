//一曲新词酒一杯，去年天气旧亭台，夕阳西下几时回？
//无可奈何花落去，似曾相识燕归来，小园香径独徘徊。
//——《浣溪沙》 晏殊
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n=(n+1)%7;
	char s[40];
	switch (n)
	{
		case 0:cout<<"Sunday";break;
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thursday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
	}
	cout<<endl;
	return 0;
}
