/**
 * @file 高精度减法.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> A, B;

bool cmp()
{
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i --)
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++)
    {
        t += A[i];
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a, b; cin >> a >> b;
    for (int i = a.size() - 1; a[i]; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; b[i]; i --) B.push_back(b[i] - '0');

    if (cmp())
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    }
    else 
    {
        cout << "-";
        auto C = sub(B, A);
        for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    }
    return 0;
}