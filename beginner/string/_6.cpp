#include <bits/stdc++.h>
using namespace std;

/** \brief      myAtoi  字符串转整数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-9
 * 
 *  \param[in] s 输入字符串s       
 *  \return      返回整数
 */
int myAtoi(string s) {
    int i = 0;
    while (isspace(s[i])) ++i;                  /**< 跳过空白符 */

    int sign = (s[i] == '-') ? -1 : 1;          /**<判断是否是负数 */
    
    if (s[i] == '-' || s[i] == '+')             /**< 跳过正，负号 */
        ++i;

    int result = 0;
    int upperBound = INT_MAX / 10;              /**< 和下面的判断，联合起来判断是否超过INT_MAX */

    for (; isdigit(s[i]); ++i) {
        /**<判断是否超过最大值 */
        if (result > upperBound || (result == upperBound && s[i] > '7')) {
            return sign > 0 ? INT_MAX : INT_MIN;
        }
        result = 10 * result + s[i] - '0';
    }

    return (sign > 0) ? result : -result;
}

int main(int argc, char *argv[])
{
    int output = myAtoi("21474836460000000");
    std::cout << output << std::endl;

    return 0;
}