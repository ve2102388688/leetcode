#include <bits/stdc++.h>
using namespace std;


/** \brief      candy 分发糖果 135
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-22
 * 
 *  \param[in] ratings   评分
 *  \return              最少应该准备的糖果数
 */
int candy(vector<int>& ratings) {

    int n = ratings.size();
    vector<int> res(n, 1);

    /**<正着贪心，只要后面的更大，就在前面的基础上加1，否则全是1 */
    for (int i = 1; i < n; ++i)
        if (ratings[i-1] < ratings[i])              /**<一旦涉及比较，就需要少循环一次 */
            res[i] = res[i-1] + 1;

    /**<反着贪心，只要前面的更大，当前值就去最大--max(curr, currNext+1) */    
    for (int i = n-2; i>=0; --i)
        if (ratings[i]>ratings[i+1])
            res[i] = max(res[i], res[i+1]+1);

    
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += res[i];

    return result;
}

int main(int argc, char *argv[])
{
    vector<int> nums = { 1,0,2 };

    int output = candy(nums);
    std::cout << output << '\n';

    return 0;
}