#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-25
 *  @Time: 23:10
 *  To change this template use File | Settings | File Templates.
 *
 */


int a1, b1;

bool prime() {//辗转相除法
    bool flag;
    int dividend = max(a1, b1);
    int divisor = min(a1, b1);
    while (true) {

        int temp = dividend % divisor;

        if (temp == 0) {
            flag = divisor == 1;
            break;
        }
        dividend = divisor;
        divisor = temp;

    }
    return flag;
}

int HDU1014() {
    while (~scanf("%d %d", &a1, &b1)) {
        bool flag = prime();
        if (flag) {
            printf("%10d%10d    Good Choice\n\n", a1, b1);
        } else {
            printf("%10d%10d    Bad Choice\n\n", a1, b1);
        }

    }
    return 0;
}