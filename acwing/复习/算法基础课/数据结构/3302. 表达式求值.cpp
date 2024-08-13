/**
 * @file 151. 表达式计算4.cpp
 * @author 弘树
 * @version 0.1
 * @date 2024-08-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  算法基础课中有一个题目也是表达式求值，这里唯一不同就是数据可能出现负数
 *  此时符号不是代表减号
 *  一种解决方法是如果判断当前减号表示负号，那么将 0 入数字栈
 *  如何判断当前减号是否为负号呢？
 *  可以先分析一下如果是减号，那么减号前面肯定是数字，如果不是数字，那么肯定是符号
 */

#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

stack<LL> num;
stack<char> op;

void eval()
{
    auto c = op.top(); op.pop();
    if (c == '(') return ;
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    LL res = 0;
    if (c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*') res = a * b;
    else if (c == '/') res = a / b;
    else res = pow(a, b);
    printf("%ld%c%ld=%ld\n", a, c, b, res);
    num.push(res);
    cout << "栈中数据：" << endl;
    auto tmp = num;
    while (tmp.size()) 
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 2}};
    
    string str; cin >> str;
    for (int i = 0; i < str.size(); i ++)
    {
        auto c = str[i];
        if (isdigit(c)) 
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j ++] - '0';
            i = j - 1;
            num.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(') eval();
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            if (c == '-' && str[i - 1] != ')' && (!i || !isdigit(str[i - 1]))) 
            {
                cout << "*************" << endl;
                num.push(0);
            }
            op.push(c);
        }
    }
    
    auto t = op;
    while (t.size())
    {
        cout << t.top();
        t.pop();
    }
    cout << endl;
    
    while (op.size() && num.size()) eval();
    cout << num.top();

    return 0;
}