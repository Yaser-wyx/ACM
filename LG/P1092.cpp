#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-06
 *  @Time: 18:14
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
int n;
int alphabet[maxn];//映射
int addition[3][maxn];//加法
bool vis[maxn];
int Next[maxn];
int cnt = 0;

bool judge() {//检查
    bool flag = 0;
    loop2(i, n - 1, 0) {
        int temp = alphabet[addition[0][i]] + alphabet[addition[1][i]] + flag;//获取相加后的值
        if (temp >= n) {
            temp -= n;
            flag = 1;//进位
        } else {
            flag = 0;
        }
        if (temp != alphabet[addition[2][i]]) {
            return 0;
        }
    }
    return 1;
}

bool judge2() {//剪枝，判断竖式能否成立
    if (alphabet[addition[0][0]] + alphabet[addition[1][0]] >= n) {
        return 1;
    }
    loop2(i, n - 1, 0) {
        int a = addition[0][i];
        int b = addition[1][i];
        int c = addition[2][i];
        if (alphabet[a] == -1 || alphabet[b] == -1 || alphabet[c] == -1) {
            continue;
        }
        int temp = alphabet[a] + alphabet[b];//获取相加后的值

        if (temp % n != alphabet[c] && (temp + 1) % n != alphabet[c]) {
            return 1;
        }
    }
    return 0;
}

void dfs(int index) {
    if (judge2()) {
        return;
    }
    if (index == n) {
        if (judge()) {
            loop3(i, 0, n) {
                cout << alphabet[i];
                if (i != n - 1) {
                    cout << " ";
                }
            }
        }
        exit(0);//注意，找到后就直接退出
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[i]) {
            vis[i] = 1;
            alphabet[Next[index]] = i;
            dfs(index + 1);
            vis[i] = 0;
            alphabet[Next[index]] = -1;
        }
    }
}

void Getnext(int x) {
    if (!vis[x]) {
        vis[x] = 1;
        Next[cnt++] = x;
    }
}

int P1092() {
    cin >> n;
    mset(alphabet, -1);
    mset(vis, 0);
    char temp;
    loop3(i, 0, 3) {
        loop3(j, 0, n) {
            cin >> temp;
            addition[i][j] = temp - 'A';
        }
    }
    loop2(i, n - 1, 0) {//按照竖式的顺序进行枚举
        Getnext(addition[0][i]);
        Getnext(addition[1][i]);
        Getnext(addition[2][i]);
    }
    mset(vis, 0);

    dfs(0);
    return 0;
}
 