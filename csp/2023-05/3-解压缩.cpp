/**
 * @file 3-解压缩.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  1.元素分为两种：字面量和回溯引用。
 *      1.1 字面量：包含一系列的字节，对其进行解压缩时，直接将这些字节输出即可。
 *      1.2 回溯引用：将此前已经解压缩得到的数据流的一部分重复输出。
 *          回溯引用可以表示为⟨o,l⟩，包含两个数字，分别为偏移量o和长度l。
 *          偏移量表示从当前位置向前回溯的距离，长度表示需要重复输出的字节数。其中要求o,l>0。
 *  2.被压缩的数据格式分为两部分：导引域和数据域。
 *      2.1 导引域保存了原始数据的长度。
 *  3.数据域：连续存储的元素的序列
 *      3.1 每个元素的第一个字节的最低两位表示了元素的类型
 *          00：字面量，高6位表示其包含的字节个数(l-1)
 *              如果高6位<=60：随后的l字节即为字面量所包含的原始字节
 *              高6位>60：随后的(高6位-60+1)字节存储了字面量的长度
 *          01：回溯引用<o, l>
 *              o占11位，第8位在随后的字节中，高3位存储于首字节的高3位中。
 *              (l−4)占3位，存储于首字节的2至4位中。
 *          10：回溯引用<o, l>
 *              o占16位，以小端序存储于随后的两个字节中
 *              (l−1)占6位，存储于首字节的高6位中。
 *          11：非法数据域
 */ 

#include <iostream>
#include <cmath>
using namespace std;

string str, out;
int idx, cnt;

// 得到一个字节
int get_byte(bool plus)
{
    int res = 0;
    for (int i = 0; i < 2; i ++)
    {
        res <<= 4;
        char c = str[idx + i];
        // cout << "c: " << c << endl;
        if (c >= '0' && c <= '9') res += c - '0';
        else res += c - 'a' + 10;
    }
    if (plus) idx += 2;
    return res;
}

string get_bytes()
{
    string res = str.substr(idx, 2);
    idx += 2;
    return res;
}

int trans(char a)
{
    if (a >= '0' && a <= '9') return a - '0';
    return a - 'a' + 10;
}

int get_data_len()
{
    int res = 0, p = 1;
    while (true)
    {
        int byte_value = get_byte(true);
        res += p * (byte_value & 0x7F);
        // cout << res << endl;
        p *= 128;
        // 判断最高位是否为1
        // cout << "judge:" << (byte_value >> 7) << endl;
        if ((byte_value >> 7) != 1) break;
    }
    return res;
}

int judge_op_type()
{
    int byte_value = get_byte(false);
    // 判断最低2位
    int one = byte_value & 1, two = byte_value & 2;
    if (one == 0 && two == 0) return 0;
    else if (one == 1 && two == 0) return 1;
    else if (one == 0 && two == 2) return 2;
    return 3;
}

void literal()
{
    int value = get_byte(true);
    // 取高6位
    int l = value >> 2;
    // cout << "L:" << l << endl;
    if (l < 60) 
    {
        // 随后的l字节即为字面量所包含的原始字节
        int literal_len = l + 1;
        // 输出之后的literal_len个字节
        for (int i = 1; i <= literal_len; i ++)
        {
            string ans = get_bytes();
            out += ans;
            cout << ans;
            if (++ cnt % 8 == 0) cout << endl;
        }
    }
    else 
    {
        // 随后的(高6位-60+1)字节存储了字面量的长度
        // 读入长度
        int literal_len = 1;
        for (int i = 0; i < l - 60 + 1; i ++)
        {
            value = get_byte(true);
            if (i) value <<= 8;
            literal_len += value;
        }
        // cout << "literal_len:" << literal_len << endl;;
        // 输出之后的literal_len个字节
        for (int i = 1; i <= literal_len; i ++)
        {
            string ans = get_bytes();
            out += ans;
            cout << ans;
            if (++ cnt % 8 == 0) cout << endl;
        }
    }
}

void back_track1()
{
    int value = get_byte(true);
    // 取高2~4位
    int l = (value >> 2 & 0b00000111) + 4;
    int o = (value & 0b11100000) << 3;
    value = get_byte(true);
    o += value;
    // cout << l << " " << o << endl;

    // 向前回溯o个
    string tmp = out.substr(out.size() - o * 2, o * 2);
    // cout << tmp << endl;
    int num = 0;
    for (int i = 1; i <= l; i ++)
    {
        string s;
        s += tmp[num * 2];
        s += tmp[num * 2 + 1];
        out += s;
        cout << s;
        if (++ num == o) num = 0;
        if (++ cnt % 8 == 0) cout << endl;
    }
}

void back_track2()
{
    int value = get_byte(true);
    // 取高6位
    int l = (value >> 2) + 1;
    int o = 0;
    for (int i = 0; i < 2; i ++)
    {
        int value = get_byte(true);
        if (i) value <<= 8;
        o += value;
    }
    // 向前回溯o个
    string tmp = out.substr(out.size() - o * 2, o * 2);
    // cout << tmp << endl;
    int num = 0;
    for (int i = 1; i <= l; i ++)
    {
        string s;
        s += tmp[num * 2];
        s += tmp[num * 2 + 1];
        out += s;
        cout << s;
        if (++ num == o) num = 0;
        if (++ cnt % 8 == 0) cout << endl;
    }
}

void work()
{
    // 判断是字面量还是回溯引用
    auto op_type = judge_op_type();
    // cout << "op:" << op_type << endl;
    switch (op_type)
    {
    case 0: literal(); break; // 字面量
    case 1: back_track1(); break;
    case 2: back_track2(); break;
        /* code */
        break;
    
    default:
        break;
    }
}

int main()
{
    int s; cin >> s;
    for (int i = 1; i <= ceil((double)s / 8); i ++)
    {
        // 每行读入8个字节
        string s; cin >> s;
        str += s;
    }

    // 得到原始数据长度
    int data_len = get_data_len();
    while (idx < str.size())
    {
        work();
    }
    // work();
    // work();
    // work();
    // work();

    return 0;
}