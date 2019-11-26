//
//  main.cpp
//  53-MaximumSubarray
//
//  Created by zhoujian on 2019/11/26.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 
 示例:
 
 输入: [-2,1,-3,4,-1,2,1,-5,4],
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 进阶:
 
 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-subarray
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

// 解法3：动态规划(2)
int maxSubArray3(vector<int>& nums) {
    int length = (int)nums.size();
    int res = INT_MIN;
    int max_ending_here = 0;
    for(int i = 0; i < length; i++) {
        max_ending_here = max(max_ending_here + nums[i], nums[i]);
        res = max(res, max_ending_here);
    }
    return res;
}

// 解法2：动态规划(1)
int maxSubArray2(vector<int>& nums) {
    int length = (int)nums.size();
    vector<int> dp(length);
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < length; i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        res = max(dp[i], res);
    }
    return res;
}


// 解法1：贪心算法
int maxSubArray1(vector<int>& nums) {
    
    int res = INT_MIN;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        
        sum += nums[i];
        res = max(res, sum);
        
        if(sum < 0) {
            sum = 0;
        }
    }
    return res;
    
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res1 = maxSubArray1(nums);
    int res2 = maxSubArray2(nums);
    int res3 = maxSubArray3(nums);
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    return 0;
}
