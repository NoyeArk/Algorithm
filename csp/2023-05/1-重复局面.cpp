/**
 * @file 1-重复局面.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  哈希表直接AC了，时间复杂度O(n)，空间复杂度O(n)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> h;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        string str;
        for (int j = 1; j <= 8; j ++)
        {
            string s; cin >> s;
            str += s;
        }
        h[str] ++;
        cout << h[str] << endl;
    }
    return 0;
}