#include <bits/stdc++.h>
using namespace std;

/** \brief      validPalindrome 验证回文字符串Ⅱ 680
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-25
 * 
 *  \param[in] s   输入字符串
 *  \return        反转字符串中的元音字母
 */
bool chaeckPalindrome(const string& s, int low, int high) {
    while (low < high){
        if(s[low] == s[high])
            ++low, --high;
        else
            return false;
    }
    return true;
}

bool validPalindrome(string& s) {
    int low = 0, high = s.size() - 1;
    while (low < high){
        if(s[low] == s[high])
            ++low, --high;
        else
            return chaeckPalindrome(s, low + 1, high) || chaeckPalindrome(s, low, high - 1);    /**<剩下的必须是回文，已经用掉一次机会了 */
    }
    return true;
}

int main(int argc, char *argv[])
{
    string str = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    bool output = validPalindrome(str);
    cout << output << " ";

    cout << "\n";

    return 0;
}