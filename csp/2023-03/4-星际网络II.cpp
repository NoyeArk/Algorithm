/**
 * @file 4-星际网络II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-02
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  一些定义：
 *  1.一个地址由n位二进制位组成，其中n是16的倍数。
 *  2.采用类似IPv6协议的十六进制表示法，每4位用:隔开。
 *  3.不会出现IPv6中省略每组的前导0或用::省略一段0的情况。
 *  4. 1 id l r：表示用户id申请地址在l∼r范围内（包含l和r，下同）的一段连续地址块。
 *      4.1 先检查地址是否可用
 *      4.2 如果用户申请的地址全部未被分配，则检查通过
 *      4.3 若地址中存在已经分配给其他用户的地址，则检查失败
 *          4.3.1 检查通过：申请的地址中没有已经分配给其他用户的地址，但含有一些先前已分配给该用户本人的地址。
 *          4.3.2 检查失败：申请的地址先前已全部分配给该用户
 *  5. 2 s：检查地址s被分配给了哪个用户。若未被分配，则结果为0
 *  6. 3 l r：检查l∼r范围内的所有地址是否完整地分配给了某个用户。若是，回答该用户的编号；若否，回答0
 *  
 *  问题：
 *  共出现了q次申请地址和检查地址分配的操作
 *  依次处理每个操作，并回答相应的结果。
 * 
 *  思路：
 *  1.对于某个区间内容的地址是否被占用，使用差分快速修改区间
 *  2.问题是如何将地址转换为数据进行表示
 *      地址最大为ffff:ffff: ... :ffff
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, q;
vector<string> ip;
unordered_map<int, vector<string>> user_ip;
unordered_map<string, int> ip_user;

void init()
{
    // n为32，则一个地址有8位 n/4/4
    string s = "0000";
    for (int i = 2; i <= n / 16; i ++) s += ":0000";
    ip.push_back(s);
    ip_user[s] = -1;

    s = "ffff";
    for (int i = 2; i <= n / 16; i ++) s += ":ffff";
    ip.push_back(s);
    ip_user[s] = -1;
}

bool allocate(int id, string l, string r)
{
    // 找到第一个大于等于l的位置
    int low = lower_bound(ip.begin(), ip.end(), l) - ip.begin();
    // 找到第一个大于等于r的位置    
    int high = lower_bound(ip.begin(), ip.end(), r) - ip.begin();
    if (ip[low] < l && ip[high] > r) 
    {
        ip.push_back(l), ip.push_back(r);  // 分配[l, r]
        user_ip[id].push_back(l);
        user_ip[id].push_back(r);
        ip_user[l] = id, ip_user[r] = id;
        return true;
    }
    return false;
}

// 2 s：检查地址s被分配给了哪个用户。若未被分配，则结果为0
int query(string s)
{
    int low = lower_bound(ip.begin(), ip.end(), s) - ip.begin();
    int high = lower_bound(ip.begin(), ip.end(), s) - ip.begin();
    int a = ip_user[ip[low]], b = ip_user[ip[high]];
    if (a == b && a != -1) return a;
    return 0;
}

// 3 l r：检查l∼r范围内的所有地址是否完整地分配给了某个用户。若是，回答该用户的编号；若否，回答0
int query(string l, string r)
{
    int low = lower_bound(ip.begin(), ip.end(), l) - ip.begin();
    int high = lower_bound(ip.begin(), ip.end(), r) - ip.begin();
    int a = ip_user[ip[low]], b = ip_user[ip[high]];
    if (a == b && a != -1) return a;
    return 0;
}

int main()
{
    cin >> n >> q;
    init();

    while (q --)
    {
        int op, id; cin >> op;
        string l, r, s;
        if (op == 1)
        {
            cin >> id >> l >> r;
            cout << (allocate(id, l, r) ? "YES" : "NO") << endl;
        }
        else if (op == 2)
        {
            cin >> s;
            cout << query(s) << endl;
        }
        else
        {
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }

    system("pause");
    return 0;
}