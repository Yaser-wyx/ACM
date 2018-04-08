#include <bits/stdc++.h>

#define maxn 3000
using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-23
 *  @Time: 10:54
 *  To change this template use File | Settings | File Templates.
 * 
 */

void LCS1() {

    char c1[maxn];
    char c2[maxn];
    scanf("%s %s", c1, c2);
    int len1 = strlen(c1) + 1;
    int len2 = strlen(c2) + 1;
    int dp[len1][len2];
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (c1[i] == c2[j]) {
                //在该处相等
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[len1 - 1][len2 - 1]);
}