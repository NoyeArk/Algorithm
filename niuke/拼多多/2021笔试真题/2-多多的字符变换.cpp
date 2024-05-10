/**
1.状态表示f[i][j]
2.状态计算
    考虑第i个字符:
        a[i] == b[j]: f[i][j] = f[i - 1][j - 1]
        a[i] != b[j]:
            if a[i + 1] == b[j]: f[i][j] = f[i - 1][j - 1]
            else f[i][j] = f[i - 1][j - 1] + abs(a[i] - b[j])
3.这么做不可以，因为可以进行多次交换，这样每个字符可以换到任意位置
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2010;
char a[N], b[N];

int main() {
    int n; cin >> n >> a + 1 >> b + 1;

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += abs(a[i] - b[i]);
    cout << res << endl;
    return 0;
}