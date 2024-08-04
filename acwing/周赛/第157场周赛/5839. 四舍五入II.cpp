/**
 * @file 5839. 四舍五入II.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	每一位向前最多进几位：每一位最多只会加1
 * 	从左向右找第一个大于等于5的数，对其进行操作，使其进位
 * 	之后从
 */

#include <iostream>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	string s; cin >> s;

	int dot = s.find('.');
	int k = dot + 1;
	while (k < s.size() && s[k] < '5') k ++;

	if (k == s.size()) 
	{
		cout << s << endl;
		return 0;
	}
	
	s = s.substr(0, k);
	k --, m --;
	while (k >= 0)
	{
		if (s[k] != '.')
		{
			
		}
	}

	return 0;
}