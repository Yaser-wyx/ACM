#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 10:51
 *  To change this template use File | Settings | File Templates.
 * 彩票
 */
#define maxn 10

int p2() {
    int sum = 0;

    for (int i = 1; i < maxn; i++) {
        if (i == 4) {
            continue;
        }
        for (int j = 0; j < maxn; j++) {
            if (j == 4) {
                continue;
            }
            for (int l = 0; l < maxn; l++) {
                if (l == 4) {
                    continue;
                }
                for (int m = 0; m < maxn; m++) {
                    if (m == 4) {
                        continue;
                    }
                    for (int n = 0; n < maxn; n++) {
                        if (n == 4) {
                            continue;
                        }
                        sum++;
                    }
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}