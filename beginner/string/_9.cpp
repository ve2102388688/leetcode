#include <bits/stdc++.h>
using namespace std;

string lcp(const string& str1, const string& str2) {
    int shortLength = std::min(str1.size(), str2.size());
    int i = 0;
    while (i < shortLength && str1[i] == str2[i]) ++i;      /**<只需要考虑最短的就好了，依次比较即可 */

    return str1.substr(0, i);
}

/** \brief      longestCommonPrefix  最长公共前缀
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-11
 *  \see        https://www.jianshu.com/p/4ef3cfa01367
 * 
 *  \param[in] strs 输入字符数组    
 *  \return         返回最长公共前缀，否则返回空
 */
string longestCommonPrefix(vector<string>& strs) {
    // //  Method1 纵向扫描
    // int size2 = strs.size();                        /**<字符串个数 */
    // if(size2 == 0)
    //     return "";

    // /**<纵向比较法 */
    // int size1 = strs[0].size();                                 /**<对字符串0遍历 */
    // for (int i = 0; i < size1; ++i) {
    //     for (int j = 1; j < size2; ++j) {                       /**<第二个字符串开始 */
    //         if(i == strs[j].size() || strs[0][i] != strs[j][i]) /**<要先判是否达到字符串末尾 */
    //             return strs[0].substr(0, i);
    //     }
    // }
    // return strs[0];                                             /**<此时只有一个字符串 */

    // 横向扫描
    int size = strs.size();                         /**<字符串个数 */
    if(size == 0)                                   /**<字符串个数为0，返回空 */
        return "";
    string result = strs[0];                        /**<即使最总只有一个字符串，也不会错 */

    for(int i = 1; i < size; ++i) {
        result = lcp(result, strs[i]);
        if (!result.size())
            break;
    }

    return result;
}

int main(int argc, char *argv[])
{
    vector<string> strs = {"flower","flow","flight"};
    string output = longestCommonPrefix(strs);
    std::cout << output << std::endl;

    return 0;
}