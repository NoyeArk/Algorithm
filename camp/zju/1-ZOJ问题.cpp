/**
 * @file 1-ZOJ问题.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	找到o的数量的关系即可
 * 		'z'前面有a个'o';
 *      'z'与'j'之间有b个'o';
 *      'j'后面有c个'o';
 *      当满足 b != 0 && c == a * b 的时候，就可以AC
 *	题目链接：https://www.nowcoder.com/questionTerminal/e132f7aa63bb430494db3644b8ffa860?f=discussion
 */

#include <iostream>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int pos_z = s.find('z'), pos_j = s.find('j');
		int a = pos_z, b = pos_j - pos_z - 1, c = s.size() - 1 - pos_j;
		if (b && c == a * b) printf("Accepted\n");
		else printf("Wrong Answer\n");
	}

	return 0;
}