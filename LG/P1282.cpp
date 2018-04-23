#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-19
 *  @Time: 09:40
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 1010
#define INF 0xfffffff
int n;
pair<int, int> dominoes[maxn];
int dp[maxn][maxn << 3];

int P1282() {
    scanf("%d", &n);
    int a, b;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        dominoes[i].first = a;
        dominoes[i].second = b;
        sum += a + b;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * 6; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][dominoes[1].first] = 0;
    dp[1][dominoes[1].second] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n * 6; j++) {
            if (j >= dominoes[i].first) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - dominoes[i].first]);
            }
            if (j >= dominoes[i].second) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - dominoes[i].second] + 1);
            }
        }
    }
    int dis = INF;
    int ans = INF;
    for (int up = 1; up <= sum; up++) {
        int down = sum - up;
        if (dis > abs(up - down)) {
            dis = abs(up - down);
            ans = dp[n][up];
        }/* else if (abs(up - down) == dis) {
            ans = min(ans, dp[n][up]);
        }*/
    }
    printf("%d\n", ans);
    return 0;
}