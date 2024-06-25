/**
 * @file 794. 高精度除法.cpp
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
#include <algorithm>
using namespace std;

typedef long long LL;

vector<int> A;

vector<int> div(vector<int> A, int b, int& r)
{
	vector<int> C;
	for (int i = A.size() - 1; i >= 0; i --)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main()
{
	string a; int b; cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

	int r = 0;
	auto C = div(A, b, r);

	for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
	cout << endl << r; 

	return 0;
}