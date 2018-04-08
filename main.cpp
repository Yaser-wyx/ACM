#include <iostream>

namespace m {
    using namespace std;
#define max 100001
    long long int a[max], b[max];
    long long int c = 0;

    void mergesort(long long int a[], int s, int m, int e) {
        int i = s, j = m + 1, k = s;
        while (i <= m && j <= e) {
            if (a[i] <= a[j]) {
                b[k] = a[i];
                k++;
                i++;
            } else {
                c += m - i + 1;
                b[k] = a[j];
                k++;
                j++;
            }
        }
        while (i <= m) {
            b[k] = a[i];
            k++;
            i++;
        }
        while (j <= e) {
            b[k] = a[j];
            k++;
            j++;
        }
        for (i = s; i <= e; i++) {
            a[i] = b[i];
        }
    }

    void mergee(long long int a[], int b, int e) {

        if (b < e) {
            int m = (b + e) / 2;
            mergee(a, b, m);
            mergee(a, m + 1, e);
            mergesort(a, b, m, e);
        }
    }

}
using namespace m;

int main() {
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergee(a, 0, n - 1);
    cout << c << endl;
    return 0;
}