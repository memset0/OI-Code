#include<iostream>
using namespace std;
int l,r,x,y; 
int a[10]; 
bool b;
bool isprime(int x){
    if(x<2)return false;
    if(x==2)return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int weishu(int j){
    int b=j,count=0;
    while(b>0){
        b/=10;
        count++;
    }
    return count;
}
void go(int x,int k){ 
    if(x==(k+1)/2){ 
        for(int i=k;i>x;i--){
            a[i]=a[k-i+1];
        }
        int shu=0; 
        for(int i=1;i<=k;i++){
            shu=shu*10+a[i];
        }
        if(shu<l)return; 
        if(shu>r){ 
            b=false;
            return;
        }
        if(isprime(shu))cout<<shu<<endl;
        return;
    }
    int i;
    if(x)i=0;
    else i=1; 
    for(i=i;i<=9;i++){
        if(b==false)return;
        a[x+1]=i;
        go(x+1,k);
    }
    return;
}
int main(){
    b=1;
    cin>>l>>r;
    x=weishu(l);
    y=weishu(r);
    for(int i=x;i<=y;i++){
        if(i==1){
            if(l<=5&&r>=5)cout<<5<<endl;
            if(l<=7&&r>=7)cout<<7<<endl;
            continue;
        }
        if(i==2){
            if(l<=11&&r>=11)cout<<11<<endl;
            continue;
        }
        if(i%2==0)continue;
        if(i==9)break;
        b=true;
        go(0,i);
    }
    return 0;
}