#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 11:54
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
#define maxn 808
#define Mod 1000000007

int n, m, k;
int dp[2][20][maxn][maxn];
int matrix[maxn][maxn];

int P1373() {

    cin >> n >> m >> k;
    k++;
    mset(dp, 0);
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin >> matrix[i][j];
            dp[0][matrix[i][j] % k][i][j] = 1;
        }
    }

    loop(i, 1, n) {
        loop(j, 1, m) {
            loop(h, 0, k) {
                dp[0][h][i][j] +=
                        (dp[1][(h - matrix[i][j] + k) % k][i - 1][j] + dp[1][(h - matrix[i][j] + k) % k][i][j - 1]) %
                        Mod;
                dp[1][h][i][j] +=
                        (dp[0][(h + matrix[i][j]) % k][i - 1][j] + dp[0][(h + matrix[i][j]) % k][i][j - 1]) %
                        Mod;
            }
        }
    }
    lli ans = 0;
    loop(i, 1, n) {
        loop(j, 1, m) {
            ans = (ans + dp[1][0][i][j]) % Mod;
        }
    }
    cout << ans;
    return 0;
}