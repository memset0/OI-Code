#include <bits/stdc++.h> 
#define MAXN 10
using namespace std;
using namespace std;
int a[MAX], book[MAX], out[MAX], N, Ans;
void dfs(int x){
    //判断退出条件
    if (x > N) {
        ++Ans;
        for (int i = 1; i <= N; i++){
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    //当下怎么走
    for (int i = 1; i <= N; i++){
        if (book[i]) continue;
        book[i] = 1;
        out[x] = a[i];     
        dfs(x + 1);
        book[i]= 0;
    }
}
int main()
{
    cin >> N;
    for (int i =1; i <= N; i++){
        cin >> a[i];     
    }
    //数据初始化
    Ans = 0;
    for (int i = 1; i <= N; i++){
        book[i] = out[i] = 0;
    }
    cout << "Case #" << t << endl;
    //递归函数调用
    dfs(1);

    //输出结果
    cout << Ans << endl;
    return 0;
}
