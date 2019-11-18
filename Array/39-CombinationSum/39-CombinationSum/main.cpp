//
//  main.cpp
//  39-CombinationSum
//
//  Created by zhoujian on 2019/11/18.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 
 链接：https://leetcode-cn.com/problems/combination-sum
 
 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 
 candidates 中的数字可以无限制重复被选取。
 
 说明：
 
 所有数字（包括 target）都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: candidates = [2,3,6,7], target = 7,
 所求解集为:
 [
 [7],
 [2,2,3]
 ]
 
 示例 2:
 输入: candidates = [2,3,5], target = 8,
 所求解集为:
 [
   [2,2,2,2],
   [2,3,3],
   [3,5]
 ]
 */

void combinationSumCore(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int currentIndex, int target) {
    
    if(target < 0 || currentIndex >= candidates.size()) {
        return;
    }
    else if (target == 0) {
        res.push_back(temp);
    }
    else {
        for(int i = currentIndex; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            combinationSumCore(res, temp, candidates, i, target - candidates[i]);
            temp.pop_back();
        }
    }
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> res;
    vector<int> temp;
    combinationSumCore(res, temp, candidates, 0, target);
    return res;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2,3,6,7};
    vector<int> nums2 = {2,3,6,7};
    
    vector<vector<int>> result = combinationSum(nums2, 8);
    
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << endl;
        }
        cout << endl;
    }
    return 0;
}
