/**
 * @file 826. 单链表.cpp
 * @author horiki
 * @date 2024-09-14
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 200010;
int h[N], e[N], ne[N], idx;

int main()
{
    int m; cin >> m;
    while (m --)
    {
        char op; int x, k; cin >> op;
        if (op == 'H') 
        {
            cin >> x; 
            add(x);
        }
        else if (op == 'D') 
    }

    return 0;
}