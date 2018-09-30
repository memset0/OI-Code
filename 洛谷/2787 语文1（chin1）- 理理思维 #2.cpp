#include<bits/stdc++.h>
//using namespace std;
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	register char ch;
	while (ch = getc(), !isupper(ch) && !islower(ch));
	x = ch;
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

#define MAXN 100005
char s[MAXN];
int n,m,nn;
struct aa
{
    int l,r,rr;
    char v;
}a[MAXN*30];
int c[50];

void fen(int i,int x)
{
    nn ++;
    a[nn].rr = a[i].rr;
    a[nn].r = a[i].r;
    a[nn].l = x;
    a[nn].v = a[i].v; 
    a[i].rr = nn;
    a[i].r = x-1;
} 

void cha(int i,int l,int r,char v)
{
    nn ++;
    a[nn].rr = a[i].rr;
    a[nn].l = l;
    a[nn].r = r;
    a[nn].v = v;
    a[i].rr = nn; 
} 

int paix(int l,int r,int p,char ch)
{
    memset(c,0,sizeof(c));
    for(int i = n+1; i != 0; i = a[i].rr)
    {
        if(a[i].l < l && a[i].r >= l) fen(i,l); 
        if(a[i].l <= r && a[i].r > r) fen(i,r+1);
    }
    bool t = 0;
    int lp,rp;
    
    for(int i = n+1; i != 0; i = a[i].rr)
    {
        if(a[i].l >= l && a[i].r <= r)
        {
            if(p == 2)
                a[i].v = ch; 
            c[a[i].v-'a'] += a[i].r - a[i].l + 1;
            t = 1;
        }
        else
        {
            if(t)
            {
                rp = i;
                break;
            }
            else lp = i;
        }
    }
    if(p == 2)
    {
    for(int i = n+1; i != 0; i = a[i].rr)
    {
    //	cout<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
        while(a[i].v == a[a[i].rr].v && a[i].rr != 0)
        {
            a[i].r = a[a[i].rr].r;
            a[i].rr = a[a[i].rr].rr;
        }
    }
        return 0;
    }
    //for(int i = 1; i <= 10; i ++)
    //	cout<<c[i]<<"\n"; 
    if(p == 1)
    {
    for(int i = n+1; i != 0; i = a[i].rr)
    {
    //	cout<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
        while(a[i].v == a[a[i].rr].v && a[i].rr != 0)
        {
            a[i].r = a[a[i].rr].r;
            a[i].rr = a[a[i].rr].rr;
        }
    }
        return c[ch-'a'];
    }
    int u = a[lp].r,x = lp;
    for(int i = 0; i <= 26; i ++)
    if(c[i] != 0)
    {
        nn ++;
        a[x].rr = nn;
        x = nn;
        a[nn].v = 'a' + i;
        a[nn].l = u+1;
        a[nn].r = u + c[i];
        u += c[i];
    }
    
    a[x].rr = rp;
    for(int i = n+1; i != 0; i = a[i].rr)
    {
    //	cout<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
        while(a[i].v == a[a[i].rr].v && a[i].rr != 0)
        {
            a[i].r = a[a[i].rr].r;
            a[i].rr = a[a[i].rr].rr;
        }
    }
    return 0;
} 


int main()
{
    read(n), read(m);
    scanf("%s",s+1);
    for(int i = 1; i <= n; i ++)
    {
        if(s[i] <= 'Z' && s[i] >= 'A')
            s[i] = s[i] -'A' + 'a';
        a[i].l = i;
        a[i].r = i;
        a[i].v = s[i];
        if(i != n)
            a[i].rr = i+1;
    }
    a[n+1].rr = 1;
    a[n].rr = n+2;
    nn = n+2;
    for(int i = n+1; i; i = a[i].rr)
    {
    //	cout<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
        while(a[i].v == a[a[i].rr].v && a[i].rr != 0)
        {
            a[i].r = a[a[i].rr].r;
            a[i].rr = a[a[i].rr].rr;
        }
    }
    for(int i = 1; i <= m; i ++)
    {
        int l,r,opt;
        char s;
        read(opt);
        if(opt == 1)
        {
            read(l), read(r), readc(s);
            if (s < 'a') s = s  - 'A'+ 'a';
            print(paix(l,r,1,s), endl);
        } else if(opt == 2)
        {
            read(l), read(r), readc(s);
            if(s < 'a') s = s - 'A' +  'a';
            paix(l,r,2,s);
        } else
        {
            read(l), read(r);
            paix(l,r,0,'a');
        }
    }
    return 0;
}
