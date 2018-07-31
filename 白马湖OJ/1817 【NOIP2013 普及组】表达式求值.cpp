#include <bits/std++.h>
using namespace std;
const int maxn = 100000 + 100000;
struct Num {
	int len = 0;
	int a[maxn];
	inline void pop(int n) {
		a[++len] = n;
	}
	inline int push() {
		return a[len--];
	}
};
struct Cal {
	int len = 0;
	char a[maxn];
	inline void pop(char n) {
		a[++len] = n;
	}
	inline char push() {
		return a[len--];
	}
};
int main()
{
	
}
