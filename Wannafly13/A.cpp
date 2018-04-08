#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-06
 *  @Time: 19:16
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100000
#define mod 1000000007
typedef long long int lli;

char c[maxn];

int A() {
    scanf("%s", c);
    lli cnt = 1;
    int len = strlen(c);
    lli temp = 0;
    for (int i = 0; i < len; i++) {
        temp = 2;
        if (c[i] >= 49 && c[i] <= 57) {
            temp = 1;
        }
        if (c[i] == 'i' || c[i] == 'I' || c[i] == 'l' || c[i] == 'L') {
            temp = 4;
        }
        if (c[i] == '0' || c[i] == 'o' || c[i] == 'O') {
            temp = 3;
        }
        cnt = (cnt * temp) % mod;
    }
    printf("%lli\n", cnt);
    return 0;
}