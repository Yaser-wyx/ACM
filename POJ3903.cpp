
#include <cstring>
#include <cstdio>
#include <algorithm>

#define maxn 5050
using namespace std;
int n, ans, max_len;
int cnt[maxn], prices[maxn];

void LIS() {
    int dp[maxn];
    ans = 0, max_len = 0;
    for (int i = 0; i < n; i++) {
        cnt[i] = 1;//该长度的个数
        dp[i] = 1;//i处的长度
    }

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (prices[j] > prices[i]) {
                int len = dp[j] + 1;
                if (dp[i] < len) {
                    //更长的长度
                    dp[i] = len;
                    cnt[i] = cnt[j];
                } else if (dp[i] == len) {//又遇到一个相同长度的
                    cnt[i] += cnt[j];//更新
                }
            } else if (prices[i] == prices[j]) {
                if (dp[i] == 1) {//注意之所以是1，是因为j从后往前查找，意味着如果遇到与之前相同的数，且同时没有组成比1更长的序列，那么这个可以去掉
                    cnt[i] = 0;
                }
                break;//注意break的位置，如果j继续减一，则就会和prices[j]重复
            }
        }
    }
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, dp[i]);
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] == max_len) {
            ans += cnt[i];
        }

    }
}

int POJ3903() {

    while (~scanf("%d", &n)) {
        memset(prices, 0, sizeof(prices));
        for (int i = 0; i < n; i++) {
            scanf("%d", &prices[i]);
        }
        LIS();
        printf("%d %d\n", max_len, ans);
    }

    return 0;
}