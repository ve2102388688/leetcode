#include <bits/stdc++.h>
using namespace std;

void count0_1(const string& str, int *res) {
    for (const auto& e : str)
        ++res[e - '0'];
}
void count0_1(const string& str, array<int, 2>& res) {
    for (const auto& e : str)
        ++res[e - '0'];
}
void count0_1(const string& str, vector<int>& res) {
    res.push_back(0);
    res.push_back(0);
    for (const auto &e : str)
        ++res[e - '0'];
}

/** \brief      findMaxForm 一和零 474
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 * 
 *  \param[in] str 输入数组
 *  \param[in] m   输入0的个数
 *  \param[in] n   输入1的个数
 *  \return        最大子集数目
*/
int findMaxForm(vector<string>& strs, int m, int n) {
    /**<base case：dp[0][0]=0 */
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (const auto& e : strs) {
        // array<int, 2> weight{};
        vector<int> weight;
        count0_1(e, weight); /**<计算字符的0和1个数 */
        for (int i = m; i >= weight[0]; --i) {
            for (int j = n; j >= weight[1]; --j) {
                dp[i][j] = max(1 + dp[i - weight[0]][j - weight[1]], dp[i][j]);
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char *argv[])
{
    vector<string> nums = {"10", "0", "1"};
    int output = findMaxForm(nums, 1, 1);
    std::cout << output << std::endl;

    return 0;
}

