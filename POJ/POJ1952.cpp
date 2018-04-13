
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-21
 *  @Time: 21:06
 *  To change this template use File | Settings | File Templates.
 * 
 */



#define maxn 5050
int prices[maxn];
int dfn_index[maxn];//第i位长度为len的次数
int n;
int max_len = 0;
int ans = 0;

void LIS() {
    int dp[maxn];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        dfn_index[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {//注意要倒着循环！！
            if (prices[i] < prices[j]) {
                int len = dp[j] + 1;
                if (dp[i] < len) {
                    //更长的长度
                    dp[i] = len;
                    dfn_index[i] = dfn_index[j];//因为是从j过来的，所以长度更新
                } else if (dp[i] == len) {
                    //又找到了一个与当前长度一样的
                    dfn_index[i] += dfn_index[j];
                }
            } else if (prices[i] == prices[j]) {
                //遇到与当前一样的值
                if (dp[i] == 1) {
                    dfn_index[i] = 0;
                }
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        max_len = max(max_len, dp[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == max_len) {
            ans += dfn_index[i];
        }
    }
}

int main() {
    while (~scanf("%d", &n)) {
        memset(prices, 0, sizeof(prices));
        memset(dfn_index, 0, sizeof(dfn_index));
        max_len = 0;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &prices[i]);
        }
        LIS();
        printf("%d %d\n", max_len, ans);
    }
    return 0;
}