//#pragma GCC optimize(2)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1005
#define maxm 10005
int n, m, t;
int times[maxn];//从第i个到第j个站台所需时间
struct people {
    int time;
    int from;
    int to;

    bool operator<(const people &rhs) const {
        if (from != rhs.from) {
            return from < rhs.from;
        } else {
            return time < rhs.time;
        }
    }

} peoples[maxm];

pair<int, int> cnt[maxn];//终点站
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}


int main() {
    in;
    scanf("%d%d%d", &n, &m, &t);
    loop(i, 2, n) {
        scanf("%d", &times[i]);//保存从上一个站台到i站台的时间
    }
    loop(i, 1, m) {
        scanf("%d%d%d", &peoples[i].time, &peoples[i].from, &peoples[i].to);
        cnt[peoples[i].to].second++;
        cnt[peoples[i].to].first = peoples[i].to;
    }
    sort(cnt + 2, cnt + 2 + n, cmp);//将到第i站的人数进行从大到小排序
    sort(peoples + 1, peoples + 1 + m);//将人按照站台的起始位置和到起点的时间，从小到大排序
    int index = 2;
    while (t > 0 && index <= n) {
        if (times[cnt[index].first] < t) {
            //如果从上一站到该站所需要的时间小于加速器的个数
            times[cnt[index].first] = 0;
            t -= times[cnt[index].first];
            index++;
        } else {
            //否则用完加速器
            times[cnt[index].first] -= t;
            t = 0;
        }
    }

    return 0;
}
