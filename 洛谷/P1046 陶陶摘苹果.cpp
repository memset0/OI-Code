#include <iostream>
using namespace std;
int height[20],H,s;
int main()
{
    for(int i=0;i<10;i++)cin >> height[i];
    cin >> H;
    H += 30;
    for(int i=0;i<10;i++)s+=!(H<height[i]);
    cout << s;
}