#include <bits/stdc++.h>
using namespace std;

/** \brief      hammingWeight 位1的个数 191
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 * 
 *  \param[in] n  输入整数
 *  \return       返回只出现1的次数
 */
int hammingWeight2(uint32_t n) {
    return bitset<32>(n).count();
}


int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        ans += n&1;     /**<判断最低位为1 */
        n >>= 1;
    }
    return ans;
}

int hammingWeight3(uint32_t n) {
    int ans = 0;
    while (n) {
        ++ans;
        n = n & (n - 1);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int output = hammingWeight(5);
    std::cout << output << '\n';

    return 0;
}