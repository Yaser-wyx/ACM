#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 15:53
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 10
#define maxm 20
int n, m, t;
bool row[maxn][maxn];//列
bool line[maxn][maxn];//行
bool area[maxn][maxn];//宫
int sudoku[maxn][maxn];
int place[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
        {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
        {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
        {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
        {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
        {0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};
int source[10][10] = {
        {0, 0, 0, 0, 0, 0,  0, 0, 0, 0},
        {0, 6, 6, 6, 6, 6,  6, 6, 6, 6},
        {0, 6, 7, 7, 7, 7,  7, 7, 7, 6},
        {0, 6, 7, 8, 8, 8,  8, 8, 7, 6},
        {0, 6, 7, 8, 9, 9,  9, 8, 7, 6},
        {0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
        {0, 6, 7, 8, 9, 9,  9, 8, 7, 6},
        {0, 6, 7, 8, 8, 8,  8, 8, 7, 6},
        {0, 6, 7, 7, 7, 7,  7, 7, 7, 6},
        {0, 6, 6, 6, 6, 6,  6, 6, 6, 6}
};
pair<int, int> cnt[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int ans = 0;

void dfs(int y, int index) {
    if (index == maxn) {
        int temp = 0;
        loop3(i, 1, maxn) {
            loop3(j, 1, maxn) {
                temp+=source[i][j]*sudoku[i][j];
            }

        }
        ans=max(ans,temp);
        return;
    }
    if (sudoku[cnt[index].first][y]) {
        dfs(y + 1, index);
    } else if (y >= maxn) {
        dfs(1, index + 1);
    } else {
        loop3(i, 1, maxn) {
            if (!row[y][i] && !line[cnt[index].first][i] && !area[place[cnt[index].first][y]][i]) {
                row[y][i] = 1;
                line[cnt[index].first][i] = 1;
                area[place[cnt[index].first][y]][i] = 1;
                sudoku[cnt[index].first][y] = i;
                dfs(y + 1, index);
                row[y][i] = 0;
                line[cnt[index].first][i] = 0;
                area[place[cnt[index].first][y]][i] = 0;
                sudoku[cnt[index].first][y] = 0;
            }
        }
    }
}

int P1074() {
    int temp;
    mset(row, 0);
    mset(line, 0);
    mset(area, 0);
    loop3(i, 1, maxn) {
        cnt[i].first = i;
        cnt[i].second = 0;
        loop3(j, 1, maxn) {
            scanf("%d", &temp);
            sudoku[i][j] = temp;
            if (temp != 0) {
                row[j][temp] = 1;
                line[i][temp] = 1;
                area[place[i][j]][temp] = 1;
                cnt[i].second++;
            }
        }
    }
    sort(cnt + 1, cnt + maxn, cmp);
    dfs(1, 1);
    printf("%d\n",ans==0?-1:ans);
    return 0;
}