#include <bits/stdc++.h>
using namespace std;
const string s2i[21] = { "zero",
	"one", "two", "three", "four", "five", 
	"six", "seven", "eight", "nine", "ten", 
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", 
	"sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};
string s;
int cge[30];
int n = 0, a[10];
int main() {
	for (int i = 0; i <= 20; i++) cge[i] = (i * i) % 100;
	cin >> s;
	while (s != ".") {
		if (s == "a" || s == "another" || s == "first") a[++n] = cge[1];
		else if (s == "both" || s == "second") a[++n] = cge[2];
		else if (s == "third") a[++n] = cge[3];
		else 
			for (int i = 1; i <= 20; i++)
				if (s == s2i[i]) a[++n] = cge[i];
		cin >> s;
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << a[i] << endl;
	// }
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i == 1) printf("%d", a[i]);
		else printf("%02d", a[i]);
	}
	if (!n) printf("0\n");
	else puts("");
	return 0;
}
