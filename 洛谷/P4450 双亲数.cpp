#include <bits/stdc++.h>
using namespace std;
namespace r { char c; int m; }
namespace p {
	int a[10], l;
	int p[168] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
		73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
		127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
		233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 
		353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 
		467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 
		547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 
		607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 
		739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 
		811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 
		877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 
		947, 953, 967, 971, 977, 983, 991, 997, 
	};
}
#define gcd(a,b) __gcd(a,b)
#define isNum(x) ('0' <= x && x <= '9')
#define read(x) do{ \
	x = 0, r::c = getchar(), r::m = 1; \
	while (!isNum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::c = getchar(), r::m == 1; \
	while (isNum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)
int a, b, d, aa, bb, ta, tb, x;
long long ans = 0;
inline long long calc(int m, int n, int *a) {
	int b[10], sum, mul;
	long long ans = m;
	memset(b, 0, sizeof(b));
	for (int i = 1; i < (1 << n); i++) {
		++b[1];
		for (int i = 1; i <= n; i++)
			if (b[i] > 1) 
				b[i] = 0, ++b[i + 1];
			else break;
//		for (int i = 1; i <= n; i++)
//			cout << b[i];
//		cout << endl;
		
		sum = 0, mul = 1;
		for (int i = 1; i <= n; i++)
			if (b[i]) {
				++sum;
				mul *= a[i];
				if (mul > m)
					break;
			}
		if (sum % 2) ans -= m / mul;
		else ans += m / mul;
	}
//	cout << ans << endl;
	return ans;
}
int main() {
//	freopen("parents.in", "r", stdin);
//	freopen("parents.out", "w", stdout);
	int tt[] = {0, 2, 3, 5};
	calc(21, 3, tt);
	read(a); read(b); read(d);
	ta = a / d, tb = b / d;
	aa = min(ta, tb), bb = max(ta, tb);
	for (int i = 1; i <= aa; i++) {
		x = i, p::l = 0;
//		cout << "i = " << x << endl;
		for (int j = 0; j < 168; j++)
			if (!(x % p::p[j])) {
				p::a[++p::l] = p::p[j];
				while (!(x % p::p[j])) x /= p::p[j];
			}
		if (x > 1) p::a[++p::l] = x;
//		for (int j = 1; j <= p::l; j++)
//			cout << p::a[j] << " ";
//		cout << endl << endl;
		ans += calc(bb, p::l, p::a);
	}
	printf("%lld\n", ans);
	return 0;
}