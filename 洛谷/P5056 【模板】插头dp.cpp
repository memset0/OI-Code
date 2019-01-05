// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
    char c = getchar();
    while (c != '*' && c != '.') c = getchar();
    return c;
}

const int maxn = 15;

const int hashModer = 1e6 + 3;
const int maxStatus = 5e5 + 10;

int n, m, a[maxn][maxn];

int p, q, w;
int endN, endM;
int flag, brackets;

ll times[maxn];
ll finalAnswer;

int hashValue;
int hashMap[hashModer];

ll status[2][maxStatus], thisStatus;
ll answer[2][maxStatus], thisAnswer;

void addStatus(ll newStatus, ll newAnswer) {
    hashValue = newStatus % hashModer;
    while (hashMap[hashValue]) {
        if (status[flag][hashMap[hashValue]] == newStatus) {
            answer[flag][hashMap[hashValue]] += newAnswer;
            return;
        }
        hashValue = (hashValue == hashModer) ? 0 : (hashValue + 1);
    }
    status[flag][0]++;
    hashMap[hashValue] = status[flag][0];
    status[flag][status[flag][0]] = newStatus;
    answer[flag][status[flag][0]] = newAnswer;
}

ll getStatus(ll a, ll b, ll c, ll d, ll j, ll thisStatus) {
    thisStatus -= a * (1 << times[j - 1]);
    thisStatus -= b * (1 << times[j]);
    thisStatus += c * (1 << times[j - 1]);
    thisStatus += d * (1 << times[j]);
    return thisStatus;
}

int main() {

    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] = readc() == '*' ? 1 : 0;
            if (!a[i][j]) endN = i, endM = j;
        }

    times[0] = 0;
    for (ll i = 1; i <= max(n, m); i++)
        times[i] = i << 1;

    flag = 0;

    status[flag][0] = 1;
    status[flag][1] = 0;
    answer[flag][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            flag ^= 1;
            memset(hashMap, 0, sizeof(hashMap));
            memset(status[flag],  0, sizeof(status[flag]));
            memset(answer[flag],  0, sizeof(answer[flag]));
            status[flag][0] = 0;

            for (int k = 1; k <= status[flag ^ 1][0]; k++) {

                thisStatus = status[flag ^ 1][k];
                thisAnswer = answer[flag ^ 1][k];

                p = (thisStatus >> times[j - 1]) % 4;
                q = (thisStatus >> times[j]) % 4;

                if (a[i][j]) {
                    if (p == 0 && q == 0) {
                        thisStatus = getStatus(0, 0, 0, 0, j, thisStatus);
                        addStatus(thisStatus, thisAnswer);
                    }
                } else {
                    if (p == 0 && q == 0) {
                        if (!a[i][j + 1] && !a[i + 1][j] && i + 1 <= n && j + 1 <= m) {
                            thisStatus = getStatus(0, 0, 1, 2, j, thisStatus);
                            addStatus(thisStatus, thisAnswer);
                        }
                    } else if (p == 0 && q > 0) {
                        if (!a[i][j + 1] && j + 1 <= m)
                            addStatus(thisStatus, thisAnswer);
                        if (!a[i + 1][j] && i + 1 <= n) {
                            thisStatus = getStatus(0, q, q, 0, j, thisStatus);
                            addStatus(thisStatus, thisAnswer);
                        }
                    } else if (p > 0 && q == 0) {
                        if (!a[i + 1][j] && i + 1 <= n) 
                            addStatus(thisStatus, thisAnswer);
                        if (!a[i][j + 1] && j + 1 <= m) {
                            thisStatus = getStatus(p, 0, 0, p, j, thisStatus);
                            addStatus(thisStatus, thisAnswer);
                        }
                    } else if (p == 1 && q == 1) {
                        brackets = 1;
                        for (int i = j + 1; i <= m; i++) {
                            w = (thisStatus >> times[i]) % 4;
                            if (w == 1) brackets++;
                            if (w == 2) brackets--;
                            if (!brackets) {
                                thisStatus -= 2 * (1 << times[i]);
                                thisStatus += 1 * (1 << times[i]);
                                break;
                            }
                        }
                        thisStatus = getStatus(1, 1, 0, 0, j, thisStatus);
                        addStatus(thisStatus, thisAnswer);
                    } else if (p == 2 && q == 2) {
                        brackets = 1;
                        for (int i = j - 2; i >= 1; i--) {
                            w = (thisStatus >> times[i]) % 4;
                            if (w == 2) brackets++;
                            if (w == 1) brackets--;
                            if (!brackets) {
                                thisStatus -= 1 * (1 << times[i]);
                                thisStatus += 2 * (1 << times[i]);
                                break;
                            }
                        }
                        thisStatus = getStatus(2, 2, 0, 0, j, thisStatus);
                        addStatus(thisStatus, thisAnswer);
                    } else if (p == 1 && q == 2) {
                        if (i == endN && j == endM)
                            finalAnswer += thisAnswer;
                    } else if (p == 2 && q == 1) {
                        thisStatus = getStatus(2, 1, 0, 0, j, thisStatus);
                        addStatus(thisStatus, thisAnswer);
                    }
                }
            }

        }
        for (int t = 1; t <= status[flag][0]; t++)
            status[flag][t] <<= 2;
    }

    printf("%lld\n", finalAnswer);

    return 0;
}