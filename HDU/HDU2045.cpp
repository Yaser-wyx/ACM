#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-15
 *  @Time: 18:55
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn  52
typedef long long int lld;
using namespace std;
int n;
lld nums[maxn];

void form() {
    nums[1] = 3;
    nums[2] = 6;
    nums[3] = 6;
    for (int i = 4; i < maxn; i++) {
        nums[i] = nums[i - 1] + nums[i - 2] * 2;
    }
}

int HDU2045() {
    form();
    while (~scanf("%d", &n) ) {
        printf("%lld\n", nums[n]);
    }

    return 0;
}