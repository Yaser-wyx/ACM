#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 100010
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
            if (cnt > 2) {//度数为奇数的节点超过2个
                return false;//不是
            }
            st[index++] = i;//起点
        }

    }
    return cnt != 1;//奇数节点数只可为2或0
}

void dfs(int index, int ct) {
    if (ct == n) {
        return;
    }
    int next = 0;
    for (int i = 0; i < maxn; i++) {
        if (G[index][i]) {//遍历节点
            next = i;//下一个访问的节点
            G[index][i] = 0;//已访问过，打上标记
            G[i][index] = 0;
            dfs(next, ct + 1);//访问该节点的下一个节点
            path.push_back((char) (next + 'A' - 1));//将该节点添加进路径中
        }
    }

}

void print() {
    for (int i = n; i >= 0; i--) {//逆序输出
        printf("%c", path[i]);
    }
}

int main() {
    in;
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