#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-24
 *  @Time: 11:47
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 100005
#define mod 100003
typedef unsigned long long int lli;

int n, k;
lli ans = 0;

int main() {
    scanf("%d%d", &n, &k);
    lli dp[maxn];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
            }
        }
    }

    printf("%llu\n", dp[n] % mod);

}