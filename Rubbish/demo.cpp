#include <bits/stdc++.h>
using namespace std;
int read(void);

int main() {
	freopen("filename.in", "r", stdin);
	freopen("filename.out", "w", stdout);
	
	return 0;
}

int ret; char chr; bool mrk;
int read() {
	chr = getchar(), ret = mrk = 0;
	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
	if (chr == '-') mrk = 1, chr = getchar();
	while ('0' <= chr && chr <= '9') ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) return -ret; else return ret;
}
