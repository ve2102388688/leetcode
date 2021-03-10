#include <bits/stdc++.h>
using namespace std;

/** \brief      wordBreak 两个字符串的删除操作 583
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-12
 *  \remark     最长公共子序列
 * 
 *  \param[in] s        输入字符串
 *  \param[in] wordDict 输入数组
 *  \return             最小的删除次数
 */
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    /**<base case: 空串的时候为0，即0行0列为0 */
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return m + n - 2*dp[m][n];
}


int main(int argc, char *argv[])
{
    int output = minDistance("sea", "");
    std::cout << output << std::endl;

    return 0;
}