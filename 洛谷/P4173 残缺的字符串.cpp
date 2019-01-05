// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int N, M, cnt;
char S[MAXN], T[MAXN];
bitset<MAXN> B[28];
main() {
    scanf("%d%d%s%s", &M, &N, T + 1, S + 1);
    for(int i = 1; i <= N; i++)
        if (S[i] == '*') {
            for (int j = 0; j < 26; j++)
                B[j].set(i);
        } else B[S[i] - 'a'].set(i);
    bitset<MAXN> ans; ans.set();
    for(int i = 1; i <= M; i++) if(T[i] != '*') ans &= (B[T[i] - 'a'] >> (i - 1));
    for(int i = 1; i <= N - M + 1; i++) if(ans[i] == 1) cnt++; printf("%d\n", cnt);
    for(int i = 1; i <= N - M + 1; i++) if(ans[i] == 1) printf("%d ", i);
}