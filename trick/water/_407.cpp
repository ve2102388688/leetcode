#include <bits/stdc++.h>
using namespace std;

/** \brief      maxProfit 买卖股票的最佳时机 121
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-20
 *  \remark     动态规划
 * 
 *  \param[in] prices  输入数组
 *  \return            返回股票收益最大值
 */
int trapRainWater(vector<vector<int>>& heightMap) {

}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {
                {1,4,3,1,3,2},
                {3,2,1,3,2,4},
                {2,3,3,2,3,1}
                };
    int output = trapRainWater(nums);
    std::cout << output << '\n';

    return 0;
}