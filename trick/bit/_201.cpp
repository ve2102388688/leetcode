#include <bits/stdc++.h>
using namespace std;

/** \brief      rangeBitwiseAnd 数字范围按位与 201
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-27
 *  \remark     Brian Kernighan算法
 * 
 *  \param[in] m  输入m
 *  \param[in] n  输入n
 *  \return       返回异或值
 */
int rangeBitwiseAnd(int m, int n) {
    while (m < n) {
        // 抹去最右边的 1
        n = n & (n - 1);
    }
    return n;
}

int main(int argc, char *argv[])
{
    int output = rangeBitwiseAnd(5, 9);
    std::cout << output << '\n';

    return 0;
}