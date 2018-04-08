#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 10:43
 *  To change this template use File | Settings | File Templates.
 *  四叶玫瑰
 */
int a() {
    int res = 0;
    int temp = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    temp = i * i * i * i + j * j * j * j + l * l * l * l + k * k * k * k;
                    res = i * 1000 + j * 100 + k * 10 + l;
                    if (temp == res) {
                        printf("%d\n", res);
                    }

                }
            }
        }
    }
    return 0;
}