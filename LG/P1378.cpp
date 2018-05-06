#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-06
 *  @Time: 20:37
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
#define maxn 30
#define area(r) M_PI*r*r
int n;
double lf, up, down, rg;
double ans = 0;
bool vis[maxn];
int nums[maxn];
double r[maxn];
struct circle {
    int x;
    int y;
} circles[maxn];

inline double dis(int a, int b) {//两点间的距离
    return sqrt((circles[a].x - circles[b].x) * (circles[a].x - circles[b].x) +
                (circles[a].y - circles[b].y) * (circles[a].y - circles[b].y));
}

inline double dis2(int index) {//与边框最近的距离
    double a = min(abs(lf - circles[index].x), abs(rg - circles[index].x));
    double b = min(abs(up - circles[index].y), abs(down - circles[index].y));
    return min(a, b);
}

double caculate() {
    mset(r, 0);
    double ans = 0;
    loop3(i, 0, n) {
        int index = nums[i];
        double mm = dis2(index);//求该圆可达的最大半径
        loop3(j, 0, n) {
            if (r[j]) {//只有该油滴已经有半径了才会妨碍到第i个油滴的扩展
                double temp = dis(index, j) - r[j];//注意，会出现油滴已经被覆盖的情况
                if (temp > 0) {
                    mm = min(temp, mm);
                } else {
                    mm = 0;
                    break;
                }

            }
        }
        r[index] = mm;
        ans += area(mm);
    }
    return ans;
}

void dfs(int index) {
    if (index == n) {
        double temp = caculate();//圆的总面积
        ans = max(temp, ans);
        return;
    }
    loop3(i, 0, n) {
        if (!vis[i]) {
            vis[i] = 1;
            nums[index] = i;
            dfs(index + 1);
            vis[i] = 0;
            nums[index] = 0;
        }
    }
}

int P1378() {
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    down = min(b, d);
    up = max(b, d);
    rg = max(a, c);
    lf = min(a, c);
    loop3(i, 0, n) {
        cin >> circles[i].x >> circles[i].y;
    }
    mset(vis, 0);
    mset(nums, 0);
    dfs(0);
    double leave = (up - down) * (rg - lf) - ans;
    cout << (int) round(leave);
    return 0;
}