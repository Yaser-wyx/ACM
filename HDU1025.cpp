#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-21
 *  @Time: 12:14
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 500050
int n, k;
int nums[maxn];
int dp[maxn];//dp用来存放长度为i的lis末尾最小是什么
int len;

int bs(int x) {
    int l = 0;
    int r = len;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (dp[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}


int LIS() {//O(nlogn)朴素LIS算法
    memset(dp, 0, sizeof(dp));
    len = 1;
    dp[0] = nums[1];
    for (int i = 2; i <= n; i++) {
        int index = bs(nums[i]);
        if (index >= len) {
            dp[len++] = nums[i];
        } else {
            if (dp[index] > nums[i]) {
                dp[index] = nums[i];
            }
        }
    }
    return len;

}

int HDU1025() {
    int T = 1;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            scanf("%d", &nums[k]);
        }
        int ans = LIS();
        printf("Case %d:\n", T++);
        if (ans <= 1) {
            printf("My king, at most %d road can be built.\n", ans);
        } else {
            printf("My king, at most %d roads can be built.\n", ans);
        }
        printf("\n");

    }
    return 0;
}