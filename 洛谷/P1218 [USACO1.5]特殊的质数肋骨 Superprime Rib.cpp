// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int a[4]={2,3,5,7};
int b[4]={1,3,7,9};

int n;
bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) 
    	if(x % i == 0) 
    		return false; 
    return true; 
}

void dfs(int s, int i) { 
    int ss; 
    if (i == n) {
        cout << s << endl;
        return;
    }
    for (int j = 0; j < 4; j++) {
        ss = s * 10 + b[j];
        if(is_prime(ss)) 
			dfs(ss, i + 1);
    } 
} 
int main() {
    n = read();
    if (n == 1)
		printf("2\n3\n5\n7\n");
    else { 
        for(int i = 0; i < 4; i++)
        	dfs(a[i], 1);
    } 
    return 0;
}