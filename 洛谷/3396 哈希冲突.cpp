#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

char readc() {
	char c = getchar();
	while (c != 'A' && c != 'C') c = getchar();
	return c;
}

const int maxn = 150010;

int n, m, x, y, k, sum, sqn, tmp;
char opt;
int a[maxn], f[400][maxn];

namespace FastIO {
    const int str=1<<22;
    const char* endl="\n";
    struct Reader {
        char buf[str],*s,*t;
        Reader():s(buf),t(buf) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        Reader& operator>>(char& c) {
            do c=gt();
            while(c!='A'&&c!='C');
            return *this;
        }
        template<typename T>Reader&operator>>(T&x) {
            register char c=0,d;
            while((c<'0'||c>'9'))d=c,c=gt();
            x=0;
            while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=gt();
            if(d=='-')x=-x;
            return *this;
        }
    } cin;
    struct Writer {
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {
            fwrite(buf,1,s-buf,stdout);
        }
        inline void pt(char c) {
            (s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);
        }
        template<typename T>Writer&operator<<(T x) {
            if(!x)return pt('0'),*this;
            if(x<0)pt('-'),x=-x;
            register char a[30],t=0;
            while(x)a[t++]=x%10,x/=10;
            while(t--)pt(a[t]+'0');
            return *this;
        }
        Writer&operator<<(const char*s) {
            while(*s)pt(*s++);
            return *this;
        }
    } cout;
}
using FastIO::cin;
using FastIO::cout;
using FastIO::endl;


int main() {

	cin >> n >> m;
	sqn = pow(n, 0.33);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++) {
		cin >> opt;
		if (opt == 'A') {
			cin >> x >> y;
			if (x <= sqn) {
				if (!f[x][y]) {
					sum = 0;
					for (int i = y; i <= n; i += x)
						sum += a[i];
					f[x][y] = sum;
				} else sum = f[x][y];
			} else {
				sum = 0;
				for (int i = y; i <= n; i += x)
					sum += a[i];
			}
			cout << sum << endl;
		} else {
			cin >> k >> x;
			tmp = x - a[k];
			for (int i = 1; i <= sqn; i++)
				if (f[i][k % i])
					f[i][k % i] += tmp;
			a[k] = x;
		}
	}

	return 0;
}

