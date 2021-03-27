#include <bits/stdc++.h>
using namespace std;

/** \brief      hammingDistance 汉明距离 461
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-27
 *  \remark     Brian Kernighan算法
 * 
 *  \param[in] x  输入x
 *  \param[in] y  输入y
 *  \return       返回变换次数
 */
int hammingDistance(int x, int y) {
    int num = x ^ y;
    int res = 0;
    while(num) {
        ++res;
        num = num & (num-1);
    }
    return res;
}

int main(int argc, char *argv[])
{
    int output = hammingDistance(5, 9);
    std::cout << output << '\n';

    return 0;
}