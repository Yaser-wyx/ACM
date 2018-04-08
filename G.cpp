#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 15:02
 *  To change this template use File | Settings | File Templates.
 *
 */
int G() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    stack<int> stack1;
    int cnt = 0;
    int index = 0;
    while (index < n) {
        if (stack1.empty()) {
            stack1.push(nums[index++]);
            continue;
        }
        int x = stack1.top();
        if (abs(x - nums[index]) == 1) {
            //绝对值为1
            cnt++;
            if (nums[index] > x) {
                index++;
                continue;
            } else {
                stack1.pop();
            }
        } else {
            stack1.push(nums[index++]);
        }

    }
    printf("%d\n", cnt);

    return 0;
}
