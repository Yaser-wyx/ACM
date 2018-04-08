#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-27
 *  @Time: 17:21
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 22000
int n, v;
int dp[maxn];

void P10() {
    scanf("%d%d", &v, &n);
    int weight[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = v; j >= weight[i]; j--) {
            dp[j] = max(dp[j - weight[i]] + weight[i], dp[j]);
        }
    }
    printf("%d", v - dp[v]);
}