#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-09
 *  @Time: 8:12
 *  To change this template use File | Settings | File Templates.
 * 
 */


int algorithm(int n) {
    int counter = 0;
    while (n != 1) {
        if (n % 2) {
            //奇数
            n = 3 * n + 1;
        } else {
            //偶数
            n = n / 2;
        }
        counter++;
    }
    return ++counter;
}


int HDU1032() {
    int a, b;
    //初始化
    while (~scanf("%d%d", &a, &b)) {
        int end_num = max(a, b);
        int start_num = min(a, b);
        int max_cnt = 0;
        for (int i = start_num; i <= end_num; i++) {
            long temp = algorithm(i);
            if (temp > max_cnt) {
                max_cnt = temp;
            }
        }
        printf("%d %d %d\n", a, b, max_cnt);
    }
    return 0;
}