#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

int map[251][251],n,m,cnt[251][251][26];
long long hash[251][251][251],P=1000000007,ans;
bool isp[251][251][251];
char get(){
	char opt=getchar();
	while(opt<'a'||opt>'z')opt=getchar();
	return opt-'a';
}
long long p[230001],tot,l,id,mx,str[230001];
int manacher(int i,int j,int L,int r){
	l=0;
	for(int k=L;k<=r;k++){
		str[++l]=-1;
		str[++l]=hash[i][j][k];
	}
	str[0]=-2;
	str[++l]=-1;
	id=0;mx=0;
	tot=0;
//	printf("%s",str+1);
	for(int k=1;k<l;k++){
		if(k<mx)p[k]=std::min(p[2*id-k],mx-k);
		else	p[k]=1;
		while(str[k-p[k]]==str[k+p[k]])p[k]++;
		if(mx<k+p[k]){
			id=k;
			mx=k+p[k];
		}
		tot+=(p[k]-(str[k]==-1))>>1;
	}
	for(int k=1;k<l;k++)p[k]=0;
	return tot;
}
void main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			map[i][j]=get();
			for(int k=0;k<26;k++)cnt[i][j][k]=cnt[i][j-1][k];
			cnt[i][j][map[i][j]]++;
		}
	for(register int i=1;i<=m;++i)
		for(register int j=i;j<=m;++j)
			for(register int k=1;k<=n;++k){
				int tot=0;
				for(register int l=0;l<26;++l){
					if((cnt[k][j][l]-cnt[k][i-1][l])%2)tot++;
				}
				if(tot<2)isp[i][j][k]=1;
				else continue;
				for(register int l=0;l<26;l++)hash[i][j][k]=(hash[i][j][k]*6666+(cnt[k][j][l]-cnt[k][i-1][l])*289)%P;
			}
	int last,cnt;
	for(register int i=1;i<=m;++i)
		for(register int j=i;j<=m;++j){
			last=1;
			while(last<=n){
				cnt=last;
				while(isp[i][j][cnt])cnt++;
				cnt--;
				if(last<=cnt)ans+=manacher(i,j,last,cnt);
				last=cnt+2;
			}
		}
	std::cout<<ans;
}

} int main() { return ringo::main(), 0; }}
