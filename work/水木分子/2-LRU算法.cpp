/**
 * @file 2-LRU算法.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-15
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

const int N = 4, maxn = 3;
int stk[N], tt;

int a[] = {1, 2, 3, 1, 4, 3, 2};

int main()
{
    for (int i = 0; i < 7; i ++)
    {
        int j = 1;
        bool is_find = false;
        while (j <= tt) 
        {
            if (stk[j] == a[i])
            {
                // 在当前栈中存在这个元素，需要将其移到栈顶
                for (int k = j; k < tt; k ++) 
                    stk[k] = stk[k + 1];
                stk[tt] = a[i];
                is_find = true;
                break;
            }
            j ++;
        }
        if (!is_find)
        {
            // 没有这个元素 
            // 判断栈是否满
            if (tt >= maxn)
            {
                // 栈满 栈底元素移除
                for (int j = 1; j < 3; j ++)
                {
                    stk[j] = stk[j + 1];
                }
                // 将这个元素加入栈顶
                stk[tt] = a[i];
            }
            else stk[++ tt] = a[i];
        }
        // 打印当前栈中元素
        for (int j = 1; j <= tt; j ++)
            cout << stk[j] << " ";
        cout << endl;
    }
    return 0;
}