#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 12:11
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
#define maxn 1005
#define maxm 20005
#define mod 1000007
int l, m, k, n, r, q;
int flower[maxn];
int dp[maxn][maxn];


int P1077() {
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> flower[i];
    }
    loop(i, 0, n) {
        dp[i][0] = 1;//啥都不放就是一种方案
    }
    loop(i, 1, n) {
        loop(j, 1, m) {
            loop(k, 0, flower[i]) {
                if (k <= j) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= mod;
                } else {
                    break;
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}

 