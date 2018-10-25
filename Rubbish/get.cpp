#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 110;
char s[maxn][maxm];
char file_name_in[10][10] = {
	"data0.in", "data1.in", "data2.in", "data3.in", "data4.in",
	"data5.in", "data6.in", "data7.in", "data8.in", "data9.in"
};
char file_name_out[10][10] = {
	"data0.out", "data1.out", "data2.out", "data3.out", "data4.out",
	"data5.out", "data6.out", "data7.out", "data8.out", "data9.out"
};
int main() {
	freopen("data.txt", "r", stdin);
	int l = 1; gets(s[l]);
	while (s[l][0] != '*') gets(s[++l]);
	cout << s[1][0] << "*" << s[2][0] << endl;
	fclose(stdin);
	freopen("data.check.txt", "w", stdout);
	for (int i = 1; i <= l; i++)
		printf("%s\n", s[i]);
	fclose(stdout);
	cout << s[1][0] << "*" << s[2][0] << endl;
	int i = 0, j = 0;
	while (j <= l) {
		freopen(file_name_in[i], "w", stdout);
		while (s[j][0] != '<' && j <= l) j++, cout << s[j][0];
		cout << j;
		while (s[j][0] == '<') {
			for (int i = 2; i < strlen(s[j]); i++)
				putchar(s[j][i]);
			puts("");
			j++;
		}
		cout << j;
		fclose(stdout);
		freopen(file_name_out[i], "w", stdout);
		while (s[j][0] != '>' && j <= l) j++;
		cout << j;
		while (s[j][0] == '>') {
			for (int i = 2; i < strlen(s[j]); i++)
				putchar(s[j][i]);
			puts("");
			j++;
		}
		cout << j;
		fclose(stdout);
	}
	return 0;
} 
