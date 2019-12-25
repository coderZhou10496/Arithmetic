//
//  main.cpp
//  377-CombinationSumIV
//
//  Created by zhoujian on 2019/12/24.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;


/*
 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
 
 示例:
 
 nums = [1, 2, 3]
 target = 4
 
 所有可能的组合为：
 (1, 1, 1, 1)
 (1, 1, 2)
 (1, 2, 1)
 (1, 3)
 (2, 1, 1)
 (2, 2)
 (3, 1)
 
 请注意，顺序不同的序列被视作不同的组合。
 
 因此输出为 7。
 进阶：
 如果给定的数组中含有负数会怎么样？
 问题会产生什么变化？
 我们需要在题目中添加什么限制来允许负数的出现？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/combination-sum-iv
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

// 解法1：动态规划
int combinationSum4_solution1(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 0;
    }
    
    int minNumber = INT_MAX;
    for(int num : nums) {
        minNumber = min(minNumber, num);
    }
    if(minNumber > target) {
        return 0;
    }
    
    /*
     nums = [5, 1, 8]
     target = 24
     状态转移方程为：dp[target] = dp[target-nums[0]] + dp[target-nums[1]] + dp[target-nums[2]] + ... +dp[target-nums[size-1]];
     假如结果的数组中有一个5，则剩下的有 dp[target-5] 中可能
     假如结果的数组中有一个1，则剩下的有 dp[target-1] 中可能
     假如结果的数组中有一个8，则剩下的有 dp[target-8] 中可能
     */
    vector<unsigned long long> dp(target+1);
    dp[0] = 1;
    for(int i = 1; i <= target; i++) {
        for(int num : nums) {
            if(i >= num) {
                dp[i] = dp[i] + dp[i-num];
            }
        }
    }
    return (int)dp[target];
}
int combinationSum4_solution2Helper(vector<int>& nums,vector<int>& temp,  int target) {
    int sum = 0;
    if(target < 0) {
        return 0;
    }
    if(target == 0) {
        return 1;
    }
    if(temp[target] != -1) {
        return temp[target];
       
    }
    for(int i = 0; i < nums.size(); i++) {
        sum += combinationSum4_solution2Helper(nums, temp, target-nums[i]);
        
    }
    temp[target] = sum;
    return sum;
}

// 解法2：DFS+记忆
int combinationSum4_solution2(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 0;
    }
    
    vector<int> temp(target+1,-1);
    return combinationSum4_solution2Helper(nums, temp, target);
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 1, 8};
    int res = combinationSum4_solution2(nums,24);
    cout << "结果：" << res << endl;
    
    return 0;
}
