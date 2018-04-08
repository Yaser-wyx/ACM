#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 20:33
 *  To change this template use File | Settings | File Templates.
 * 
 */

int A() {
    int four = 0;
    int seven = 0;
    char c;
    while (~scanf("%c", &c)) {
        if (c == '4') {
            four++;
        } else if (c == '7') {
            seven++;
        }
    }
    if (four >= seven && four != 0) {
        printf("4\n");
    } else if (four == 0 && seven == 0) {
        printf("-1\n");
    } else {
        printf("7\n");
    }

    return 0;
}