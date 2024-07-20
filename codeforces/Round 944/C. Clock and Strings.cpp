/**
 * @file C. Clock and Strings.cpp
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
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (b <= c || d <= a || (a <= c && d <= b) || (c <= a && b <= d)) 
			cout << "NO" << endl; 
		else cout << "YES" << endl;
	}

	return 0;
}