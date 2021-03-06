//
//  main.cpp
//  416-Partition Equal Subset Sum
//
//  Created by zhoujian on 2019/12/27.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 
 注意:
 
 每个数组中的元素不会超过 100
 数组的大小不会超过 200
 示例 1:
 
 输入: [1, 5, 11, 5]
 
 输出: true
 
 解释: 数组可以分割成 [1, 5, 5] 和 [11].
  
 
 示例 2:
 
 输入: [1, 2, 3, 5]
 
 输出: false
 
 解释: 数组不能分割成两个元素和相等的子集.
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 解法1：DP
bool canPartition(vector<int>& nums) {
    int length = (int)nums.size();
    if(length == 0 || length == 1) {
        return false;
    }
    
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    if(sum%2 == 1) {
        return false;
    }
    
    int targetNum = sum/2;
    
    // dp[i] 表示nums数组能否组成和为i的状态，值为bool
    // 假如dp[i - num]为true，则表示在num之前的数组可以找出和为i - num的集合，那么再加入了num之 后，数组也能找出和为i的集合，于是dp[i]更新为true。
    

    vector<bool> dp(targetNum+1,false);
    dp[0] = 1;
    
    for(int num : nums) {
        for(int i = targetNum; i >= num; i--) {
            if(dp[i-num] == true) {
                dp[i] = true;
            }
        }
    }
    
    return dp[targetNum];
}

// 解法2：回溯+剪枝  速度比DP快很多
bool canPartition2Helper(vector<int>& nums, int target, int index) {
    if(target == 0) {
        return true;
    }
    // 剪枝操作
    if(index < 0 || target < 0 ||  nums[index] > target) {
        return false;
    }
    
    for(int i = index; i >= 0; i--) {
        
        return canPartition2Helper(nums, target-nums[i], index - 1) || canPartition2Helper(nums, target, index-1);
    }
    return false;
}

bool canPartition2(vector<int>& nums) {
    int length = (int)nums.size();
    if(length == 0 || length == 1) {
        return false;
    }
    
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    if(sum%2 == 1) {
        return false;
    }
    int targetNum = sum/2;
    sort(nums.begin(), nums.end());
    return canPartition2Helper(nums, targetNum, length-1);
}

// 解法3：转换成背包问题
/*
 题目转换成从这个数组里面选取一些元素使这些元素和为sum/2。如果我们将所有元素的值看做是物品的重量，每件物品价值都为1，所以这就是一个恰好装满的01背包问题。
 */
bool canPartition3(vector<int>& nums) {
    int length = (int)nums.size();
    if(length == 0 || length == 1) {
        return false;
    }
    
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    if(sum%2 == 1) {
        return false;
    }
    int capacity = sum/2;
    vector<int>dp(capacity + 1, INT_MIN);
    dp[0] = 1;
    for(int num : nums) {
        for(int j = capacity; j >= num; j--) {
            dp[j] = max(dp[j], 1 + dp[j-num]);
        }
    }
    return dp[capacity] > 0;
    

    /*
     
     由于此题最后求的是能不能进行划分，所以dp的每个元素定义成bool型就可以了，然后将dp[0]初始为true其他初始化为false，而转移方程就应该是用或操作而不是max操作
     
     int capacity = sum / 2;
     vector<bool>dp(capacity + 1, false);
     dp[0] = true;
     for(int i = 1; i <= n; i++)
        for(int j = capacity; j >= nums[i-1]; j--)
            dp[j] = dp[j] || dp[j - nums[i-1]];
     
     return dp[capacity];
     
     */
}
int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1, 1, 1, 1};
    bool res = canPartition2(nums);
    cout << "res:" << res << endl;

    return 0;
}
