#include <bits/stdc++.h>
using namespace std;

/** \brief      reverse  整数反转
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-7
 * 
 *  \param[in] s 输入整数        
 *  \return      返回反序的数
 */
int reverse(int x) {
    int res = 0;            /**<结果 */
    while (x != 0) {
       int pop = x % 10;
        x /= 10;
        if (res > INT_MAX/10 || (res == INT_MAX / 10 && pop > 7)) return 0;
        if (res < INT_MIN/10 || (res == INT_MIN / 10 && pop < -8)) return 0;
        res = res * 10 + pop;
    }
}

int main(int argc, char *argv[])
{
    int output = reverse(-2147483412);
    std::cout << output << std::endl;

    return 0;
}