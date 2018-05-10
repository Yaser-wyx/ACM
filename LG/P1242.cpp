#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-09
 *  @Time: 15:09
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 50
int n, m;
int origin[maxn];
int dis[maxn];
int cnt = 0;
/**
 *
 * @param d 当前圆盘的编号
 * @param x 当前圆盘的位置
 * @param y 当前圆盘想去的位置
 * @param mv 大于等于当前圆盘的是否都已经到了他想去的地方
 */
void dfs(int d, int x, int y, bool mv) {
    if (x != y) {
        //该圆盘需要动
        int z = 1;
        while (z == x || z == y) {
            z++;//计算比它小的圆盘呆的位置
        }
        if (d > 1) {
            dfs(d - 1, origin[d - 1], z, false);//让那些比当前圆盘小的都到z这个位置，别妨碍到自己
        }
        cnt++;//计数
        cout << "move " << d << " from " << char(x + 'A' - 1) << " to " << char(y + 'A' - 1) << endl;
        origin[d] = y;//移动
    }

    if (d > 1) {
        dfs(d - 1, origin[d - 1], mv ? dis[d - 1] : y, mv);
        //如果大于等于当前圆盘都已经就位了，则让下一个圆盘移动，否则让比他小的圆盘都待自己上面，不让他们妨碍到比自己大的圆盘的移动
    }
}

int P1242() {
    cin >> n;
    cin >> m;
    int temp;
    loop3(i, 0, m) {
        cin >> temp;
        origin[temp] = 1;
    }
    cin >> m;
    loop3(i, 0, m) {
        cin >> temp;
        origin[temp] = 2;
    }
    cin >> m;
    loop3(i, 0, m) {
        cin >> temp;
        origin[temp] = 3;
    }
    cin >> m;
    loop3(i, 0, m) {
        cin >> temp;
        dis[temp] = 1;
    }
    cin >> m;
    loop3(i, 0, m) {
        cin >> temp;
        dis[temp] = 2;
    }
    cin >> m;
    loop3(i, 0, m) {
        cin >> temp;
        dis[temp] = 3;
    }
    dfs(n, origin[n], dis[n], true);
    cout << cnt;
    return 0;
}