#include <bits/stdc++.h>
#define infinitesimal  -2100000000

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-20
 *  @Time: 19:22
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 3015
int n;
pair<int, int> strap[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int dp[maxn][maxn];

int main() {
    scanf("%d", &n);
    loop(i, 1, n) {
        scanf("%d%d", &strap[i].first, &strap[i].second);
    }
    sort(strap + 1, strap + n + 1, cmp);
    loop(i, 0, n) {
        dp[0][i] = infinitesimal;
        dp[i][n + 1] = infinitesimal;
    }
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][max(0, j - strap[i].first) + 1] + strap[i].second);
        }
    }
    int ans = infinitesimal;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}