/**
 * @file 高精度加法.cpp
 * @author horiki
 * @version 0.2
 * @date 2024-04-29 2024-06-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *      
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> A, B, C;

int main()
{
    string a, b; cin >> a >> b;
    for (int i = a.size() - 1; a[i]; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; b[i]; i --) B.push_back(b[i] - '0');

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);

    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    return 0;
}

