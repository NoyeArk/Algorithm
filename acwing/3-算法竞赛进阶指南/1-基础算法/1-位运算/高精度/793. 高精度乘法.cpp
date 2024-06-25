/**
 * @file 793. 高精度乘法.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-22
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

vector<int> mult(vector<int>& A, int b)
{
	vector<int> C;
	for (int i = 0, t = 0; i < A.size() || t; i ++)
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main()
{
	string a;
	int b; cin >> a >> b;

	for (int i = a.size() - 1; a[i]; i --) A.push_back(a[i] - '0');
	auto C = mult(A, b);
	for (int i = C.size() - 1; i >= 0; i --) cout << C[i];

	return 0;
}