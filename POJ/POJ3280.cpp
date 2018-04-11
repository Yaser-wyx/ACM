#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-19
 *  @Time: 17:04
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 2020
char *s;
int letter[2][maxn];
int cost[maxn][maxn];

int dfs(int l, int r) {

    if (cost[l][r] != -1) {
        return cost[l][r];
    }
    if (l >= r) {
        cost[l][r] = 0;
        return cost[l][r];
    }
    int ans = 99999999;
    if (s[l] == s[r]) {
        ans = dfs(l + 1, r - 1);
    } else {
        //分两种情况讨论
        //1、删除左边或右边
        //2、在左边或右边添加
        ans = min(ans, dfs(l + 1, r) + letter[s[l] - 'a'][1]);//删除左边
        ans = min(ans, dfs(l, r - 1) + letter[s[r] - 'a'][1]);//删除右边
        ans = min(ans, dfs(l, r - 1) + letter[s[r] - 'a'][0]);//在左边添加
        ans = min(ans, dfs(l + 1, r) + letter[s[l] - 'a'][0]);//在右边添加
    }
    cost[l][r] = ans;
    return ans;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        scanf("%s", s + 1);
        memset(letter, 0, sizeof(letter));
        memset(cost, -1, sizeof(cost));
        for (int i = 0; i < n; i++) {//读取数据
            getchar();
            char c;
            int del, add;
            scanf("%c%d%d", &c, &add, &del);
            letter[c - 'a'][0] = add;
            letter[c - 'a'][1] = del;
        }
        int ans = dfs(1, m);
        printf("%d\n", ans);
    }
    return 0;
}