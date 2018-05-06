#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-08
 *  @Time: 20:54
 *  To change this template use File | Settings | File Templates.
 *  扩展欧几里得
 */
void Exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        Exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}