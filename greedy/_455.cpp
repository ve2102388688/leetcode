#include <bits/stdc++.h>
using namespace std;


/** \brief      findContentChildren 分发饼干 455
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] g   输入胃口
 *  \param[in] s   输入饼重量
 *  \return        最多能满足孩子的数量
 */
int findContentChildren(vector<int>& g, vector<int>& s) {
    // 降序排列
    sort(g.begin(), g.end(), [](const int a, const int b) { return (a>b) ? true: false; });
    sort(s.begin(), s.end(), [](const int a, const int b) { return (a>b) ? true: false; });
    int m = g.size(), n = s.size();
    int i = 0, j = 0;
    int count = 0;
    while(i<m && j<n) {
        if(s[j]>=g[i]){         /**<饼重些就ok */
            ++count;
            ++i, ++j;
        }else 
            ++i;                /**<孩子胃口大于饼，下一个孩子 */
    }
    return count;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 2, 3};
    int output = findContentChildren(nums1, nums2);
    cout << output << " ";

    cout << "\n";

    return 0;
}