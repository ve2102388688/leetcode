#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      lengthOfLIS 最长递增子序列 200
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 *  \remark     技巧性很强
 * 
 *  \param[in] root 输入数组
 *  \return         返回最长递增子序列
 */
int lengthOfLIS(vector<vector<int>>& envelopes) {
    int size = envelopes.size();

    vector<int> top;
    int piles = 0;                                  /**<牌堆数量 */
    for (int i = 0; i < size; ++i) {
        int proke = envelopes[i][1];                /**<总是取第二列的值 */

        /**<左侧二分搜索 */
        int left = 0;
        int right = piles;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if(top[mid] == proke)
                right = mid;
            else if(top[mid] > proke)
                right = mid;
            else
                left = mid + 1;
        }
        if(left == piles){                          /**<没有牌堆可以容纳，新建牌堆 */
            ++piles;
            top.push_back(proke);                   /**<将新数据压入容器 */
        }else{
            top[left] = proke;                      /**<每一个牌堆top值逐渐减小，覆盖 */
        }   
    }
    return piles;
}

/** \brief      maxEnvelopes  俄罗斯套娃信封问题 354
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-22
 * 
 *  \param[in] envelopes 输入二维数组
 *  \return              返回最长递增子序列
 */
int maxEnvelopes(vector<vector<int>>& envelopes) {
    if(envelopes.size() == 0)
        return 0;

    /**<二维数组第一列升序，第一列相同第二列降序 */
    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)->bool { return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0]; });

    /**<一维最长递增子序列 */
    return lengthOfLIS(envelopes);
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{5,4},{6,4},{6,7},{2,3}};

    int output = maxEnvelopes(nums);
    std::cout << output << '\n';

    return 0;
}