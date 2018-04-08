#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-07
 *  @Time: 11:35
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 10100
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int col[maxn << 4];
int hash1[maxn << 4];
int cnt;

void PushDown(int rt) {
    if (col[rt] != -1) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];//标记下推
        col[rt] = -1;//清除标记
    }

}

void update(int L, int R, int v, int l, int r, int rt) {//区间更新
    if (L <= l && R >= r) {
        col[rt] = v;//在需要更新的区间内部
        return;
    }
    PushDown(rt);//在更新当前节点之前需要先看当前节点是否有标记，即col[rt]!=-1
    //如果有标记则将标记进行下推
    int m = (l + r) >> 1;
    if (L <= m)update(L, R, v, lson);
    if (R > m)update(L, R, v, rson);
}

void query(int l, int r, int rt) {
    if (col[rt] != -1) {
        if (!hash1[col[rt]]) {
            cnt++;
        }
        hash1[col[rt]] = true;
        return;
    }
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    query(lson);
    query(rson);

}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int n;
        scanf("%d", &n);
        int x[maxn << 2];
        int lx[n], rx[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &lx[i], &rx[i]);
            x[m++] = lx[i];
            x[m++] = rx[i];
        }
        //进行离散化操作
        sort(x, x + m);
        int size = unique(x, x + m) - x;//求去重后的区间大小
        int temp = size;
        for (int i = 1; i < temp; i++) {
            if (x[i] - 1 != x[i - 1]) {//如果两个区间之间大于1，则插入一个数
                x[size++] = x[i] - 1;
            }
        }
        sort(x, x + size);//再排序
        cnt = 0;
        //初始化
        memset(hash1, false, sizeof(hash1));
        memset(col, -1, sizeof(col));
        for (int i = 0; i < n; i++) {
            int l = lower_bound(x, x + size, lx[i]) - x;
            int r = lower_bound(x, x + size, rx[i]) - x;
            update(l, r, i, 0, size, 1);
        }
        query(0, size, 1);
        printf("%d\n", cnt);
    }
    return 0;
}