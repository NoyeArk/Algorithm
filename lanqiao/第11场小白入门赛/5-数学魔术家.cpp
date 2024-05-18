/**
 * @file 5-数学魔术家.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-18
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

int main()
{
    string x; cin >> x;

    for (int i = 0; i < x.size(); i ++)
        num.push_back(x[i] - '0');

    // 找最大值
    sort(num.begin(), num.end(), greater<int>());
    for (auto t : num)
        cout << t;
    cout << " ";

    // 找最小值
    sort(num.begin(), num.end());
    // 判断是否有前导零
    int i = 0;
    while (num[i] == 0 && i < num.size()) i ++;
    cout << num[i];
	
    for (int j = 0; j < num.size(); j ++)
        if (i != j) cout << num[j];

    return 0;
}