//
//  main.cpp
//  216-CombinationSumIII
//
//  Created by zhoujian on 2019/12/23.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 
 说明：
 
 所有数字都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: k = 3, n = 7
 输出: [[1,2,4]]
 示例 2:
 
 输入: k = 3, n = 9
 输出: [[1,2,6], [1,3,5], [2,3,4]]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/combination-sum-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

void combinationSum3Helper(vector<vector<int>>& res, vector<int>& temp, int currentK, int n, int index) {
    if(currentK < 0 || n < 0) {
        return;
    }
    if(n == 0) {
        if(currentK == 0) {
            res.push_back(temp);
        }
        return;
    }
    for(int i = index; i <= 9; i++) {
        temp.push_back(i);
        combinationSum3Helper(res, temp, currentK-1, n-i, i+1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    
    vector<vector<int>> res;
    if(k == 0 || n == 0) {
        return res;
    }
    vector<int> temp;
    combinationSum3Helper(res, temp, k, n, 1);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> res = combinationSum3(3, 15);
    for(auto arr : res) {
        for(auto sec : arr) {
            cout << sec << " ";
        }
        cout << endl;
    }
    return 0;
}
