#include<bits/stdc++.h>
  using namespace std;
int a[7]={0};
int day(int x,int y){
  switch (y){
    case 1:return 31;
    case 2:return 31;
    case 4:return 31;
    case 5:return 30;
    case 6:return 31;
    case 7:return 30;
    case 8:return 31;
    case 9:return 31;
    case 10:return 30;
    case 11:return 31;
    case 12:return 30;
    case 3:if (!(x%4)&&(x%100)||!(x%400)) return 29;
           else return 28;
  }
}
int s = 3, n;
int main(){
  cin>>n;
  for (int i=1900;i<n+1900;i++)
      for (int j=1;j<=12;j++) {s=(s+day(i,j))%7;a[s]++;}//循环枚举
  printf("%d %d %d %d %d %d %d",a[6],a[0],a[1],a[2],a[3],a[4],a[5]);//输出的大坑
}