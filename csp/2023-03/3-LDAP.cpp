/**
 * @file 3-LDAP.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  需要进行离散化
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

struct Query
{
    LL k, v, dn;
};

const int N = 550;
int n, m;
string str;
vector<int> alls;
vector<Query> query;
unordered_map<int, vector<LL>> h[N];

int find(int x)
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

// 两个vector求交集
vector<LL> vectors_intersection(vector<LL> v1,vector<LL> v2){
    vector<LL> v;
    sort(v1.begin(),v1.end());   
    sort(v2.begin(),v2.end());   
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));//求交集 
    return v;
}

// 两个vector求并集
vector<LL> set_union(vector<LL>& v1,vector<LL>& v2){
	vector<LL> v;
	sort(v1.begin(),v1.end());   
	sort(v2.begin(),v2.end());   
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));//求交集 
	return v;
}

vector<LL> EXPR()
{
    char op; int idx = 0;
    if (str[0] == '&' || str[0] == '|')
        op = str[0], idx += 2;

    vector<LL> res;
    for (int i = idx; i < str.size(); i += 5)
    {
        vector<LL> tmp;
        int k = find(str[i] - '0'), v = str[i + 2] - '0';
        if (str[i + 1] == ':')
        {
            if (h[k].find(v) != h[k].end()) tmp = h[k][v];
        }
        else 
        {
            for (auto it : h[k])
            {
                if (it.first == v) continue;
                tmp.insert(tmp.end(), it.second.begin(), it.second.end());
            }
        }
        if (i <= 5) res = tmp;  // 初始化res

        if (op == '&')
            res = vectors_intersection(res, tmp);
        else res = set_union(res, tmp);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        LL dn, l; cin >> dn >> l;
        while (l --)
        {
            int k, v; cin >> k >> v;
            alls.push_back(k);
            query.push_back({k, v, dn});
        }
    }

    // 离散化
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto q : query)
    {
        int k = find(q.k);
        h[k][q.v].push_back(q.dn);
    }

    cin >> m;
    while (m --)
    {
        cin >> str;
        auto ans = EXPR();
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }

    return 0;
}