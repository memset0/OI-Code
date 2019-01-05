#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void dfs(string M,string L){
    int len=M.length();  //这是确定子树的周长。
    if (len<=1){  //如果这棵树只是一个单节点或是空树，直接输出就好了
        cout << M;
        return;
    }
    int u=M.find(L[len-1]);  //找到根在中序遍历中的位置。
    cout << M[u];
    dfs(M.substr(0,u),L.substr(0,u));   //找到左边的子树
    dfs(M.substr(u+1,len-u-1),L.substr(u,len-1-u));  //找到右边的子树
}
int main()
{
    string mid, last;
    cin >> mid >> last;
    dfs(mid, last);
    return 0;
}