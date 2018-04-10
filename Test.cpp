#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t) memset(t,0,sizeof(t))
#define maxn 100005
using namespace std;

int w, n;
int p[maxn];

int main() {
    in;
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + n);

    return 0;
}