/**
 * @file 5-施肥.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 题意：
 *  1.n块田地编号为 1,2,…,n, 按照编号从小到大的顺序排成一列
 *  2.第i辆施肥车只能恰好从第li块田地开到第ri块田地，并给编号在li
 *    与ri之间的田地（包含li和ri）都施一遍肥。其中1≤li<ri≤n。
 *  3.编号在L和R之内的田地至少被某一辆施肥车施了一次肥，且编号范围外的田地都没有被施过肥。
 * 思路：
 *  1.n块田地，可以分为长度为2、3、……、n
 *      长度为2：n-1个
 *      长度为3：n-2个
 *      …………
 *      长度为n：1个
 *      一共有1 + 2 + 3 + …… + (n - 1) = n*(n-1)/2个
 *  2.如果遍历每块田地，时间复杂度为O(n²)，而n为10^5，超时
 *  3.应该用O(nlogn)的时间复杂度
 *  4.遍历每个施肥车 O(n)
 *      4.1 每个施肥车都可以作为一个答案
 *      4.2 如果两个或多个施肥车的区间可以无缝合并 可以作为答案
 *  5.能否使用贡献法，看每一个施肥车对最终方案的贡献是多少？
 * 遇到的问题：
 *  1.可能施肥车的施肥空间不是连续的，所以不是n*(n-1)/2
 *  2.只要两个土地或n个土地可以连起来，就选择其中的某几个
 *      1个土地：1 + 0
 *      2个土地：2 + 1
 *      3个土地：3 + 2 + 1
 *      4个土地：4 + 3 + 2 + 1
 *      ……
 *      n个土地：n + n - 1 + ... + 1 = n * (n + 1) / 2
 *  3.但是这种连起来并不能是包含关系，因为如果合起来的结果还是一个
 */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define l first 
#define r second 
typedef pair<int, int> PII;

const int N = 200010;
int n, m;
vector<PII> a;
int diff[N];
bool st[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int l, r; cin >> l >> r;
        a.push_back({l, r});
        // diff[l] ++; diff[r + 1] --;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < a.size(); i ++) cout << a[i].l << " " << a[i].r << endl;
    
    int ans = 0;
    for (int i = 0; i < a.size(); i ++)
    {
        if (st[i]) continue;
        cout << "cur:" << a[i].l << " " << a[i].r << endl;
        // 当前田地算一个
        int cnt = 1, max_r = a[i].r;
        st[i] = true;
        for (int j = i + 1; j < a.size(); j ++)
        {
            if (a[j].l >= a[i].l && a[j].r <= max_r) 
                break;
            if (a[j].l <= max_r + 1) 
            {
                cnt ++;
                st[j] = true;
                max_r = max(max_r, a[j].r);
            }
        }
        ans += cnt * (cnt + 1) / 2;
        cout << "cnt:" << cnt << " ans:" << ans << endl;
    }
    
    cout << ans;
    return 0;
}