#include <bits/stdc++.h>

#define maxn 2100
using namespace std;
int N;
char c1[maxn];//子弹
char c2[maxn];//恐怖分子
map<char, int> sorce;//每种类型的恐怖分子对应的分值


/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-22
 *  @Time: 15:43
 *  To change this template use File | Settings | File Templates.
 * 
 */

int LCS() {

    int len1 = strlen(c1);
    int len2 = strlen(c2);
    int dp[len1][len2];
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            dp[i][j] = 0;//初始化
        }
    }

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (c1[i] == c2[j]) {
                //相等
                dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + sorce[c1[i]] : sorce[c1[i]];

            } else {
                //不等
                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                } else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i - 1][j];
                }
            }

        }
    }
    return dp[len1 - 1][len2 - 1];
}

int pro1243() {
    while (~scanf("%d", &N)) {
        char s1[N];
        scanf("%s", s1);
        for (int i = 0; i < N; i++) {
            int temp;
            scanf("%d", &temp);
            sorce[s1[i]] = temp;
        }
        scanf("%s%s", c1, c2);
        int n = LCS();
        printf("%d\n", n);

    }
    cout<<454;
    return 0;
}