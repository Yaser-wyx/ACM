#include <bits/stdc++.h>

#define mset(t) memset(t,0,sizeof(t))
#define maxn 22
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-11
 *  @Time: 16:44
 *  To change this template use File | Settings | File Templates.
 * 
 */
int n;
int vis[maxn];//每个单词已经访问过的次数
int ans = 0;
int chart[maxn][maxn];//保存单词重合的个数
char *s[maxn];//单词

void dfs(int x, int len) {
    ans = max(ans, len);//保证ans的值最大
    for (int i = 0; i < n; i++) {
        if (chart[x][i]) { //不为0，即二者有重叠的部分
            if (vis[i] < 2) {
                vis[i]++;
                dfs(i, len + (strlen(s[i]) - chart[x][i]));
                vis[i]--;
            }
        }
    }
}

void pre() {//预处理
    for (int i = 0; i < n; i++) {//前
        for (int j = 0; j < n; j++) {//后

            char *temp = &s[i][strlen(s[i]) - 1];
            int cnt = 1;//重合的个数
            while (*temp != s[j][0] && temp > &s[i][0]) {//定位前一个单词与后一个单词首个字母重复的位置
                temp--;//从后向前遍历，直到找到与另一个单词开头一样的字母
                cnt++;
            }
            if (cnt < strlen(s[i]) && cnt < strlen(s[j])) {//如果重合的个数大于等于二者中的一个，则将个数置为0
                auto index = &s[j][0];
                while (temp <= &s[i][strlen(s[i]) - 1]) {
                    if (*temp == *index) {//如果字母一样，则二者同时向后移动
                        temp++;
                        index++;
                    } else {//不一样代表没有重合的字母，置为0
                        cnt = 0;
                        break;
                    }
                }
            } else {
                cnt = 0;//不存在
            }
            chart[i][j] = cnt;
        }
    }
}

int P1019() {

    mset(chart);
    mset(vis);
    cin >> n;
    vector<int> start;
    for (int i = 0; i < n; i++) {
        s[i] = new char[1000];
        cin >> s[i];
    }
    char c;

    cin >> c;
    for (int i = 0; i < n; i++) {//起点
        if (s[i][0] == c) {
            start.push_back(i);
        }
    }
    pre();
    for (int i = 0; i < start.size(); i++) {//对每一个起点进行DFS操作
        int st = start[i];
        mset(vis);
        vis[st]++;
        dfs(st, strlen(s[st]));
    }
    printf("%d\n", ans);
    return 0;
}