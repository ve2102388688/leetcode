#include <bits/stdc++.h>
using namespace std;

/** \brief      isPalindrome  验证回文串
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-9
 * 
 *  \param[in] s 输入字符串s     
 *  \return      时候是回文串
 */
bool isPalindrome(string s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high) {
        while (low < high && !isalnum(s[low])) ++low;           /**<找到第一个数字或字母 */
        while (low < high && !isalnum(s[high])) --high;

        if (low < high && tolower(s[low]) != tolower(s[high]))  /**<不相等直接退出 */
            return false;
        ++low, --high;                                          /**<下次循环 */
    }
    return true;
}

int main(int argc, char *argv[])
{
    bool output = isPalindrome(".,");
    std::cout << output << std::endl;

    return 0;
}