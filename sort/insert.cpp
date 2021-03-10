#include <bits/stdc++.h>
using namespace std;

/** \brief      insertSort 简单插入排序
 *  \author     wzk
 *  \date       2020.03.06
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void insertSort(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1)
        return;
    
    for (size_t i = 1; i < n; ++i) {                /**<有序无序区间？ 认定是第一个元素是有序区间*/
        if (nums[i-1]>nums[i]) {                    /**<什么时候启动查找目标位置j？ 此刻元素小一些 */
            int temp = nums[i];                     /**<哨兵 */
            int j = i - 1;  
            for (; nums[j] > temp; --j)             /**<什么时候停止查找？ 第一个小于目标值temp */
                nums[j+1] = nums[j];
            nums[j + 1] = temp;                     /**<注意是j+1，很简单，什么时候停止查找？小于目标值 */
        }
    }
}

/** \brief      insertSort2 折半插入排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     只是在比较的时候，启动折半查找确定位置k，之后通过移动的方式完成
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void insertSort2(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return;

    for (int i = 1; i < n; ++i) {
        if(nums[i-1] > nums[i]) {                    /**<什么时候启动查找目标位置j？ 此刻元素小一些 */
            int temp = nums[i];
            /**<折半查找,左闭右闭 */
            int low = 1, high = i-1;
            while (low <= high) {
                int mid = (low+high)/2;
                if(nums[mid] > temp)
                    high = mid -1;
                else
                    low = mid + 1;
            }
            
            /**<移动元素 */
            for (int j = i-1; j>=low; --j)  /**<循环出口low>high,所有low就是插入点、循环到这停止 */
                nums[j + 1] = nums[j];
            nums[low] = temp;
        }
    }
}

/** \brief      insertSort3 shell排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     仅仅是多了一个外部步长dk,内部启动的简单插入排序
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void insertSort3(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return;

    /**<希尔排序步长，dk初始值是长度的一班，之后每次缩小成一半，直到1 */
    for (int dk = n/2; dk>=1; dk/=2) {
        /**<内部启用简单的插入排序 */
        for (int i = dk+1; i<n; ++i) {      /**<简单排序什么时候开始的？ 第一个元素有序 */
            if (nums[i-dk]>nums[i]) {       /**<前一个元素大，启用查找位置k */
                int temp = nums[i];
                int j = i-dk;
                for (; j >= 0 && nums[j] > temp; j -= dk)             /**<什么时候停止查找？ 第一个小于目标值temp */
                    nums[j + dk] = nums[j];
                nums[j + dk] = temp;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    vector<int> nums = {1, 5, 3, 7, 2, 4, 9, 3, 10, 8, 2};
    insertSort(nums);
    for (const auto& e : nums)
        cout << e << ' ';
    cout << '\n';

    return 0;
}