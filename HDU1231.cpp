#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-24
 *  @Time: 19:36
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1231() {

    int k;
    while (~scanf("%d", &k)) {
        if (k == 0)break;
        int dp[k + 1];
        int nums[k + 1];
        dp[0] = 0;
        int indexes[k + 1];
        for (int i = 1; i <= k; i++) {
            scanf("%d", &dp[i]);
            nums[i] = dp[i];
            indexes[i] = i;
        }
        int max_index = 1;

        for (int i = 2; i <= k; i++) {
            int temp = dp[i - 1] + nums[i];//保存前面的数与当前数的和
            if (dp[i] > temp) {
                indexes[i] = i;//如果当前数更大，则从i重新开始
            } else {
                dp[i] = temp;//否则跟在前一个数后面
                indexes[i] = i - 1;
            }
            if (dp[max_index] < dp[i]) {
                max_index = i;//判断最大和所在的位置
            }
        }
        int start = 1;//起始位置
        if (dp[max_index] < 0) {
            printf("%d %d %d\n", 0, nums[1], nums[k]);
            continue;
        }
        for (int i = max_index; i > 0; i--) {
            start = i;
            if (indexes[i] == i) {
                break;
            }
        }
        printf("%d %d %d\n", dp[max_index], nums[start], nums[max_index]);

    }
    return 0;
}