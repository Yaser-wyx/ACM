#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-17
 *  @Time: 17:20
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 5500
int n, m;
int stock[maxn];
int dp[maxn];
int cnt[maxn];

int P1108() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (stock[j] > stock[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 1) {
            cnt[i] = 1;
        }
        for (int j = 0; j < i; j++) {
            if (stock[i] < stock[j] && dp[i] == dp[j] + 1) {
                cnt[i] += cnt[j];
            }
            if (stock[i] == stock[j] && dp[i] == dp[j]) {
                cnt[i] = 0;
            }
        }
        if (dp[i] == mx) {
            ans += cnt[i];
        }
    }
    printf("%d %d\n", mx, ans);
    return 0;
}
