#include <bits/stdc++.h>
using namespace std;


/** \brief      longestPalindromeSubseq  516. 最长回文子序列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-26
 *  \remark     dp[i][j]表示s[i,...,j]的LPSS
 * 
 *  \param[in] text1 输入字符串1
 *  \return          返回最长回文子序列
 */
int longestPalindromeSubseq(string& s) {
    int size = s.size();

    vector<vector<int>> dp(size, vector<int>(size, 0));
    /**<base case, 一个字母就是回文 */
    for (int i = 0; i < size; ++i)
        dp[i][i] = 1;

    // /**<Method1 */
    // for(int len = 2; len <= size; ++len) {                      /**<对角线方式遍历 */
    //     for(int i = 0; i+len <= size; ++i) {
    //         int j = i + len - 1;
    //         if (s[i] == s[j])                                   /**<若相等，则最长回文子序列增加2 */
    //             dp[i][j] = dp[i + 1][j - 1] + 2;
    //         else                                                /**<若不相等，分别将左边的i和右边的j加入，取得最大值 */
    //             dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
    //     }
    // }
    /**<Method2 */
    for(int i = size-2; i >= 0; --i) {
        for(int j = i+1; j < size; ++j) {                      /**<从下至上，从左至右的有上三角 */
            /**<状态转移方程 */
            if (s[i] == s[j])                                   /**<若相等，则最长回文子序列增加2 */
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else                                                /**<若不相等，分别将左边的i和右边的j加入，取得最大值 */
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    // for(const auto& e: dp) {
    //     for(const auto& i: e)
    //         std::cout << i << " ";
    //     std::cout << std::endl;
    // }

    return dp[0][size - 1];                                     /**<返回右上角 */
}


/** \brief      longestPalindromeSubseq  516. 最长回文子序列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-26
 *  \remark     dp[i][j]表示s[i,...,j]的LPSS
 *  \remark     状态压缩
 * 
 *  \param[in] text1 输入字符串1
 *  \return          返回最长回文子序列
 */
int longestPalindromeSubseq2(string& s) {
    int size = s.size();
    /**<base case, 一个字母就是回文 */
    vector<int> dp(size, 1);

    for(int i = size-2; i >= 0; --i) {
        int pre = 0;
        for (int j = i + 1; j < size; ++j) {                    /**<从下至上，从左至右的有上三角 */
            int temp = dp[j];
            if (s[i] == s[j]) /**<若相等，则最长回文子序列增加2 */
                dp[j] = pre + 2;
            else                                                /**<若不相等，分别将左边的i和右边的j加入，取得最大值 */
                dp[j] = max(dp[j - 1], dp[j]);
            pre = temp;
        }
    }
    return dp[size - 1];                                     /**<返回右上角 */
}

int main(int argc, char *argv[])
{
    string text1("bbbab");

    int output = longestPalindromeSubseq2(text1);
    std::cout << output << '\n';

    return 0;
}