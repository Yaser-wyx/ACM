#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 12:06
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 10
int nums[6];
int n;

bool judge(int nn) {
    int l = 0, r = nn - 1;
    while (l <= r) {
        if (nums[l] != nums[r]) {
            return false;
        } else {
            l++, r--;
        }
    }
    int sum = 0;
    for (int i = 0; i < nn; i++) {
        sum += nums[i];
    }
    return sum == n;
}

void print(int nn) {
    for (int i = 0; i < nn; i++) {
        printf("%d", nums[i]);
    }
    printf("\n");

}

int p4() {
    scanf("%d", &n);
    bool flag = true;
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int k = 0; k < maxn; k++) {
                for (int l = 0; l < maxn; l++) {
                    for (int m = 0; m < maxn; m++) {
                        nums[0] = i;
                        nums[1] = j;
                        nums[2] = k;
                        nums[3] = l;
                        nums[4] = m;
                        if (judge(5)) {
                            flag = false;
                            print(5);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int k = 0; k < maxn; k++) {
                for (int l = 0; l < maxn; l++) {
                    for (int m = 0; m < maxn; m++) {
                        for (int o = 0; o < maxn; o++) {
                            nums[0] = i;
                            nums[1] = j;
                            nums[2] = k;
                            nums[3] = l;
                            nums[4] = m;
                            nums[5] = o;
                            if (judge(6)) {
                                flag = false;
                                print(6);
                            }
                        }
                    }
                }
            }
        }
    }
    if (flag) {
        printf("-1\n");
    }
    return 0;
}