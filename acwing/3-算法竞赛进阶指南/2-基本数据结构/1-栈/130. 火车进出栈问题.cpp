/**
 * @file 130. 火车进出栈问题.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-06
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mult(vector<int> A, int b)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || t; i ++)
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() && C.back() == 0) C.pop_back();
    return C;
}

vector<int> div(vector<int> A, int b)
{
    int r = 0;
    vector<int> C;
    for (auto x : A)
        r = r * 10 + x, C.push_back(r % 10), r /= 10;
    reverse(C.begin(), C.end());
    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}

int main()
{
    vector<int> A(1);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
        A = div(mult(A, 4 * i - 2), i + 1);

    for (int i = A.size() - 1; ~i; i --) cout << A[i];
    return 0;
}