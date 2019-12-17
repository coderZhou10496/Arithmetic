//
//  main.cpp
//  198-HouseRobber
//
//  Created by zhoujian on 2019/12/16.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 
 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 
 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 
 示例 1:
 
 输入: [1,2,3,1]
 输出: 4
 解释: 偷窃 1 号房屋 ( = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
      偷窃到的最高金额 = 1 + 3 = 4 。
 示例 2:
 
 输入: [2,7,9,3,1]
 输出: 12
 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/house-robber
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

int rob(vector<int>& nums) {
    
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }

    /*
     1.状态转移公式
     2.初始值
     3.结果值
     */
    
    vector<vector<int>> result(length, vector<int>(2));
    result[0][1] = nums[0];
    result[0][0] = 0;
    
    
    for(int i = 1; i < length; i++) {
        result[i][1] = result[i-1][0] + nums[i];
        result[i][0] = max(result[i-1][0], result[i-1][1]);
    }
    
    return max(result[length-1][0], result[length-1][1]);
    
}

// 是对rob1方法的优化，降维处理，速度及内存都比解法1好
/*
 
 */
int rob2(vector<int>& nums) {
    int length = (int)nums.size();
    if(length == 0) {
        return 0;
    }
    if(length == 1) {
        return nums[0];
    }
    
    // result[i]，表示第i个必偷的情况下，能偷取的最大价值
    vector<int> result(length);
    result[0] = nums[0];
    result[1] = max(nums[0], nums[1]);
    
    for(int i = 2; i < length; i++) {
        result[i] = max(result[i-2]+nums[i], result[i-1]);
    }
    return result[length-1];
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2,3,5};
    cout << rob(nums) << endl;
    return 0;
}
