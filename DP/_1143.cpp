#include <bits/stdc++.h>
using namespace std;


/** \brief      longestCommonSubsequence  最长公共子序列 1143
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-25
 *  \remark     dp[i][j]表示s1[0,...,i-1],s1[0,...,j-1]的LCS
 * 
 *  \param[in] text1 输入字符串1
 *  \param[in] text2 输入字符串2
 *  \return          返回最长公共子序列的长度
 */
int longestCommonSubsequence(string& text1, string& text2) {
    int m = text1.size();
    int n = text2.size();

    /**<base case若两个字符串有空串，则返回0，即0行和0列*/
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(text1[i-1] == text2[j-1])                    /**<若两个字符相等， 则LCS加1*/
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else                                            /**<若两个字符不相等，则比较两者形式，取最大值 */
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];                                        /**<dp数组向右下角递增 */
}

int main(int argc, char *argv[])
{
    string text1("abc");
    string text2("def");

    int output = longestCommonSubsequence(text1, text2);
    std::cout << output << '\n';

    return 0;
}