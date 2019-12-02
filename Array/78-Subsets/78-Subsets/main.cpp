//
//  main.cpp
//  78-Subsets
//
//  Created by zhoujian on 2019/12/2.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 
 说明：解集不能包含重复的子集。
 
 示例:
 
 输入: nums = [1,2,3]
 输出:
 [
   [3],
   [1],
   [2],
   [1,2,3],
   [1,3],
   [2,3],
   [1,2],
   []
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/subsets
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

void subsetsCore(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index) {
    
    res.push_back(temp);
    
    if(index == nums.size()) {
        return;
    }
    
    for(int i = index; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        subsetsCore(res, temp, nums, i+1);
        temp.pop_back();
    }
}

// 解法1：回溯求解
vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<vector<int>> res;
    vector<int> temp;
    subsetsCore(res, temp, nums, 0);
    return res;
}

// 解法2：层级遍历
vector<vector<int>> subsets2(vector<int>& nums) {
    
    vector<vector<int> > res(1);
    
    for(int i = 0;i < nums.size(); i++){
        int cnt = (int)res.size();
        for(int j = 0;j < cnt; j++){
            vector<int> tmp=res[j];
            tmp.push_back(nums[i]);
            res.push_back(tmp);
        }
    }
    return res;
}

// 解法3：位运算
vector<vector<int>> subsets3(vector<int>& nums) {
    
    vector<vector<int>>subset_set;
    
    int subset_num= 1<<nums.size();
    for(int i = 0;i < subset_num; i++){
        vector<int>subset;
        for(int j = 0;j < nums.size(); j++){
            if(i & (1 << j)){
                subset.push_back(nums[j]);
            }
        }
        subset_set.push_back(subset);
    }
    return subset_set;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets3(nums);
    for(auto val : res) {
        for(auto sec: val) {
            cout << sec << " " ;
        }
        cout << endl;
    }
    return 0;
}
