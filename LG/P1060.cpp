#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-16
 *  @Time: 10:53
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 100010
int n, m;
int cost[30], value[30];
int dp[maxn];

int P1164() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &cost[i], &value[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = n; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + cost[i] * value[i]);
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}