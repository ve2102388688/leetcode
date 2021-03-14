#include <bits/stdc++.h>
using namespace std;

/** \brief      findTheDifference 找不同 389
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 * 
 *  \param[in] s  输入字符串s
 *  \param[in] t  输入字符串t
 *  \return       返回插入的字符串
 */
char findTheDifference(string& s, string& t) {
    int res = 0;
    for(const auto& e: s)
        res ^= e;
    for(const auto& e: t)
        res ^= e;
    return res;
}

int main(int argc, char *argv[])
{
    string s = "abccd";
    string t = "abccde";
    int output = findTheDifference(s, t);
    std::cout << output << '\n';

    return 0;
}