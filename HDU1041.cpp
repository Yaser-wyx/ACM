#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-09
 *  @Time: 19:27
 *  To change this template use File | Settings | File Templates.
 * 
 */


int HDU1041() {
    queue<int> nums;
    queue<int> temp;
    nums.push(1);
    for (int i = 0; i < 15; i++) {
        while (!nums.empty()) {
            int x = nums.front();
            if (x) {
                temp.push(0);
                temp.push(1);
            } else {
                temp.push(1);
                temp.push(0);
            }
            nums.pop();
        }
        int zero = 0;
        int pair = 0;
        while (!temp.empty()) {
            int x = temp.front();
            if (!x) {
                zero++;
                if (zero == 2) {
                    pair++;
                    zero = 0;
                }
            } else {
                zero = 0;
            }
            nums.push(x);
            temp.pop();
        }
        printf("%d\n", pair);
    }
    return 0;
}