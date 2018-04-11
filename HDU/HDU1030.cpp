#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-06
 *  @Time: 11:17
 *  To change this template use File | Settings | File Templates.
 * 
 */

void HDU1030() {
    long n, m;
    while (~scanf("%li%li", &n, &m)) {
        long Min = min(n, m);
        long Max = max(n, m);
        long level1 = (int) sqrt(Min - 1) + 1;//层数
        long level2 = (int) sqrt(Max - 1) + 1;
        long left1 = (Min - (level1 - 1) * (level1 - 1) - 1) / 2 + 1;//左坐标
        long left2 = (Max - (level2 - 1) * (level2 - 1) - 1) / 2 + 1;
        long right1 = (level1 * level1 - Min) / 2 + 1;//右坐标
        long right2 = (level2 * level2 - Max) / 2 + 1;
        long dis = abs(left1 - left2) + abs(level1 - level2) + abs(right1 - right2);
        printf("%li\n", dis);

    }
}