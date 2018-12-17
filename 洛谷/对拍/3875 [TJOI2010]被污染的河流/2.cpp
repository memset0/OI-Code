#include <bits/stdc++.h>
using namespace std;

namespace wxw {
    typedef long long ll;
    const int N = 10000 + 10;
    
    struct ele {
        int l, r, h, v;
        bool operator < (const ele a) const {
            return h < a.h || (h == a.h && v > a.v);
        }
    }Q[N << 1];
    
    int sum[N << 3], tag[N << 3];
    int x1[N], y1[N], x2[N], y2[N], pre[N << 1];
    long long ans = 0;
    int n, tot = 0;
    
    void update(int u, int l, int r) {
        /*cout << "update : ";
        cout << l << " " << r << endl;*/
        if(tag[u]) sum[u] = pre[r + 1] - pre[l];
        else if(l != r) sum[u] = sum[u << 1] + sum[u << 1 | 1];
        else sum[u] = 0;
    }
    
    void change(int u, int l, int r, int L, int R, int v) {
        if(l <= L && R <= r) {
            tag[u] += v;
            update(u, L, R);
            return;
        }
        int mid = (L + R) >> 1;
        if(mid >= l) change(u << 1, l, r, L, mid, v);
        if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, v);
        update(u, L, R);
    }
    
    void main() {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x, y, _x, _y;
            scanf("%d %d %d %d", &x, &y, &_x, &_y);
            x1[i] = min(x, _x), y1[i] = min(y, _y);
            x2[i] = x + _x - x1[i], y2[i] = y + _y - y1[i];
            if(x == _x) x1[i]--, x2[i]++;
            else if(y == _y) y1[i]--, y2[i]++;
            Q[++tot] = (ele) {x1[i], x2[i], y1[i], 1}; pre[tot] = x1[i];
            Q[++tot] = (ele) {x1[i], x2[i], y2[i], -1}; pre[tot] = x2[i];
        }
        sort(Q + 1, Q + tot + 1); sort(pre + 1, pre + tot + 1);
        for(int i = 1; i <= tot; i++) {
            int l = lower_bound(pre + 1, pre + tot + 1, Q[i].l) - pre;
            int r = lower_bound(pre + 1, pre + tot + 1, Q[i].r) - pre - 1;
            /*cout << "solve : ";
            cout << l << " " << r << endl;*/
            int tmp = sum[1]; if(l <= r) change(1, l, r, 1, tot, Q[i].v);
            ans += (ll)tmp * (ll)(Q[i].h - Q[i - 1].h);
        }
        cout << ans << endl;
    }
}

int main() {
	freopen("3.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
    wxw :: main();
    return 0;
}
