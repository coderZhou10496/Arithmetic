//
//  main.cpp
//  494-TargetSum
//
//  Created by zhoujian on 2019/12/30.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "map"
using namespace std;

/*
 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
 
 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 
 示例 1:
 
 输入: nums: [1, 1, 1, 1, 1], S: 3
 输出: 5
 解释:
 
 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3
 
 一共有5种方法让最终目标和为3。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/target-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 解法一：简单易于理解的DP，但勉强能AC
int findTargetSumWays(vector<int>& nums, int S) {
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    /*
     dp[i][j] 表示数组中到索引为i时，组成和为j的方法数量，值为int
     转移方程：dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]];
     S的范围为 -sum(nums) ~ sum(nums)
     */
    
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    
    vector<map<int, int>> dp(length); // 注意，这里是：数组里放map
    if(nums[0] == 0) {
        dp[0][nums[0]] = 2;
    }
    else {
        dp[0][nums[0]] = 1;
        dp[0][-nums[0]] = 1;
    }
    
    for(int i = 1; i < length; i++) {
        for(int j = -sum; j <= sum; j++) {
            dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]];
        }
    }
    return dp[length-1][S];
    
}

/*
 解法2：如何将这个问题转换成01背包问题，是关键的部分
 
P N皆为nums的子集，P取整数的部分，N取负数的部分
sum(P) - sum(N) = S
sum(P) + sum(N) = sum(nums)
则有：2 * sum(P) = S + sum(nums),即 sum(P) = (S + sum(nums))/2
所以，这个问题转换成了，找到子集的数量，使子集的和等于(S + sum(nums))/2
 */
int findTargetSumWays2(vector<int>& nums, int S) {
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    if(S > sum || (S+sum)%2 == 1) {
        return 0; //数组中的总和比S还小；(S+sum)不能被2整除，说明一个子集也没有
    }
    int target = (S + sum)/2;
    vector<int> dp(target + 1);
    dp[0] = 1;
    
    for(int num : nums) {
        for(int i = target; i >= num; i--) {
            dp[i] += dp[i-num];
        }
    }
    
    return dp[target];
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 1, 1, 1, 1};
    int res = findTargetSumWays2(nums, 3);
    cout << res << endl;
    return 0;
}
