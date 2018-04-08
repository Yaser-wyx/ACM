#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-01
 *  @Time: 20:40
 *  To change this template use File | Settings | File Templates.
 * 
 */


int x;

//斐波那契博弈
//如果n是斐波那契数，则先手必败，否则胜
int G() {
    scanf("%d", &x);
    int last(1);
    int now(1);
    bool flag = false;
    for (int i = 0; i <= x; i++) {
        int temp = last + now;
        if (temp == x) {
            flag = true;
            break;
        }
        last = now;
        now = temp;
    }
    puts(flag ? "Sha\n" : "Xian\n");


    return 0;
}