#include <bits/stdc++.h>

#define INF 0xfffffff

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-03
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
#define maxn 20
int n, m, r, c;
int matrix[maxn][maxn];
int reduce[maxn];
int v[maxn][maxn];
int temp[maxn];
int ans = INF;

void dp() {
    int f[maxn][maxn];
    loop(i, 0, c) {
        loop(j, 0, m) {
            f[i][j] = INF;
        }
    }
    f[0][0] = 0;
    loop(i, 1, c) {//选择i列
        loop(j, i, m) {//这i列里最后一列是j
            loop3(k, 0, j) {//j的前一列是k
                f[i][j] = min(f[i][j], f[i - 1][k] + reduce[j] + v[k][j]);//前i-1的第k列加上第j列的值
            }
        }
    }
    loop(j, c, m) {
        ans = min(ans, f[c][j]);//最小值
    }

}

void pre() {//预处理，矩阵压缩
    mset(reduce, 0);
    mset(v, 0);
    loop(j, 1, m) {
        loop3(i, 1, r) {//计算行的绝对值差的和(竖着)
            reduce[j] += abs(matrix[temp[i - 1]][j - 1] - matrix[temp[i]][j - 1]);
        }
    }
    loop(i, 1, m) {
        loop(j, i + 1, m) {
            loop(k, 1, r) {//计算i列与j列的绝对值差的和(横着)
                v[i][j] += abs(matrix[temp[k - 1]][i - 1] - matrix[temp[k - 1]][j - 1]);
            }
        }
    }
}

void dfs(int index, int next) {//组合
    if (index == r) {
        pre();//预处理
        dp();
        return;
    }
    loop3(i, next, n) {
        temp[index] = i;
        dfs(index + 1, i + 1);
        temp[index] = 0;
    }
}

int P2258() {
    cin >> n >> m >> r >> c;
    loop3(i, 0, n) {
        loop3(j, 0, m) {
            cin >> matrix[i][j];
        }
    }
    mset(temp, 0);
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
