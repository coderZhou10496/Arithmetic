//
//  main.cpp
//  300-Longest Increasing Subsequence
//
//  Created by zhoujian on 2020/2/9.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 
 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 
 示例:
 
 输入: [10,9,2,5,3,7,101,18]
 输出: 4
 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 说明:
 
 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 你算法的时间复杂度应该为 O(n2) 。
 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

// 解法一：DP
/*
 dp[i]表示遍历到第i个数时，数字的最长子序列长度
 时间复杂度O(N^2)
 空间负责度O(N)
 */
int lengthOfLIS(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int size = (int)nums.size();
    int res = 0;
    vector<int> dp(size, 1);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}
// 解法一：DP + 二分

/*
 
 新建数组 array，用于保存最长上升子序列。
 对原序列进行遍历，将每位元素二分插入 array 中:
    如果 array 中元素都比它小，将它插到最后
    否则，用它覆盖掉比它大的元素中最小的那个。
 总之，思想就是让 array 中存储比较小的元素。这样，array 未必是真实的最长上升子序列，但长度是对的
 */


int lengthOfLIS_solution2(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int size = (int)nums.size();
    int res = 0;
    vector<int> array(size, 0);
    for(int i = 0; i < size; i++) {

        int left = 0;
        int right = res;
        
        while (left < right) {
            int mid = (left+right) >> 1;
            if(array[mid] < nums[i]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        array[left] = nums[i];
        if(right == res) {
            res++;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS_solution2(nums) << endl;
    return 0;
}
