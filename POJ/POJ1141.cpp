#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-20
 *  @Time: 16:18
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 250
#define inf 9999
char *s;
long pos[maxn][maxn];//-1代表断点处

void print(int l, int r) {
    if (l > r) {
        return;
    }
    if (l == r) {
        //只有一个括号
        if (s[l] == '(' || s[l] == ')') {
            printf("()");
        } else {
            printf("[]");
        }
        return;
    }
    if (pos[l][r] == -1) {
        //l与r无需分解
        printf("%c", s[l]);
        print(l + 1, r - 1);
        printf("%c", s[r]);
    } else {
        //需要分解
        print(l, pos[l][r]);
        print(pos[l][r] + 1, r);
    }


}

int POJ1141() {
    map<char, char> map1;
    map1['['] = ']';
    map1['('] = ')';
    scanf("%s", s);
    int dp[maxn][maxn];//l-r代表在该区间内最少需要添加的括号数量
    int ll = strlen(s);
    for (int l = 0; l < ll; l++) {
        dp[l][l] = 1;
    }
    for (int len = 1; len < ll; len++) {//长度
        for (int l = 0; l + len < ll; l++) {//左端点
            int r = l + len;//右端点
            dp[l][r] = inf;
            if (map1[s[l]] == s[r]) {
                pos[l][r] = -1;//断点
                dp[l][r] = dp[l + 1][r - 1];
            }
            for (int k = l; k < r; k++) {
                int temp = dp[l][k] + dp[k + 1][r];
                if (dp[l][r] > temp) {
                    pos[l][r] = k;
                    dp[l][r] = temp;
                }

            }
        }
    }
    print(0, ll - 1);
    printf("\n");

    return 0;
}