#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t) memset(t,0,sizeof(t))
#define maxn 100005
using namespace std;
int fa[maxn];

void init(int n) {
    for (int i = 0; i <= n; fa[i] = i++);
}

int find(int u) {
    return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void _union(int u, int v) {
    fa[find(v)] = find(u);
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        _union(a, b);
    }
    return 0;
}