#include <bits/stdc++.h>

using namespace std;

int HDU1029() {
    int n;
    while (~scanf("%d", &n)) {//摩尔投票
        int nums[n];
        int appear = (n + 1) >> 1;
        int count = 0;
        int num = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            if (!count) {
                num = nums[i];
                count++;
            } else {
                if (num == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        int counter(0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == num) {
                counter++;
            }
        }
        if (counter >= appear) {
            printf("%d\n", num);
        }


    }
    return 0;
}