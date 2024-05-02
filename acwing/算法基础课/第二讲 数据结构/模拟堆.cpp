/**
 * @file 模拟堆.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  支持随机修改和删除
 */

#include <iostream>
using namespace std;

const int N = 100010;
int h[N], len;

void up(int u)
{
    
}

void down(int u)
{
    
}

int main()
{
    int n; cin >> n;
    
    while (n --) {
        string op; cin >> op;
        if (op == "I")
        {
            int x; cin >> x;
            h[++ len] = x; 
        }
        else if (op == "PM") cout << h[1] << endl;
        else if (op == "DM") 
        {
            
        }
        else if (op == "D")
        {
            int k; cin >> k;
            
        }
        else
        {
            int k, x; cin >> k >> x;
            
        }
    }
    
    return 0;
}