#include <bits/stdc++.h>
using namespace std;

/** \brief      strStr  子字符串
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-9
 * 
 *  \param[in] haystack 输入原始字符串
 *  \param[in] needle   输入匹配字符串       
 *  \return             返回匹配下标，无返回0
 */
int strStr(string haystack, string needle) {
    // Method 1
    // int size1 = haystack.size();
    // int size2 = needle.size();

    // if (size2 == 0)             /**<当needle是空字符串时，返回0 */
    //     return 0;
    // if(size1 < size2)           /**<haystack较短，不存在 */
    //     return -1;

    // /**<低效的原因每次失败只能前进一步  */
    // for (int i = 0; i < size1-size2+1; ++i) {
    //     int j = i, k = 0;       /**<j只是临时代替i走 */
    //     for ( ; k < size2 && haystack[j] == needle[k]; ++j, ++k) ;

    //     if(k == size2)
    //         return i;
    // }
    // return -1;

    // Method 2
    auto p = haystack.find(needle);
	return p;
}

int main(int argc, char *argv[])
{
    int output = strStr("mississippi", "issip");
    std::cout << output << std::endl;

    return 0;
}