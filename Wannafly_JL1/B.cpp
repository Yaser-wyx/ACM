#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-02
 *  @Time: 21:31
 *  To change this template use File | Settings | File Templates.
 * 
 */
typedef long long ll;
ll coin_nums[4];
int coins[4] = {1, 5, 10, 50};
ll v;

int B() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld", &coin_nums[0], &coin_nums[1], &coin_nums[2], &coin_nums[3], &v);
        ll money = 0;
        for (int i = 1; i < 4; i++) {
            money += coin_nums[i] * coins[i];
        }
        if (money <= v) {
            printf("%lld\n", coin_nums[0]);
            continue;
        }
        ll temp1 = money;
        ll temp = 0;
        money -= v;
        temp = money % 5;
        coin_nums[0] += temp;
        money -= temp;
        temp1 -= money;
        if (temp1 == 0) {
            printf("%lld\n", coin_nums[0]);
            continue;
        }
        ll x = money / temp1;

        printf("%lld\n", coin_nums[0] + x * temp);
    }
    return 0;
}