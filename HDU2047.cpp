#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-15
 *  @Time: 21:43
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 42
typedef long long int lli;
lli nums[maxn];
int n;

void form() {
    nums[1] = 3;
    nums[2] = 8;
    nums[3] = 22;
    for (int i = 4; i < maxn; i++) {

        nums[i] = 2 * nums[i - 1] + 2 * nums[i - 2];
    }
}

int HDU2047() {
    form();
    while (~scanf("%d", &n)) {
        printf("%lli\n", nums[n]);
    }

    return 0;
}