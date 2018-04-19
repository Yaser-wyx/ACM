#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-19
 *  @Time: 14:24
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 1010
#define maxm 50
int n, m;
int cards[maxn];
int cnt[5];
int dp[maxm][maxm][maxm][maxm];

int P1541() {
    scanf("%d%d", &n, &m);
    loop(i, 1, n) {
        scanf("%d", &cards[i]);
    }
    int temp;
    loop(i, 1, m) {
        scanf("%d", &temp);
        cnt[temp]++;
    }
    mset(dp, 0);
    dp[0][0][0][0] = cards[1];
    loop(a, 0, cnt[1]) {
        loop(b, 0, cnt[2]) {
            loop(c, 0, cnt[3]) {
                loop(d, 0, cnt[4]) {
                    int step = a + b * 2 + c * 3 + d * 4 + 1;
                    if (a != 0)dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + cards[step]);
                    if (b != 0)dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + cards[step]);
                    if (c != 0)dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + cards[step]);
                    if (d != 0)dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + cards[step]);
                }
            }
        }
    }
    printf("%d\n", dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);

    return 0;
}
