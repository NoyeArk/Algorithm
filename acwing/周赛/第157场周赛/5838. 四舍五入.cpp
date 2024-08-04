/**
 * @file 1.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
	int x; cin >> x;
	cout << (x % 10 >= 5 ? x / 10 * 10 + 10 : x - x % 10);
	return 0;
}