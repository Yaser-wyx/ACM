#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 200010
using namespace std;
int n, m;
int head[maxn];
int cnt = 0;
int color[maxn];
bool vis[maxn];
int sum[2];
struct edge {
    int next;
    int to;
} edges[maxn];

void add(int a, int b) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].next = head[a];
    head[a] = cnt;//更新以a为起点 的边的位置
}

bool dfs(int node, int flag) {
    if (vis[node]) {
        if (color[node] != flag) {
            return 0;
        } else {
            return 1;
        }
    }
    vis[node] = 1;
    sum[(color[node] = flag) == 1 ? 1 : 0]++;
    bool tf = 1;
    for (int i = head[node]; i != -1 && tf; i = edges[i].next) {
        tf = tf && dfs(edges[i].to, 0 - flag);
    }
    return tf;
}

int main() {
    in;
    mset(head, -1);
    scanf("%d%d", &n, &m);
    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);//无向图
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {//对每一个节点进行遍历访问
        if (vis[i]) {
            continue;//已经访问过了
        }
        mset(sum, 0);
        if (!dfs(i, 1)) {
            printf("Impossible\n");
            return 0;
        }
        ans += min(sum[0], sum[1]);

    }
    printf("%d\n", ans);
    return 0;
}