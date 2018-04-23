#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-21
 *  @Time: 11:21
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 500050
int n, k;
int pre[maxn];

int LIS() {//O(N^2)朴素LIS算法
    int ans = 0;
    int dp[maxn];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (pre[j] <= pre[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}