#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 18:12
 *  To change this template use File | Settings | File Templates.
 *  在区间(l...r)之间，不包含左右端点
 *  l=0 r=max+1
 */

int search(int l, int r, int f) {
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (f) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;

}