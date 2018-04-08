#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 14:17
 *  To change this template use File | Settings | File Templates.
 *
 */

#define maxn 102

int A() {

    long sum = 0;
    int puzzle[maxn][maxn];
    int index = 1;
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            puzzle[i][j] = index;
            sum += index;
            index++;
        }

    }
    int len = maxn / 2;
    for (int i = 1; i < maxn / 2; i++) {
        for (int j = 1; j < len; j++) {
            sum -= puzzle[i][j];
        }
        len--;
    }

    len = maxn / 2;
    for (int i = 1; i < maxn / 2; i++) {
        for (int j = maxn - len + 1; j < maxn; j++) {
            sum -= puzzle[i][j];
        }
        len--;
    }
    len = 0;
    for (int i = maxn / 2 + 1; i < maxn; i++) {
        len++;
        for (int j = 1; j <= len; j++) {
            sum -= puzzle[i][j];
        }
    }

    len = 0;
    for (int i = maxn / 2 + 1; i < maxn; i++) {
        len++;
        for (int j = maxn - len; j < maxn; j++) {
            sum -= puzzle[i][j];
        }
    }
    printf("%li", sum);

    return 0;
}