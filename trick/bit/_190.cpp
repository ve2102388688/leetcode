#include <bits/stdc++.h>
using namespace std;

/** \brief      reverseBits 位1的个数 191
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 * 
 *  \param[in] n  输入整数
 *  \return       返回颠倒的数字
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int i = 32;             /**<一定要循环32次，换成n的话，高位的0不会移动 */
    while (i--){
        ans <<= 1;
        ans += n & 1;       /**<加上最低位 */
        n >>= 1;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int output = reverseBits(6);
    std::cout << output << '\n';

    return 0;
}