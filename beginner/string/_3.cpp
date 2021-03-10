#include <bits/stdc++.h>
using namespace std;

/** \brief      firstUniqChar  字符串中的第一个唯一字符
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-9
 * 
 *  \param[in] s 输入字符串s    
 *  \return      字符串中的第一个唯一字符的下标
 */
int firstUniqChar(string s) {
    // Method1
    int letter[26] = {0};                               /**<26个字母出现的次数 */
    unordered_map<int, int> letter_first_position;      /**<字母第一次出现的下标，unordered_map效率更高 */
    int totalNumber = 26;                               /**<每当字母出现第二次，就减1，到0表示所有字母都重复出现了，返回-1 */

    /**<遍历数组，累计次数；如果所有字母均重复出现立即返回-1；第一次出现的下标 */
    for (int i = 0; i < s.size(); ++i) {
        int offset = s[i] - 'a';
        ++letter[offset];                       /**<累计次数 */
        if(letter[offset] == 2)                 /**<如果所有字母均重复出现立即返回-1 */
            --totalNumber;
        if(totalNumber == 0)
            return -1;
        letter_first_position[offset] = i;      /**<第一次出现的下标 */
    }

    vector<int> onlyOnce;                       /**<只出现一次的字母，可能有多个 */
    for (int i = 0; i < 26; ++i) {
        if(letter[i] == 1)
            onlyOnce.push_back(i);
    }
    
    if(onlyOnce.size() == 0)                    /**<没有出现一次的字母 */
        return -1; 

    int firstPosition = INT_MAX;                /**<求取下标最小的那个字母 */
    for (const auto &e : onlyOnce) {
        int res =  letter_first_position.find(e)->second;
        firstPosition = firstPosition < res ? firstPosition : res;
    }

    return firstPosition;


    // //*********** Method2
    // int ans[26] = {0};
    // for (int i = 0; i < s.size(); i ++) 
    //     ans[s[i] - 'a'] ++;
    // for (int i = 0; i < s.size(); i ++) {
    //     if (ans[s[i] - 'a'] == 1) return i;
    // }
    // return -1;
}

int main(int argc, char *argv[])
{
    int output = firstUniqChar("itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb");
    std::cout << output << std::endl;

    return 0;
}