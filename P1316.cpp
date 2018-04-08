#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 11:49
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100010
int a, b;
int nums[maxn];

bool judge(int dis) {
    int k = 1, last = 0;
    for (int i = 0; i < a; i++) {
        int d = nums[i] - nums[last];
        if (d >= dis) {
            k++;
            last = i;
        }
    }
    return k >= b;
}

int P1316() {
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + a);
    int l = 0;
    int r = nums[a - 1] - nums[0];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (judge(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", r);
    return 0;
}