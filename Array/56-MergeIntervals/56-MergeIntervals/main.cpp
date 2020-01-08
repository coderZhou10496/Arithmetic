//
//  main.cpp
//  56-MergeIntervals
//
//  Created by zhoujian on 2019/11/28.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 
 给出一个区间的集合，请合并所有重叠的区间。
 
 示例 1:
 
 输入: [[1,3],[2,6],[8,10],[15,18]]
 输出: [[1,6],[8,10],[15,18]]
 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 示例 2:
 
 输入: [[1,4],[4,5]]
 输出: [[1,5]]
 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-intervals
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/*
 自己写的，虽然ac，但内存占用过高
 */
vector<vector<int>> merge1(vector<vector<int>> & intervals) {
    
    vector<vector<int>> res;
    
    sort(intervals.begin(), intervals.end());
    
    int length = (int)intervals.size();
    if(length == 0) {
        return res;
    }
    if(length == 1) {
        vector<int> temp;
        vector<int> v = intervals[0];
        temp.push_back(v[0]);
        temp.push_back(v[v.size()-1]);
        res.push_back(temp);
        return res;
    }
    
    vector<int> v = intervals[0];
    int minValue = v[0];
    int maxValue = v[v.size()-1];
    
    for(int i = 1; i < length; i++) {
        
        vector<int> v = intervals[i];
        if(v[0] > maxValue) {
            vector<int> temp;
            temp.push_back(minValue);
            temp.push_back(maxValue);
            res.push_back(temp);
            
            minValue = v[0];
            maxValue = v[v.size()-1];
        }
        else {
            minValue = min(minValue, v[0]);
            maxValue =max(maxValue, v[v.size()-1]);
        }
        
        if(i == intervals.size()-1) {
            vector<int> temp;
            temp.push_back(minValue);
            temp.push_back(maxValue);
            res.push_back(temp);
        }
    }
    
    return res;
    
}

vector<vector<int>> merge2(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    int cur = 0;
    for (const auto &interval : intervals) {
        if (res.empty()) {
            res.push_back(interval);
        }
        if (interval[0] <= res[cur][1]) {
            // merge
            if (interval[1] > res[cur][1]) {
                res[cur][1] = interval[1];
            }
        }
        else {
            res.push_back(interval);
            ++cur;
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    
//    vector<vector<int>> nums = {
//        {1,3},
//        {2,6},
//        {8,10},
//        {15,18},
//    };
    vector<vector<int>> nums = {
        {1,4},
        {4,5}
    };
    vector<vector<int>> result = merge2(nums);
    
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
