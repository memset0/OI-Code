#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int L[N],R[N],st[N],h[N];
int n;
int main(){
     while(cin>>n){
        for(int i=0;i<n;i++) cin>>h[i];
        int t=0;
        for(int i=0;i<n;i++){
             while(t>0&&h[st[t-1]]>=h[i]) t--;
             L[i]=t==0?-1:st[t-1];
                st[t++]=i  ;
        }

        t=0;
        for(int i=n-1;i>=0;i--){
             while(  t>0   &&   h[st[t-1]]>=h[i]  )   t--   ;
             R[i]=   t==0?n:st[t-1]  ;
             st[t++]=i	     ;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(long long)    h[i]*(R[i]-L[i]-1) );
        }
       cout<<ans<<endl;
     }
     return 0;
} 

