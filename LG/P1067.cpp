#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-09
 *  @Time: 10:47
 *  To change this template use File | Settings | File Templates.
 * 
 */
int P1067() {
    int n;
    scanf("%d", &n);
    int temp;
    bool flag = 0;
    for (int i = n; i >= 0; i--) {
        scanf("%d", &temp);
        if (temp == 0) {
            continue;
        }
        if (i == 0) {
            //最后一个元素
            //直接输出
            if (temp > 0) {
                printf("+");
            }
            printf("%d", temp);
        } else {
            //不是最后一个元素
            if (temp > 0) {
                if (flag) {
                    printf("+");
                } else {
                    flag = 1;
                }
                if (temp != 1) {
                    printf("%d", temp);
                }
            } else {
                if (temp == -1) {
                    printf("-");
                } else
                    printf("%d", temp);
            }
            if (i == 1) {
                printf("x");
            } else
                printf("x^%d", i);
        }


    }
    return 0;
}