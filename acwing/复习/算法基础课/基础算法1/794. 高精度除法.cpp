/**
 * @file 794. 高精度除法.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-07
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;

vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> C;
    for (auto x : A)
        r = r * 10 + x, C.push_back(r / b), r %= b;
    reverse(C.begin(), C.end());
    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}

int main()
{
    string a; int b; cin >> a >> b;
    for (int i = 0; a[i]; i ++) A.push_back(a[i] - '0');

    int r = 0;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl << r;

    return 0;
}