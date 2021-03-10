#include <bits/stdc++.h>
using namespace std;


/** \brief      minDistance 编辑距离 72
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-25
 *  \remark     dp[i][j]表示s1[0,...,i-1],s1[0,...,j-1]的编辑距离
 * 
 *  \param[in] text1 输入字符串1
 *  \param[in] text2 输入字符串2
 *  \return          返回将word1转换成word2所使用的最少操作数
 */
int minDistance(string& word1, string& word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    /**<base case */
    for (int i = 1; i <= m; ++i) {              /**<0列依次递增 */
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {              /**<0行依次递增 */
        dp[0][j] = j;
    }

    /**<动态规划 */
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(word1[i-1] == word2[j-1])        /**<若两者相等，直接跳过，不改变编辑距离 */
                dp[i][j] = dp[i-1][j-1];
            else                                /**<删除、插入、替换的最小值 */
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
        }
    }
    return dp[m][n];                            /**<动态规划的最大值是最大角 */
}

int main(int argc, char *argv[])
{
    string text1("intention");
    string text2("execution");

    int output = minDistance(text1, text2);
    std::cout << output << '\n';

    return 0;
}