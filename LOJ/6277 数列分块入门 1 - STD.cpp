//@HelloElwin-20180706
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, bs, A[50005], tag[50005];

int main(){
//	freopen("a.in", "r", stdin);
//	freopen("axx.out", "w", stdout);

	scanf("%d", &n); bs=sqrt(n);
	for (int i=1; i<=n; i++) scanf("%d", &A[i]);
	
	for(int i=0; i<n; i++){
		int opt, l, r, c;
		scanf("%d %d %d %d", &opt, &l, &r, &c);
		if(opt){
			printf("%d\n", A[r]+tag[r/bs]);
		}else{
			if (l <= r) {
				if(l/bs==r/bs){
					for (int j=l; j<=r; j++) A[j]+=c;
					continue;
				}
				int lb=(l-1)/bs+1, rb=(r+1)/bs-1;
				for (int d=l; d<=lb*bs-1; d++) A[d]+=c;
				for (int d=lb; d<=rb; d++) tag[d]+=c;
				for (int d=(rb+1)*bs; d<=r; d++) A[d]+=c;
			}
		}
	}

	return 0;
}
