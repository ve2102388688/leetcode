#include <bits/stdc++.h>
using namespace std;

/** \brief      BubbleSort 冒泡排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     n-1趟冒泡，每趟冒泡逆序就交换
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void BubbleSort(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n-1; ++i) {                 /**<n-1趟冒泡 */
        int flag = false;
        for (int j = n-1; j > i; --j) {             /**<每趟冒泡 */
            if (nums[j-1] > nums[j]) {              /**<逆序就交换 */
                std::swap(nums[j-1], nums[j]);
                flag = true;
            }
        }
        if (flag == false)                          /**<若没有发生交换 */
            return;
    }
}


/** \brief      doubleBubbleSort 双向冒泡排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     奇数趟（从前往后），逆序交换，一趟下来最大值已知
 *  \remark     偶数趟（从后往前），逆序交换，一趟下来最小值已知
 *  
 * \param[in]   nums 输入数组
 * \return      void
 */
void doubleBubbleSort(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    bool flag = true;                           /**<默认为真，不然循环都不会进入 */
    while (low < high && flag) {
        flag = false;
        for (int i = low; i < high; ++i) {      /**<奇数趟（从前往后）,目标找到最大值 */
            if (nums[i]>nums[i+1]) {            /**<何为逆序？ 那就是前面的元素大于后面的， 显然i是前面，i+1是后面，为什么是i+1？从前往后不该是和i+1比较吗？ */
                std::swap(nums[i], nums[i+1]);
                flag = true;
            }
        }
        --high;                                 /**<每趟循环都确定了一个值，这里是最大值 */
        for (int i = high; i > low; --i) {      /**<偶数趟（从后往前）,目标找到最小值 */
            if(nums[i-1]>nums[i]) {             /**<何为逆序？ 那就是前面的元素大于后面的， 显然i是前面，i+1是后面，为什么是i+1？从前往后不该是和i+1比较吗？ */
                std::swap(nums[i-1], nums[i]);
                flag = true;
            }
        }
        ++low;                                 /**<每趟循环都确定了一个值，这里是最小值 */
    }    
}



/** \brief      partition 划分
 *  \author     wzk
 *  \date       2020.03.06
 *  
 * \param[in]   nums 输入数组
 * \param[in]   low  输入上界
 * \param[in]   high 输入下界
 * \return      void
 */
int partition(vector<int>& nums, int low, int high) {
    int privot = nums[low];
    while (low < high) {
        while (low < high && nums[high]>=privot) --high;        /**<右边大于枢轴，--high */
        nums[low] = nums[high];                                 /**<在右边找到一个左边的数，拷贝到左边 */
        while (low < high && nums[low]<=privot) ++low;          /**<左边小于枢轴，++low */
        nums[high] = nums[low];                                 /**<在左边找到一个右边的数，拷贝到右边 */
    }
    nums[low] = privot;                                         /**<循环出口high>low */
    return low;
}

/** \brief      quickSort 快速排序
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     分治
 *  
 * \param[in]   nums 输入数组
 * \param[in]   low  输入上界
 * \param[in]   high 输入下界
 * \return      void
 */
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {                               /**<注意这里是if，而不是while,在递归中不需要while,因为没有改变low、high，这两个值是外界传进来的 */
        int mid = partition(nums, low, high);
        quickSort(nums, low, mid - 1);
        quickSort(nums, mid + 1, high);
    }
}


/** \brief      kth_elem 寻找k小的数据
 *  \author     wzk
 *  \date       2020.03.06
 *  \remark     分治
 *  
 * \param[in]   nums 输入数组
 * \param[in]   low  输入上界
 * \param[in]   high 输入下界
 * \return      void
 */
int helper(vector<int>& nums, int low, int high, int k) {
    int pivot = nums[low];
    int low_temp = low, high_temp = high;                   /**<low,high在划分的时候会被修改，提前记住 */
    while (low < high) {
        while (low < high && nums[high] >= pivot) --high;   /**<带上等号，重复也ok */
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) ++low;
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    if(low - low_temp + 1 == k)                             /**<[low_temp,...,low,...high]这是划分后的情形，也就是前进了多少？low - low_temp + 1 */
        return nums[low];
    else if (low - low_temp + 1 > k)
        return helper(nums, low_temp, low - 1, k);
    else
        return helper(nums, low+1, high_temp, k-(low - low_temp + 1));  /**<还差几步就到k了 */
}

int kth_elem(vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size())              /**<非法输入,返回最小值 */
        return INT_MIN;
    helper(nums, 0, nums.size() - 1, k);
}


int main(int argc, char* argv[])
{
    vector<int> nums = {1, 5, 3, 7, 2, 4, 9, 3, 10, 8, 2};
    // doubleBubbleSort(nums);
    // // quickSort(nums, 0, nums.size()-1);      /**<数组的有效下标 */
    // for (const auto& e : nums)
    //     cout << e << ' ';
    // cout << '\n';

    int output = kth_elem(nums, 8);
    cout << output << '\n';
    return 0;
}

