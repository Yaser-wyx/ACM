#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 19:49
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
#define maxn 2002
#define Mod 1000000007
int n, c;
int price[maxn];
lli dp[maxn][maxn];

int P2858() {

    cin >> n;
    mset(dp, 0);
    loop(i, 1, n) {
        cin >> price[i];
    }
    loop(i, 1, n) {
        loop2(j, n, i) {
            dp[i][j] = max(dp[i - 1][j] + price[i - 1] * (i - 1 + (n - j)),
                           dp[i][j + 1] + price[j + 1] * (i - 1 + (n - j)));
        }
    }
    lli ans = 0;
    loop(i, 1, n) {
        ans = max(ans, dp[i][i] + n * price[i]);
    }
    cout << ans;
    return 0;
}