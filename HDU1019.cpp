#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-27
 *  @Time: 15:53
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1019() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int nums[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        sort(nums, nums + n);
        int multiple = nums[0];//前index个数的最小公倍数
        int now = nums[0];//前index个数的公倍数
        int index = 1;
        while (index < n) {
            if (now % nums[index] == 0) {
                //是倍数
                multiple = now;
                index++;
            } else {
                now += multiple;
            }
        }
        printf("%d  %d\n", now, multiple);
    }
    return 0;
}