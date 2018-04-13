#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-12
 *  @Time: 20:09
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 1000
using namespace std;
int n;
bool G[maxn][maxn];//图
int deg[maxn];//度数
int cnt = 0;
int st[3];//起点
vector<char> path;

void add(int a, int b) {
    G[a - 'A' + 1][b - 'A' + 1] = 1;
    G[b - 'A' + 1][a - 'A' + 1] = 1;
    deg[a - 'A' + 1]++;
    deg[b - 'A' + 1]++;
    st[2] = min(min(a - 'A' + 1, b - 'A' + 1), st[2]);//最小的字典序
}

bool judge() {//判断是否是欧拉回路或欧拉通路
    int index = 0;
    for (int i = 0; i < maxn; i++) {
        if (deg[i] & 1) {
            cnt++;
            if (cnt > 2) {
                return false;
            }
            st[index++] = i;
        }

    }
    return cnt != 1;
}

void dfs(int index, int ct) {
    if (ct == n) {
        return;
    }
    int next = 0;
    for (int i = 0; i < maxn; i++) {
        if (G[index][i]) {
            next = i;
            G[index][i] = 0;
            G[i][index] = 0;
            dfs(next, ct + 1);
            path.push_back((char) (next + 'A' - 1));
        }
    }
}

void print() {
    for (int i = n; i >= 0; i--) {
        printf("%c", path[i]);
    }
}

int P1341() {
    cin >> n;
    mset(deg, 0);
    st[2] = maxn;
    for (int i = 0; i < n; i++) {
        char a, b = 0;
        cin >> a;
        cin >> b;
        add(a, b);
    }
    if (!judge()) {
        //不是
        printf("No Solution\n");
        return 0;
    }
    //进行dfs遍历
    if (cnt == 2) {
        int start = min(st[0], st[1]);
        dfs(start, 0);
        path.push_back((char) start + 'A' - 1);
    } else {
        dfs(st[2], 0);
        path.push_back((char) st[2] + 'A' - 1);
    }
    print();
    return 0;
}