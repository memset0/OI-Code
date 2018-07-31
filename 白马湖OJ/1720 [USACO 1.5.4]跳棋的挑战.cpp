#include <iostream>
 
#include <vector>
 
using namespace std;
 
 
 
 
 
typedef unsigned long long ULL;//最多支持64皇后
 
 
 
ULL n = 8;
 
ULL ANS;
 
ULL ans = 0;
 
 
 
vector<vector<ULL> > aa;
 
void dfs ( ULL col, ULL diag1, ULL diag2, vector<ULL> &a )
 
{
 
    if ( col == ANS )
 
    {
 
        if ( aa.size() < 3 )
 
            aa.push_back ( a );//存答案
 
        ++ans;
 
        return;
 
    }
 
    ULL can_put = ANS & ~ ( col | diag1 | diag2 );//可以放的位置是1
 
    while ( can_put )
 
    {
 
        ULL curcol = can_put & ( -can_put ) ;//取最低位的1，由于每次选择最低位，所以答案以字典序出现
 
        can_put &= ~curcol;//可以放的删去当前选择的
 
        a.push_back ( curcol );//压入答案
 
        dfs ( col | curcol, ( diag1 | curcol ) << 1 & ANS, ( diag2 | curcol ) >> 1, a );
 
        a.pop_back ( );//回溯
 
    }
 
}
 
 
 
int main()
 
{
 
    cin >> n;
 
    ANS = ( 1 << n ) - 1;
 
    vector<ULL> tmp;
 
    dfs ( 0, 0, 0, tmp );
 
    for ( unsigned i = 0; i < aa.size(); ++i )
 
    {
 
        for ( unsigned j = 0; j < n; ++j )
 
        {
 
            ULL k = aa[i][j];
 
            int l = 1;
 
            while ( k >>= 1 )//统计解答中1的位置
 
                ++l;
 
            cout << l << " ";
 
        }
 
        cout << endl;
 
    }
 
 
 
    cout << ans << endl;
 
    return 0;
 
}