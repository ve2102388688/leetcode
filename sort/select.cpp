#include <bits/stdc++.h>
using namespace std;

/** \brief      selectSort 简单选择排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     n-1趟选择，每次选择最小的数，之后交换
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void selectSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; ++i) {                 /**<n-1趟选择 */
        int min = i;                                /**<最小元素位置 */
        for (int j = i+1; j < n; ++j) {
            if (nums[j] < nums[min])
                min = j;
        }
        if (min != i)
            std::swap(nums[i], nums[min]);          /**<最小元素和i交换 */
    }
}


/** \brief      adjustDown 向下调整堆(调整区域：开始k，终止end--[k,end])
 *  \author     wzk
 *  \date       2020.03.06
 *  
 * \param[in]   nums 输入数组
 * \param[in]   k    根结点k
 * \param[in]   end  终点下标，也就是长度length-1
 * \return      void
 */
void adjustDown(vector<int>& nums, int k, int end) {
    int temp = nums[k];
    for (int i = 2*k+1; i <= end; i *= 2) {     /**<数组从0开始的，所有需要+1*/
        if(i<end && nums[i]<nums[i+1])          /**<向后比较，寻找孩子中较大值 */
            ++i;
        if (temp >= nums[i])                    /**<根结点本来就大，不需要操作 */
            break;
        else {                                  /**<最大值和根结点交换，注意，第一句、这里、最后一句就是一个交换操作，只是分成了三部分 */
            nums[k] = nums[i];
            k = i;                              /**<就能理解有这句代码，否则无法交换 */
        }
    }
    nums[k] = temp;
}


/** \brief      heapSort 堆排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     n-1趟选择，每次选择最小的数，之后交换
 *  \remark     注意从0存储!!!
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void heapSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n/2-1; i >= 0; --i)        /**<创建大顶堆--由下向上创建 */
        adjustDown(nums, i, n-1);           /**<将[i,...,n-1]调整为堆 */

    for (int i = n-1; i > 0; --i) {         /**<一共n-1趟，n-1-1+1*/
        std::swap(nums[i], nums[0]);
        adjustDown(nums, 0, i-1);           /**<[0,...,i-1]调整为堆 */
    }
}


int main(int argc, char* argv[])
{
    // vector<int> nums = {1, 5, 3, 7, 2, 4, 9, 3, 10, 8, 2};
    vector<int> nums = {53, 45, 87, 32, 17, 65, 78, 9};
    heapSort(nums);
    for (const auto& e : nums)
        cout << e << ' ';
    cout << '\n';

    return 0;
}

