#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-11
 *  @Time: 18:45
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t) memset(t,0,sizeof(t))
#define maxn 105
int n;
char matrix[maxn][maxn];
queue<pair<int, int>> queue1;
bool vis[maxn][maxn];
int mv[8][2] = {{1,  1},
                {1,  -1},
                {1,  0},
                {0,  1},
                {0,  -1},
                {-1, -1},
                {-1, 0},
                {-1, 1}};
vector<pair<int, int>> temp;//存放一次dfs遍历过的坐标
int flag;
char c[7] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};

void dfs(int x, int y, int index) {
    if (index == 7) {
        //找到了一个，将遍历过的坐标标记上
        for (int i = 0; i < temp.size(); i++) {
            vis[temp[i].first][temp[i].second] = 1;
        }
        return;
    }
    int temp_x = x + mv[flag][0];
    int temp_y = y + mv[flag][1];
    if (temp_x >= 0 && temp_y >= 0 && temp_x < n && temp_y < n) {
        //在范围内
        if (matrix[temp_x][temp_y] == c[index]) {
            pair<int, int> p(temp_x, temp_y);
            temp.push_back(p);//添加坐标
            dfs(temp_x, temp_y, index + 1);
        }
    }
}

void print() {//打印
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) {//如果有标记，就打印
                printf("%c", matrix[i][j]);
            } else {//否则输出*
                printf("*");
            }
        }
        printf("\n");
    }
}

int P1101() {
    mset(vis);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'y') {
                pair<int, int> pair1(i, j);//读取起点坐标
                queue1.push(pair1);
            }
        }
    }
    while (!queue1.empty()) {
        pair<int, int> start = queue1.front();
        queue1.pop();
        for (flag = 0; flag < 8; flag++) {//8个方向的搜索
            temp.clear();
            temp.push_back(start);
            dfs(start.first, start.second, 1);//遍历
        }
    }
    print();
    return 0;
}