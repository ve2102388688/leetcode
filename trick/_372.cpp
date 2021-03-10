#include <bits/stdc++.h>
using namespace std;

// // 针对两个long long相乘可能导致溢出
// // (ab)%mod
// long long multiplyMod(long long a, long long b, long long mod) {
//     long long ans = 0, y = a % mod;
//     while (b) {
//         if (b & 1)
//             ans = (ans + y) % mod;
//         y = (y * 2) % mod;
//         b >>= 1;
//     }
//     return ans;
// }

// // 快速幂取模，非递归算法
// long long modulo(long long a, long long b, long long mod) {
//     long long ans = 1, rns = a;                  /**<ans结果，rns是指数的阶 */
//     while (b) {
//         if (b & 1)
//             ans = multiplyMod(ans, rns, mod);    /**<ans = (ans*rns)%mod */
//         rns = multiplyMod(rns, rns, mod);        /**<rns = (rns*rns)%mod */
//         b >>= 1;                                 /**<每次循环一次，移位一次 */
//     }
//     return ans;
// }

// /** \brief      superPow 超级次方 372
//  *  \author     wzk
//  *  \copyright  GNU Public License
//  *  \version    1.0 
//  *  \date       2020-2-19
//  * 
//  *  \param[in] a 输入底数
//  *  \param[in] b 输入指数
//  *  \return      返回(a^b)%k
//  */
// int superPow(int a, vector<int>& b) {
//     if (b.size() == 0)
//         return 1;
    
//     int last = b.back(); b.pop_back();

//     int part1 = modulo(a, last, 1337);
//     int part2 = modulo(superPow(a, b), 10, 1337);

//     return multiplyMod(part1, part2, 1337);
// }

// 快速幂递归算法
int mypow(int a, int k) {
    if (k == 0)
        return 1;
    
    a %= 1337;
    if (k%2 == 1) {
        return a*mypow(a, k-1) % 1337;
    } else {
        int temp = mypow(a, k/2);
        return (temp * temp) % 1337;
    }
}

int superPow(int a, vector<int>& b) {
    if (b.size() == 0)
        return 1;
    
    int last = b.back(); b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    return (part1*part2)%1337;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,0,0};

    int output = superPow(2147483647, nums);
    std::cout << output << '\n';

    return 0;
}