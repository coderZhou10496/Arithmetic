//
//  main.cpp
//  90-SubsetsII
//
//  Created by zhoujian on 2019/12/2.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 
 说明：解集不能包含重复的子集。
 
 示例:
 
 输入: [1,2,2]
 输出:
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/subsets-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

void subsetsWithDupCore(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int index) {
    res.push_back(temp);
    if(index == nums.size()) {
        return;
    }
    for(int i = index; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) {
            continue;
        }
        temp.push_back(nums[i]);
        subsetsWithDupCore(res, temp, nums, i+1);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int length = (int)nums.size();
    vector<vector<int>> res;
    if(length == 0) {
        return res;
    }
    sort(nums.begin(), nums.end());
    vector<int> temp;
    subsetsWithDupCore(res, temp, nums, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for(auto val : res) {
        for(auto sec : val) {
            cout << sec << " ";
        }
        cout << endl;
    }
    return 0;
}
