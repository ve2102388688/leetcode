#include <bits/stdc++.h>
using namespace std;

/** \brief      canEatFinish 以speed的速度在H小时吃完香蕉
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 * 
 *  \param[in] piles  输入数组
 *  \param[in] speed  输入速度
 *  \param[in] h      时长
 *  \return           bool
 */
bool canEatFinish(vector<int>& piles, int speed, int h) {
    int size = piles.size();
    for (int i = 0; i < size; ++i) {
        h -= piles[i] / speed;
        h -= (piles[i] % speed == 0) ? 0 : 1;
        if (h < 0)
            return false;
    }
    return true;
}

/** \brief      minEatingSpeed 爱吃香蕉的珂珂 875
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 *  \remark     超时
 * 
 *  \param[in] piles  输入数组
 *  \param[in] h      输入时间
 *  \return           峰值下标
 */
int minEatingSpeed2(vector<int>& piles, int h) {
    /**<寻找数组的最大值 */
    int size = piles.size();
    int maxSize = 0;
    for (int i = 0; i < size; ++i)
        maxSize = (maxSize > piles[i]) ? maxSize : piles[i];

    for (int i = 1; i <= maxSize; i++) {            /**<暴力搜索 */
        if(canEatFinish(piles, i, h))
            return i;
    }
    return 0;                       /**<不可能执行到 */
}

int minEatingSpeed(vector<int>& piles, int h) {
    /**<寻找数组的最大值 */
    int size = piles.size();
    int maxSize = 0;
    for (int i = 0; i < size; ++i)
        maxSize = (maxSize > piles[i]) ? maxSize : piles[i];

    int low = 1, high = maxSize;
    while (low <= high) {                   /**<左侧二分查找 */
        int mid = low + (high-low)/2;
        if (canEatFinish(piles, mid, h))
            high = mid - 1;                 /**<往左缩 */
        else
            low = mid + 1;
    }

    return low;                       /**<出口low>high，结果中不可能找不到，所有没有出错判断 */
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {3,6,7,11};
    int output = minEatingSpeed(nums1, 8);
    cout << output << " ";

    cout << "\n";   
    return 0;
}