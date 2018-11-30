#include <bits/stdc++.h>

using namespace std;

int main() {

	system("g++-7 2_data.cpp -o tmp/data.exe -O2");
	system("g++-7 2.cpp -o tmp/1.exe -O2");
	system("g++-7 2_2.cpp -o tmp/2.exe -O2");

	int cnt = 0;

	while (true) {

		cnt++;

		system("./tmp/data.exe > tmp/data.in");
		system("./tmp/1.exe < tmp/data.in > tmp/runner1.out");
		system("./tmp/2.exe < tmp/data.in > tmp/runner2.out");

		if (system("diff tmp/runner1.out tmp/runner2.out -w -B")) {

			printf("Wrong Answer in [%d]\n", cnt);

			char opt = cin.get();
			if (opt == 'x')
				break;

		} else {

			printf("Accepted in [%d]\n", cnt);

		}

	}

}
