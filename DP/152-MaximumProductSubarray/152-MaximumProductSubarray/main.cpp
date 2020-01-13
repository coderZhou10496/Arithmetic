//
//  main.cpp
//  152-MaximumProductSubarray
//
//  Created by zhoujian on 2020/1/13.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 
 示例 1:
 
 输入: [2,3,-2,4]
 输出: 6
 解释: 子数组 [2,3] 有最大乘积 6。
 示例 2:
 
 输入: [-2,0,-1]
 输出: 0
 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-product-subarray
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */


/*
 自己经过多次尝试 ，终于AC,不过判断太过复杂
 执行用时 : 4 ms, 在所有 C++ 提交中击败了91.35%的用户
 内存消耗 :9.4 MB, 在所有 C++ 提交中击败了5.14%的用户
 */
int maxProduct(vector<int>& nums) {
    
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    if(length == 1) {
        return nums[0];
    }
   
    vector<int> dp(length);
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < length; i++) {
        if(nums[i] == 0) {
            dp[i] = 0;
            res = max(res,0);
            continue;
        }
        else if (nums[i] > 0) {
            dp[i] = max(dp[i-1]*nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        else {
            
            // 下面是为了找到上一个负数的位置
            int index = i-1;
            while (index >= 0 && nums[index] > 0) {
                index--;
            }
            int chengji = 1;
            if(index >= 0) {
                
                for(int j = index; j <= i; j++) {
                    chengji = chengji*nums[j];
                }
            }
            if(index > 0) {
                // 上一个负数的位置在索引0的前面
                dp[i] = max(dp[index-1] * chengji,chengji);
            }
            else if(index == 0){
                // 上一个负数的位置在索引0
                dp[i] = chengji;
            }
            else {
                dp[i] = max(dp[i-1]* nums[i], nums[i]);
            }
            res = max(res, dp[i]);

        }
        
    }
    return res;
}

// 别人的解法2，DP
int maxProduct_solution2(vector<int>& nums) {
    
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    if(length == 1) {
        return nums[0];
    }
    
    int min_current = 0;
    int max_current = 0;
    int res = nums[0];
    for(int i = 1; i < length; i++) {
        if(nums[i] == 0) {
            min_current = max_current = 0;
        }
        else if (nums[i] > 0) {
            max_current = max(max_current*nums[i], nums[i]);
            min_current = min_current * nums[i];
        }
        else {
            int t = max_current;
            max_current = min_current*nums[i];
            min_current = min(t*nums[i], nums[i]);
        }
        
        res = max(res, max_current);
    }
    return res;
}

// 别人的解法3，双向遍历
int maxProduct_solution3(vector<int>& nums) {
    
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    int max_current = 1;
    int res = nums[0];
    for (int i = 0; i < length; i++) {
        max_current *= nums[i];
        res = max(res, max_current);
        if (max_current == 0) {
            max_current = 1;
        }
    }
    max_current = 1;
    for (int i = length - 1; i >= 0; i--) {
        max_current *= nums[i];
        res = max(res, max_current);
        if (max_current == 0) {
            max_current = 1;
        }
    }
    
    return res;
}
int main(int argc, const char * argv[]) {
//    vector<int> nums = {2,3,-2,4};
//    vector<int> nums = {-2,0,-1};
    
//    vector<int> nums = {1,2,-2,-2,4,0,5};
//    vector<int> nums = {-2,3,-4,1,-2,-2};
    
    vector<int> nums = {-1,2,3,-4,0};
//    vector<int> nums = {2,-1,1,1};
    cout << maxProduct(nums) << endl;
    
    return 0;
}
