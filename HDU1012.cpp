#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-24
 *  @Time: 16:33
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1012() {
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    double e[10];
    e[0] = 1;
    e[1] = 2;
    e[2] = 2.5;
    for (int i = 3; i <= 9; i++) {
        double temp = i;
        for (int j = i - 1; j > 1; j--) {
            temp *= j;
        }
        temp = 1.0 / temp;
        e[i] = e[i - 1] + temp;
        printf("%d %.9f\n", i, e[i]);
    }

    return 0;
}