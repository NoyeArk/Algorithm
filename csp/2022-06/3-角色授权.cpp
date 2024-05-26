/**
 * @file 3-角色授权.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-26
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	1.安全模型将验证流程分为两个步骤：
 * 		第一步是验证用户的身份（鉴别）
 * 		第二步是验证用户的权限（授权）
 * 	2.第一步：验证一个用户是否是该用户所声称的那个身份
 * 		2.1 验证用户提供的口令（Password）是否正确
 * 		2.2 验证用户提供的智能卡是否合法有效
 * 	3.第二步：权限策略会被检索以便判断来访的用户是否能够操作系统中的某个资源
 * 	4.一个用户具有下列要素：
 * 		名称：是一个字符串，用于唯一标识一个用户；
 * 		用户组：是一个数组，包含若干个字符串，表示该用户所属的用户组。
 * 	5.一个待授权的行为，包括下列要素：
 * 		主体：是一个用户，包括试图进行该行为的用户的名称和该用户所属的用户组；
 * 		操作：是一个字符串，一般是一个动词，例如Read、Open、Close等
 * 		资源：表示该行为的操作对象，由资源种类和资源名称描述。例如Door、File等。
 * 			在一个特定的资源种类中，资源名称唯一确定了一个资源。
 * 	6.一个待授权的行为的主体信息，即用户名称和所属用户组，
 * 		是由前一步骤的鉴别过程完成的。
 * 	7.每次授权过程中，每个待授权的行为都会包含主体用户和其关联的用户组的信息。
 * 	8.一个角色包含下列要素：
 * 		名称，是一个字符串，用于唯一标识一个角色；
 * 		操作清单，是一个数组，包含一个或多个操作，表示该角色允许执行的操作集合；
 * 		资源种类清单，是一个数组，包含一个或多个资源种类，表示该角色允许操作的资源的种类集合；
 * 		资源名称清单，是一个数组，包含若干个资源名称，表示该角色允许操作的资源的名称集合。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int N = 510;
int n, m, q;
struct Role
{
	string name;
	vector<string> op;
	vector<string> src_type;
	vector<string> src_name;
}role[N];

unordered_map<string, int> role_name2id;
unordered_map<string, vector<string>> user_name2role;

// 判断角色role[id]是否能完成op src_type src_name
bool check(int id, string op, string src_type, string src_name)
{
	// 遍历该角色的操作
	for (auto s : role[id].op)
		if (s == op || s == "*")
		{
			// 可以完成op操作
			for (auto type : role[id].src_type)
				if (type == src_type || type == "*")
				{
					if (role[id].src_name.size() == 0)
						return true;
					else 
					{
						for (auto name : role[id].src_name)
							if (name == src_name) return true;
					}
				}
		}
	return false;
}

int main()
{
	cin >> n >> m >> q;

	// 读入n个角色
	for (int i = 1; i <= n; i ++)
	{
		cin >> role[i].name;
		// 读入操作清单中的操作
		int nv; cin >> nv;
		while (nv --) 
		{
			string s; cin >> s;
			role[i].op.push_back(s);
		}
		// 读入资源种类
		int no; cin >> no;
		while (no --)
		{
			string s; cin >> s;
			role[i].src_type.push_back(s);
		}
		// 读入资源名称
		int nn; cin >> nn;
		while (nn --)
		{
			string s; cin >> s;
			role[i].src_name.push_back(s);
		}
		role_name2id[role[i].name] = i;
	}

	// 读入m个角色关联
	for (int i = 1; i <= m; i ++)
	{
		string role_name; cin >> role_name;
		int ns; cin >> ns;
		while (ns --)
		{
			char c;
			string name; cin >> c >> name;
			if (c == 'u')
				user_name2role[name].push_back(role_name);
			else user_name2role[name].push_back(role_name);
		}
	}

	// q个查询
	while (q --)
	{
		string name; cin >> name;
		int ng; cin >> ng;
		vector<string> group;
		// 该用户所属的用户组的名称
		while (ng --)
		{
			string s; cin >> s;
			group.push_back(s);
		}
		string op, src_type, src_name; cin >> op >> src_type >> src_name;

		bool ans = false;
		// 判断该用户是否有权限
		if (user_name2role.find(name) != user_name2role.end())
		{
			auto role_names = user_name2role[name];
			for (auto role_name : role_names)
			{
				auto id = role_name2id[role_name];
				if (check(id, op, src_type, src_name))
				{
					ans = true;
					break;
				}
			}
		}
		if (ans)
		{
			cout << 1 << endl;
			continue;
		}
		// 遍历用户所属的每个用户组
		for (auto g : group)
		{
			if (user_name2role.find(g) != user_name2role.end())
			{
				auto role_names = user_name2role[g];
				for (auto role_name : role_names)
				{
					auto id = role_name2id[role_name];
					if (check(id, op, src_type, src_name))
					{
						ans = true;
						break;
					}
				}
			}
		}
		cout << (ans ? 1 : 0) << endl;
	}
	return 0;
}