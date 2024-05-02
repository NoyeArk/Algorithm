/**
 * @file 模拟堆.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  ph[k]：第k个插入的数在堆中的下标是什么
 *  hp[k]：堆中的第几个点是第几个插入的点
 *  支持随机修改和删除
 *  1.插入一个数：
 *      在最后插入一个数，然后up
 *  2.删除第一个数：
 *      将第一个元素和最后一个元素交换，然后删除最后一个数，然后down(1)
 *  3.删除第k个数： 
 *      将第k个数和最后一个数交换，然后删除最后一个数，down(k)或up(k)
 *  4.修改一个元素：
 *      修改之后down(k)或up(k)
 */

#include <iostream>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], len;

void swap_heap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap_heap(u / 2, u);
        u >>= 1;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= len && h[u * 2] < h[t]) t = 2 * u;
    if (u * 2 + 1 <= len && h[u * 2 + 1] < h[t]) t = 2 * u + 1;
    if (t != u)
    {
        swap_heap(t, u);
        down(t);
    }
}

int main()
{
    int n, m = 0; cin >> n;
    
    while (n --) {
        string op; cin >> op;
        if (op == "I")
        {
            int x; cin >> x;
            m ++, len ++;
            ph[m] = len, hp[len] = m;
            h[len] = x;
            up(len);
        }
        else if (op == "PM") cout << h[1] << endl;
        else if (op == "DM") 
        {
            swap_heap(1, len);
            len --;
            down(1);
        }
        else if (op == "D")
        {
            int k; cin >> k;
            k = ph[k];
            swap_heap(k, len);
            len --;
            down(k); up(k);
        }
        else
        {
            int k, x; cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k); up(k);
        }
    }
    
    return 0;
}