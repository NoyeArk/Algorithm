/**
 * @file 153. 双栈排序.cpp
 * @author horiki
 * @date 2024-08-28
 * 
 * @brief 
 *  对于当前输入序列的第一个元素a来说，如果栈S1中有元素小于a，那么不能入S1
 *  如果栈S2中也有元素小于a，那么也不能入S2，则无解
 *  任何时候能满足放入S1的，先放入S1，放不了的再考虑S2
 *  同时如果有序序列的当前需要的元素是a，那么a入栈后立马出栈
 *  ---------------------------------------------------
 *  不是每次都要放入S1中，应该是放入S1和S2中最后一个元素最接近当前元素a的栈中
 */

#include <iostream>
using namespace std;

const int N = 1010;
int s1[N], s2[N], tt1 = -1, tt2 = -1;
int need = 1;
string ans;

void check(int stk[], int x)
{
    // stk一定是一个单调递减的栈，如果找stk是否有小于x的元素，只需要判断最后一个元素是否小于x即可
}

void push_s1(int x)
{
    s1[++ tt1] = x, ans += 'a';
}

void push_s2(int x)
{
    s2[++ tt2] = x, ans += 'c';
}

bool pop_s1()
{
    if (tt1 != -1 && s1[tt1] == need)
    {
        tt1 --, ans += 'b', need ++;
        return true;
    }
    return false;
}

bool pop_s2()
{
    if (tt2 != -1 && s2[tt2] == need)
    {
        tt2 --, ans += 'd', need ++;
        return true;
    }
    return false;
}

int main()
{
    int n; cin >> n;

    for (int i = 1; i <= n; i ++)
    {
        int x; cin >> x;

        if (tt1 == -1 && tt2 == -1) push_s1(x);
        else if (tt1 == -1 && tt2 != -1) push_s1(x);
        else if (tt1 != -1 && tt2 == -1)
        {
            if (s1[tt1] > x) push_s1(x);
            else push_s2(x);
        }
        else 
        {
            if ()
        }

        // 判断能否放入s1中
        if (tt1 == -1 || s1[tt1] > x) 
        else if (tt2 == -1 || s2[tt2] > x) s2[++ tt2] = x, ans += 'c';
        else
        {
            cout << 0;
            return 0;
        }
        // 判断是否需要马上出栈
        while (pop_s1() || pop_s2());
    }

    for (auto c : ans) cout << c << " ";

    return 0;
}