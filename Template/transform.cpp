#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 16:39
 *  To change this template use File | Settings | File Templates.
 *  进制转换
 */

void transform(int num, int index, int t, int &x[]) {
    if (num == 0) {
        return;
    }
    x[index] = num % t;
    transform(num / t, index + 1, t, x);
}