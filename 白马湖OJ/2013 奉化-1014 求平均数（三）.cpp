#include <bits/stdc++.h>
using namespace std;
double t, s = 0;
int i = 0;
int main() {
	while (scanf("%lf", &t) != EOF) {
		i++;
		s += t;
	}
	printf("%.4lf", s / i);
	return 0;
} 
