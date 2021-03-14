#include <bits/stdc++.h>
using namespace std;

/** \brief      isPowerOfFour 2的幂
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 * 
 *  \param[in] n  输入整数
 *  \return       返回是否是2的幂
 */
bool isPowerOfFour(int n) {
    return (n > 0 && (n & (n - 1)) == 0) && (n&0xaaaaaaaa)==0;
}

int main(int argc, char *argv[])
{
    int output = isPowerOfFour(16);
    std::cout << output << '\n';

    return 0;
}