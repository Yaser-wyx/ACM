#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 16:27
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 55
#define Mod 1000000007
int n, c;
int lamps[maxn][2];
int dp[maxn][maxn][2];
int pre[maxn][maxn];

int P1220() {
    cin >> n >> c;
    loop(i, 1, n) {
        cin >> lamps[i][0] >> lamps[i][1];
    }
    mset(pre, 0);
    loop(i, 1, n) {
        loop(j, i, n) {
            pre[i][j] += pre[i][j - 1] + lamps[j][1];
        }
    }
    mset(dp, 1);
    dp[c][c][1] = dp[c][c][0] = 0;

    for (int l = c; l >= 1; l--) {
        for (int r = c; r <= n; r++) {
            if (l == r && r == c) {
                continue;
            }
            dp[l][r][0] = min(dp[l + 1][r][0] + (pre[1][l] + pre[r + 1][n]) * (lamps[l + 1][0] - lamps[l][0]),
                              dp[l + 1][r][1] + (pre[1][l] + pre[r + 1][n]) * (lamps[r][0] - lamps[l][0]));//左端
            dp[l][r][1] = min(dp[l][r - 1][0] + (pre[1][l - 1] + pre[r][n]) * (lamps[r][0] - lamps[l][0]),
                              dp[l][r - 1][1] + (pre[1][l - 1] + pre[r][n]) * (lamps[r][0] - lamps[r - 1][0]));//右端
        }

    }
    cout << min(dp[1][n][0], dp[1][n][1]);
    return 0;
}