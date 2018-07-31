#include<iostream>
using namespace std;
int P[1010], D[1010], Pre[1010];
int W[1010], Hash[1010];
int G[1010][1010];
int Ans, Flow, i, Tmp;
int M, N, S, T, First, End, Min, Adv;
int INF = 10000000;
bool Flag;

int main()
{       
    // freopen("INPUT", "r", stdin);
    scanf("%d%d%d%d", &N, &M, &S, &T);
    for (i = 1; i <= M; i++)
    {
        scanf("%d%d", &First, &End);
        scanf("%d", &G[First][End]);
    }
    Hash[0] = N;
    for (i = 1; i <= N; i++) P[i] = 1;
    i = S;
    Flow = INF;
    Ans = 0;
    while (D[S] < N)
    {
                    // cout << "find ans\n";
        W[i] = Flow;
        Flag = 0;
        for (int j = P[i]; j <= N; j++)
        {
            if (G[i][j] > 0 && D[i] == D[j] + 1)
            {
                Flag = 1;
                P[i] = j;
                if (G[i][j] < Flow) Flow = G[i][j];
                Pre[j] = i;
                i = j;
                if (i == T)
                {
                    Ans += Flow;
                    while (i != S)
                    {
                        Tmp = i;
                        i = Pre[i];
                        G[i][Tmp] -= Flow;
                        G[Tmp][i] += Flow;
                    }
                    Flow = INF;
                }
                break;
            }
        }
        if (Flag) continue;
        Min = N - 1;
        for (int j = 1; j <= N; j++)
            if (G[i][j] && D[j] < Min)
                Adv = j, Min = D[j];
        P[i] = Adv;
        Hash[D[i]]--;
        if (Hash[D[i]] == 0) break;
        D[i] = Min + 1;
        Hash[D[i]]++;   
        if (i != S) i = Pre[i], Flow = W[i];
    }
    printf("%d\n", Ans);
    return 0;
}