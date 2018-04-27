#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 11:30
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1005
#define maxm 10005
int n, b, k, t, x, y;
int matrix[maxn][maxn];
int dp[maxn][maxn];

int main() {
    mset(matrix, 0);
    mset(dp, 0);

    cin >> n >> t;
    loop3(i, 0, t) {
        cin >> x >> y;
        matrix[x][y] = 1;
    }
    int ans = 0;
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (!matrix[i][j]) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
