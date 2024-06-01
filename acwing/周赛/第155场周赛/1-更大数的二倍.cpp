/**
 * @file 更大数的二倍.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include <iostream>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	cout << 2 * max(a, b);
	return 0;
}