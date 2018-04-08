#include<iostream>

using namespace std;

long long mac(int x, int y) {
    if (x == 0)
        return 1;
    long long sum1 = 1, sum2 = 1;
    int temp = x;
    for (int i = 0; i < x; i++, y--)
        sum1 = sum1 * y;
    while (x--) {
        sum2 = sum2 * temp;
        temp = temp - 1;
    }
    return sum1 / sum2;
}

int main() {
    int i;
    long long a[25] = {0, 0, 1, 2};
    for (i = 4; i < 25; i++)
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    int c, m, n;
    long long temp;
    while (cin >> c)//n个人有m个找错，说明有n-m找对了，相当于m个人错排
    {
        while (c--) {
            cin >> n >> m;
            temp = mac(n - m, n);
            cout << temp * a[m] << endl;
        }
    }
    return 0;
}