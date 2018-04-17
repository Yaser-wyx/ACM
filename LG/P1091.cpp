#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-17
 *  @Time: 10:35
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 200
int n, m;
int people[maxn];

int P1091() {
    int dp[maxn];
    int dp1[maxn];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &people[i]);
    }
    //两次递增子序列
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        dp1[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (people[j] < people[i]) {
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (people[j] < people[i]) {
                dp1[i] =max( dp1[j] + 1,dp1[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cnt = max(cnt, dp1[i] + dp[i]-1);
    }
    printf("%d\n", n - cnt);
    return 0;
}
