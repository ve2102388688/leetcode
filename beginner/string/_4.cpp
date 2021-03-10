#include <bits/stdc++.h>
using namespace std;

/** \brief      isAnagram  整数反转
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-9
 * 
 *  \param[in] s 输入字符串s     
 *  \param[in] t 输入字符串t 
 *  \return      是否是字母异位词
 */
bool isAnagram(string s, string t) {
    // // ****** Method1
    // int size1 = s.size();
    // int size2 = t.size();
    // if(size1 != size2)           /**<长度不等，直接退出 */
    //     return false;

    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());

    // for (int i = 0; i < size1; ++i) {
    //     if(s[i] != t[i])
    //         return false;
    // }
    // return true;

    if(s.size() != t.size())        /**<长度不等，直接退出 */
        return false;

    int letterNum[26] = {0};
    for (const auto &e : s)
        ++letterNum[e - 'a'];
    for(const auto& e : t)
        --letterNum[e - 'a'];
    
    for (int i = 0; i < 26; i++)
        if(letterNum[i] != 0)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    bool output = isAnagram("anagram", "nagaram");
    std::cout << output << std::endl;

    return 0;
}