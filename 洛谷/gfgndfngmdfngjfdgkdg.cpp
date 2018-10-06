#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1e6 + 10;
using namespace std;
char s[MAXN];
int N, M, rak[MAXN], sa[MAXN], tax[MAXN], tp[MAXN];
void Debug() {
    printf("*****************\n");
    printf("下标"); for(int i = 1; i <= N; i++) printf("%d ", i);     printf("\n");
    printf("sa  "); for(int i = 1; i <= N; i++) printf("%d ", sa[i]); printf("\n");
    printf("rak "); for(int i = 1; i <= N; i++) printf("%d ", rak[i]);printf("\n");
    printf("tp  "); for(int i = 1; i <= N; i++) printf("%d ", tp[i]); printf("\n");
}
void Qsort() {
    for(int i = 0; i <= M; i++) tax[i] = 0;
    for(int i = 1; i <= N; i++) tax[rak[i]]++;
    for(int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for(int i = N; i >= 1; i--) sa[ tax[rak[tp[i]]]-- ] = tp[i];
    //这部分我的文章的末尾详细的说明了 
}
void SuffixSort() {
    M = 75;
    for(int i = 1; i <= N; i++) rak[i] = s[i] - '0', tp[i] = i;
    Qsort();
    Debug();
    for(int w = 1, p = 0; p < N; M = p, w <<= 1) {
        //w:当前倍增的长度，w = x表示已经求出了长度为x的后缀的排名，现在要更新长度为2x的后缀的排名
        //p表示不同的后缀的个数，很显然原字符串的后缀都是不同的，因此p = N时可以退出循环 
        p = 0;//这里的p仅仅是一个计数器 
        for(int i = 1; i <= w; i++) tp[++p] = N - w + i;
        for(int i = 1; i <= N; i++) if(sa[i] > w) tp[++p] = sa[i] - w;//这两句是后缀数组的核心部分，我已经画图说明 
        for (int i = 1; i <= p; i++) 
        	printf("%d ", tp[i]); puts("");
        Qsort();//此时我们已经更新出了第二关键字，利用上一轮的rak更新本轮的sa 
        std::swap(tp, rak);//这里原本tp已经没有用了 
        rak[sa[1]] = p = 1;
        for(int i = 2; i <= N; i++)
            rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
        //这里当两个后缀上一轮排名相同时本轮也相同，至于为什么大家可以思考一下 
        Debug();
    }
    for(int i = 1; i <= N; i++)
        printf("%d ", sa[i]);
}
int main() {
	freopen("INPUT", "r", stdin);
    scanf("%s", s + 1);
    N = strlen(s + 1);
    SuffixSort();
    return 0;
}
