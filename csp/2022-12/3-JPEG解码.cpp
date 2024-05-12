/**
 * @file 3-JPEG解码.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-12
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 *  如何实现对角线遍历？
 *      
 */

#include <iostream>
#include <cmath>
#include <cstring>

#define PI acos(-1) 
using namespace std;

const int N = 65;
int n, t;
double tmp[10][10];
double q[10][10], m[10][10];
double scan[N];

void print_m()
{
    for (int i = 0; i < 8; i ++)
    {
        for (int j = 0; j < 8; j ++)   
            printf("%.lf ", m[i][j]);
        cout << endl;
    } 
}

void fill()
{
    // 读入扫描数据
    for (int i = 0; i < n; i ++) cin >> scan[i];
    // 填充矩阵M
    int cnt = 0, sum = 0;
    bool left = false;
    while (cnt < n)
    {
        if (left)
            for (int i = max(0, sum - 7), j = sum - i; i <= min(sum, 7); i ++, j --)
            {
                m[i][j] = scan[cnt ++];
                // printf("i:%d j:%d m[i][j]:%.lf\n", i, j, m[i][j]);
            }
        else
            for (int j = max(0, sum - 7), i = sum - j; i >= max(0, sum - 7); i --, j ++)
            {
                m[i][j] = scan[cnt ++];
                // printf("i:%d j:%d m[i][j]:%.lf\n", i, j, m[i][j]);
            }
        sum ++;
        left = left ? false : true;
    }
}

void mult()
{
    // 将矩阵M中的每个元素都乘以量化矩阵Q中的对应元素
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j ++)   
            m[i][j] *= q[i][j];
}

void decode()
{
    fill();
    mult();

    // 对矩阵M进行离散余弦逆变换
    memcpy(tmp, m, sizeof m);
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j ++)
        {
            double sum = 0;
            for (int u = 0; u < 8; u ++)
                for (int v = 0; v < 8; v ++)
                {
                    double au = u == 0 ? sqrt(0.5) : 1;
                    double av = v == 0 ? sqrt(0.5) : 1;
                    sum += au * av * tmp[u][v] * cos((PI / 8) * (i + 0.5) * u) * cos((PI / 8) * (j + 0.5) * v);
                }
            m[i][j] = sum / 4;
        }
    // 将矩阵M′中的每个元素都加上128
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j ++)
        {
            m[i][j] = (m[i][j] + 128);
            m[i][j] = max(m[i][j], 0.0);
            m[i][j] = min(m[i][j], 255.0);
        }
    print_m();
}

int main()
{
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j ++)  
            cin >> q[i][j];

    cin >> n >> t;
    if (t == 0)
    {
        fill();
        print_m();
    }
    else if (t == 1)
    {
        fill();
        mult();
        print_m();
    }
    else decode();

    return 0;
}