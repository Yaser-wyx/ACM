#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-18
 *  @Time: 21:15
 *  To change this template use File | Settings | File Templates.
 *  两种解法：一种使用记忆化搜索，一种使用S的逆序来做LCS，求得最大公共子串n，再用总长减去n即为需要插入的个数
 */
#define maxn 5005
namespace way1 {
    short dp[maxn][maxn];
    int n;
    char s[maxn];

    int dfs(int l, int r) {//搜索从l到r范围是否回文

        if (l >= r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = 999999;
        if (s[l] == s[r]) {
            //两者一样，则看下一位
            ans = dfs(l + 1, r - 1);
        } else {

            ans = min(ans, dfs(l + 1, r) + 1);//在右边添加一位
            ans = min(ans, dfs(l, r - 1) + 1);//在左边添加一位
        }
        dp[l][r] = ans;
        return ans;

    }

    int POJ1159() {
        while (~scanf("%d", &n)) {
            scanf("%s", s);
            memset(dp, -1, sizeof(dp));
            int ans = dfs(0, n - 1);
            printf("%d\n", ans);
        }
        return 0;
    }
}
namespace way2 {
    int dp[2][maxn];
    int n;
    char s[maxn];
    char s1[maxn];

    int POJ1159() {

        while (~scanf("%d", &n)) {
            scanf("%s", s + 1);
            memset(dp, 0, sizeof(dp));

            int index = 1;
            for (int i = n; i >= 1; i--) {
                s1[index++] = s[i];//逆序操作
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1[i] == s[j]) {
                        dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
                    } else {
                        dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
                    }
                }
            }
            printf("%d\n", n - dp[n & 1][n]);

        }
        return 0;
    }
}