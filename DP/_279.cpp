#include <bits/stdc++.h>
using namespace std;

/** \brief      coinChange 完全平方数 279
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 *  \remark     dp[i]，凑出总金额为i需要的最少硬币数量
 * 
 *  \param[in] n  输入目标n
 *  \return       凑出总金额为n需要的最少完全平方数
 */
int numSquares(int n) {
    int m = sqrt(n);
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(j >= i*i)
                dp[i][j] = min(dp[i-1][j], dp[i][j-i*i]+1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][n];
}

int numSquares2(int n) {
    vector<int> dp(n+1, INT_MAX);       /**<求最小值，数组初始值最大*/
    dp[0] = 0;

    int m = sqrt(n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(j >= i*i)
                dp[j] = min(dp[j], dp[j-i*i]+1);
        }
    }
    return dp[n];
}

int main(int argc, char *argv[])
{
    int output = numSquares(12);
    std::cout << output << std::endl;

    return 0;
}