#include <bits/stdc++.h>

typedef long long int lli;
#define data  "E:\\WorkSpace\\ACM\\data.in"
#define in fstream _file;_file.open(data,ios::in);if(_file)freopen(data,"r",stdin);

using namespace std;

int main() {
    in;
    int n;
    scanf("%d", &n);
    int temp;
    bool flag = 0;
    for (int i = n; i >= 0; i--) {
        scanf("%d", &temp);
        if (temp == 0) {
            continue;
        }
        if (i == 0) {
            //最后一个元素
            //直接输出
            if (temp > 0) {
                printf("+");
            }
            printf("%d", temp);
        } else {
            //不是最后一个元素
            if (temp > 0) {
                if (flag) {
                    printf("+");
                } else {
                    flag = 1;
                }
                if (temp != 1) {
                    printf("%d", temp);
                }
            } else {
                if (temp == -1) {
                    printf("-");
                } else
                    printf("%d", temp);
            }
            if (i == 1) {
                printf("x");
            } else
                printf("x^%d", i);
        }


    }
    return 0;
}