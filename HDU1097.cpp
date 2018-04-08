#include <bits/stdc++.h>

typedef long long lli;
using namespace std;
#define maxn 10
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-11
 *  @Time: 9:05
 *  To change this template use File | Settings | File Templates.
 * 
 */

struct num {
    vector<int> last;
    int size = 0;
} nums[maxn];

void create() {//打表
    for (int i = 0; i < 10; i++) {
        bool vis[10] = {false};
        int temp = i;
        while (true) {
            if (vis[temp]) {
                break;
            }
            nums[i].last.push_back(temp);
            nums[i].size++;
            vis[temp] = true;
            temp *= i;
            if (temp >= 10) {
                temp %= 10;
            }
        }
    }
}

int HDU1097() {
    create();
    lli a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        if (a >= 10) {
            a %= 10;
        }
        int index = (b % nums[a].size) - 1;
        if (index < 0) {
            printf("%d\n", nums[a].last[nums[a].size - 1]);
        } else {
            printf("%d\n", nums[a].last[index]);
        }

    }
    return 0;
}