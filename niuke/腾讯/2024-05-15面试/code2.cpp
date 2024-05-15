/**
 * @file code2.cpp
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

int idx = 0;
string str = "";

int judge(int id, char c)
{
    int res = 0;
    for (int i = id + 1; i < str.size(); i ++)
        if (str[i] == c) res ++;
    return res;
}

int main() 
{
    string ans;

    int i = 0;    
    while (i < str.size())
    {
        int res = judge(i, str[i]);
        ans += str[i];
        if (res != 0) {
            ans += to_string(res + 1);
        }
        i += res + 1;
    }

    cout << ans << endl;
}