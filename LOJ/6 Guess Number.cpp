#include<cstdio>
#include "interaction.h"
using namespace std;
int n, l, r, mid, ret;
vector < int > ans;
int main() {
	n = get_num();
	for(int i = 0; i < n; i++) {
		l = 1, r = 1000000;
		while(l <= r) {
			mid = (l + r) >> 1;
			ret = guess(i,mid);
			if(!ret) break;
			if(ret == 1) r = mid - 1;
			else l = mid + 1;
		}
		ans.push_back(mid);
	}
	submit(ans);
	return 0;
}
