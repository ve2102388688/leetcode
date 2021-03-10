#include <bits/stdc++.h>
using namespace std;

/** \brief      minPathSum 最小路径和 64
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 *  \remark     dp[i][j],表示从(0,0)到(i,j)的最短路径和
 * 
 *  \param[in] grid 输入网格
 *  \return         返回最小的路径和
 */
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m ,vector<int>(n, 0));

    /**<base case*/
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < n; ++j)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];    /**<有两种方案，分别是从上，左到达目标点 */
        }
    }
    return dp[m - 1][n - 1];
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int output = minPathSum(nums);
    std::cout << output << '\n';

    return 0;
}