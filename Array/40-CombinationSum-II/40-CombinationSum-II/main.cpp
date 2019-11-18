//
//  main.cpp
//  40-CombinationSum-II
//
//  Created by zhoujian on 2019/11/18.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;


/*
 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 
 candidates 中的每个数字在每个组合中只能使用一次。
 
 说明：
 
 所有数字（包括目标数）都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 所求解集为:
 [
 [1, 7],
 [1, 2, 5],
 [2, 6],
 [1, 1, 6]
 ]
 示例 2:
 
 输入: candidates = [2,5,2,1,2], target = 5,
 所求解集为:
 [
   [1,2,2],
   [5]
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/combination-sum-ii
 
 */
void combinationSumCore2(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int currentIndex, int target) {
    
    if(target < 0) {
        return;
    }
    else if (target == 0) {
        res.push_back(temp);
    }
    else {
        for(int i = currentIndex; i < candidates.size(); i++) {
            if( i > currentIndex && candidates[i] == candidates[i-1]) {
                continue;
            }
            temp.push_back(candidates[i]);
            combinationSumCore2(res, temp, candidates, i+1, target - candidates[i]);
            temp.pop_back();
        }
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    combinationSumCore2(res, temp, candidates, 0, target);
    return res;
    
}


int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2,5,2,1,2};
    vector<int> nums2 = {10,1,2,7,6,1,5};
    
    vector<vector<int>> result = combinationSum2(nums, 5);
    
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << endl;
        }
        cout << endl;
    }
    return 0;
}
