#include <bits/stdc++.h>
using namespace std;

/** \brief      wordBreak 两个字符串的最小ASCII删除和 712
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-12
 *  \remark     最长公共子序列，并且和值最大 
 * 
 *  \param[in] s        输入字符串
 *  \param[in] wordDict 输入数组
 *  \return             最小的删除次数
 */
int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    /**<得到的结果是最大的最长公共子序列 */
    for (int i = 1; i <=m ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i - 1][j - 1]+s1[i-1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int res = 0;
    for (const auto &e: s1)
        res += e;
    res -= dp[m][n];
    for (const auto &e: s2)
        res += e;
    res -= dp[m][n];
    
    return res;
}

int main(int argc, char *argv[])
{
    int output = minimumDeleteSum("delete", "leet");
    std::cout << output << std::endl;

    return 0;
}