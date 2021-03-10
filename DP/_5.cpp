#include <bits/stdc++.h>
using namespace std;

/** \brief      longestPalindrome  最长回文子串
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 *  \remark     二维动态规划
 * 
 *  \param[in] s 输入字符串
 *  \return      返回最长回文子串
 */
string longestPalindrome(string s) {
    int size = s.size();
    if(size == 0) return "";
    if(size == 1) return s;

    int longest = 1;            /**<最长路径 */
    int start = 0;              /**<起始位置 */
    vector<vector<bool>> dp(size, vector<bool>(size, false));   /**<二位动态规划 */

    /**<边界条件--base case：这里有两个, 长度为1的都是回文, 长度为2的都是回文 */
    for (int i = 0; i < size; i++){
        dp[i][i] = 1;                   /**<长度为1的都是回文 */

        /**<为什么长度为2的也是边界条件？ 主要考虑dp[i+1][j-1]不能取主对角线下的元素，如cbbd */
        if(i < size -1){                /**<单独考虑长度为2的情况 */
            if(s[i] == s[i+1]){
                dp[i][i + 1] = true;
                start = i;
                longest = 2;
            }
        }
    }

    /**<l 表示字符串的长度; i表示起点; j表示终点 */
    /**<len=1放在这里会导致下标下溢，所有DP问题首先解决边界条件 */
    /**<len=2放在这里会导致获取无效元素dp[i+1][j-1]，所有DP问题首先解决边界条件 */
    for (int len = 3; len <= size; ++len) {
        for (int i = 0; i+len <= size; ++i) {
            int j = i + len - 1;                        
            if(s[i] == s[j] && dp[i + 1][j - 1]){       /**<当前字符串是否为回文？两边相等+看看上次的结果 */
                dp[i][j] = true;
                start = i;
                longest = len;
            }
        }
    }

    return s.substr(start, longest);                    /**<最长回文子串 */
}


// int longestPalindrome2(string& s) {
//     int size = s.size();

//     vector<vector<int>> dp(size, vector<int>(size, 0));
//     /**<base case, 一个字母就是回文 */
//     for (int i = 0; i < size; ++i)
//         dp[i][i] = 1;

//     for(int i = size-2; i >= 0; --i) {
//         for(int j = i+1; j < size; ++j) {                      /**<从下至上，从左至右的有上三角 */
//             /**<状态转移方程 */
//             if (s[i] == s[j])                                   /**<若相等，则最长回文子序列增加2 */
//                 dp[i][j] = dp[i + 1][j - 1];
//             else                                                /**<若不相等，分别将左边的i和右边的j加入，取得最大值 */
//                 dp[i][j] = 0;
//         }
//     }
//     return dp[0][]
//     // return s.substr(start, longest);                    /**<最长回文子串 */
// }


int main(int argc, char *argv[])
{
    string output = longestPalindrome("({({(({()}})}{())})})[){{{([)()((()]]}])[{)]}{[}{)");
    std::cout << output << std::endl;

    return 0;
}