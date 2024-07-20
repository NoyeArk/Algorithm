/**
 * @file A. My First Sorting Problem.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-07-20
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t --)
	{
		int a, b; cin >> a >> b;
		cout << min(a, b) << " " << max(a, b) << endl;
	}

	return 0;
}