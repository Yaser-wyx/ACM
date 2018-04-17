#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 14:23
 *  To change this template use File | Settings | File Templates.
 * 
 */
int nums[8];
bool vis[8];


bool judge() {
    long res = 0;

    for (int i = 0; i < 8; i++) {
        res = res * 10 + nums[i];
    }

    for (int i = 2; i <= sqrt(res); i++) {
        if (res % i == 0) {
            return false;
        }
    }
    return true;
}

int pre = 0;

void find(int index) {
    if (index == 8) {
        if (judge()) {
            pre++;
            for (int i = 0; i < 8; i++) {
                printf("%d", nums[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (index == 0 && i == 0) {
            continue;
        }
        if (!vis[i]) {
            vis[i] = true;
            nums[index] = i;
            find(index + 1);
            vis[i] = false;
        }
    }
}

int B() {
    find(0);

    printf("\n\n%d", pre);
    return 0;
}